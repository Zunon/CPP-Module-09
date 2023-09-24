/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:22:30 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/24 16:46:59 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe	*process_input(int argc, char *argv[]) {
	//using C++98, parse the arguments into integers and add them to the PmergeMe object and return it
	PmergeMe *Pmerge = new PmergeMe();
	std::istringstream stream;
	int holder;
	for (int i = 1; i < argc; i++) {
		stream.str(argv[i]);
		if (!stream >> holder)
			return (NULL);
		Pmerge->addNumber(holder);
		stream.clear();
	}
	return (Pmerge);
}

int	main(int argc, char *argv[]) {
	PmergeMe *Pmerge;
	if (argc > 1) {
		Pmerge = process_input(argc, argv);
		if (!Pmerge) {
			std::cout << "Error" << std::endl;
			return (0);
		}
		std::cout << "Before: " << Pmerge << std::endl;
		Pmerge->sort();
		std::cout << "After: " << Pmerge << std::endl;
		
	} else
		std::cout << std::endl;
	return (0);
}