/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:26:54 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/18 22:09:30 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[]) {
	if (argc == 2) {
		try {
			RPN expression(argv[1]);
			std::cout << expression;
		} catch (RPN::InvalidExpressionException &error) {
			std::cout << "Error:" << error.what();
		}
	}
	std::cout << std::endl;
	return (0);
}