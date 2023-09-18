/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:31:09 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/18 14:58:03 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>
# include <fstream>

class BitcoinExchange {
    private:
		std::map<std::string, double>			*_rates;
		static std::map<std::string, double>	*parseCSV(std::ifstream &);
    public:
        BitcoinExchange				(void);
		BitcoinExchange				(std::string);
		BitcoinExchange				(std::ifstream &);
        BitcoinExchange				(const BitcoinExchange &);
        ~BitcoinExchange			(void);
        BitcoinExchange &operator=	(const BitcoinExchange &);
		double						lookup(std::string);
		bool						verifyDate(std::string);
};

#endif