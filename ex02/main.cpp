/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:22:30 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/19 10:30:05 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe	*process_input(int argc, char *argv[]) {
	
}

int	main(int argc, char *argv[]) {
	PmergeMe *Pmerge;
	if (argc > 1) {
		Pmerge = process_input(argc, argv);
		std::cout << "Before: " << Pmerge << std::endl;
		Pmerge->sort();
		std::cout << "After: " << Pmerge << std::endl;
		
	} else
		std::cout << std::endl;
	return (0);
}