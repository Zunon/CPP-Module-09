/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:31:06 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/18 15:38:18 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void): _rates(new std::map<std::string, double>) {}

BitcoinExchange::BitcoinExchange(std::string filename) {
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("File not found");
	_rates = parseCSV(file);
}

BitcoinExchange::BitcoinExchange(std::ifstream &file) {
	if (!file.is_open())
		throw std::runtime_error("File not found");
	_rates = parseCSV(file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	_rates = new std::map<std::string, double>(*other._rates);
}

BitcoinExchange::~BitcoinExchange(void) {
	delete _rates;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other)
		_rates = new std::map<std::string, double>(*other._rates);
	return (*this);
}

/**
 * @brief Consume CSV file and return a map of dates and rates
 * @note  We're assuming all inputs in the database are valid
*/
std::map<std::string, double>	*BitcoinExchange::parseCSV(std::ifstream &file) {
	std::map<std::string, double> *rates = new std::map<std::string, double>;
	std::string line;
	std::string date;
	double rate;
	
	std::getline(file, line);
	while (std::getline(file, line)) {
		date = line.substr(0, line.find(','));
		rate = std::stod(line.substr(line.find(',') + 1));
		rates->insert({date, rate});
	}
	return (rates);
}

double	BitcoinExchange::lookup(std::string date) const {
	if (!verifyDate(date))
		throw std::runtime_error("Invalid date");
	if (_rates->find(date) == _rates->end()) {
		std::map<std::string, double>::iterator it = _rates->lower_bound(date);
		if (it == _rates->begin())
			throw std::runtime_error("No data available");
		it--;
		return (it->second);
	}
	return (_rates->at(date));
}

void	BitcoinExchange::addData(std::string date, double rate) {
	if (!verifyDate(date))
		throw std::runtime_error("Invalid date");
	_rates->insert({date, rate});
}

bool BitcoinExchange::verifyDate(std::string date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    std::istringstream ss(date);
    int year, month, day;
    char dash1, dash2;
    if (!(ss >> year >> dash1 >> month >> dash2 >> day))
        return false;
    if (dash1 != '-' || dash2 != '-')
        return false;
    if (ss.rdbuf()->in_avail() != 0)
        return false;
    if (year < 0 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2) {
        if (day > 29)
            return false;
        if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
            return false;
    }
    return true;
}