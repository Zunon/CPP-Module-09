/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:30:44 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/18 17:23:38 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool verify_line(std::string line, std::string& date, double& amount) {
    std::string::size_type pos = line.find('|');
    if (pos == std::string::npos)
        return false;
    date = line.substr(0, pos);
    std::string::size_type first = date.find_first_not_of(" \t");
    std::string::size_type last = date.find_last_not_of(" \t");
    if (first == std::string::npos || last == std::string::npos)
        return false;
    date = date.substr(first, last - first + 1);
    std::istringstream stringstream(line.substr(pos + 1));
    if (!(stringstream >> amount))
        return false;
    return true;
}

void	process_input(std::ifstream &input, const BitcoinExchange &exchange) {
	std::string line;
	std::string date;
	double amount;
	double rate;
	
	std::getline(input, line);
	while (std::getline(input, line)) {
		if (!verify_line(line, date, amount)) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (amount <= 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (amount >= 1000)
			std::cout << "Error: too large a number." << std::endl;
		else {
			try {
				rate = exchange.lookup(date);
				std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
			} catch (std::runtime_error &error) {
				std::cout << "Error: " << error.what() << std::endl;
			}
		}
	}
}

int	main(int argc, char *argv[]) {
    if (argc == 2) {
		std::ifstream file(argv[1]);
		std::ifstream data(DATABASE);
		if (!file.is_open()) {
			std::cout << "Input File not found" << std::endl;
			return (1);
		}
		if (!data.is_open()) {
			std::cout << "Database not found" << std::endl;
			return (1);
		}
		BitcoinExchange exchange(data);
		process_input(file, exchange);
	}
	std::cout << std::endl;
    return (0);
}