/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:22:30 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/25 12:34:48 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe	*process_input(int argc, char *argv[]) {
	//using C++98, parse the arguments into integers and add them to the PmergeMe object and return it
	PmergeMe *Pmerge = new PmergeMe();
	std::istringstream stream;
	int holder = 0;
	for (int i = 1; i < argc; i++) {
		stream.str(argv[i]);
		if (!(stream >> holder)) {
			delete Pmerge;
			return (NULL);
		}
		Pmerge->addNumber(holder);
		stream.clear();
	}
	return (Pmerge);
}

int	main(int argc, char *argv[]) {
	PmergeMe *Pmerge = 0;
	if (argc > 1) {
		Pmerge = process_input(argc, argv);
		if (!Pmerge) {
			std::cout << "Error" << std::endl;
			return (0);
		}
		std::cout << "Before: " << *Pmerge << std::endl;
		std::clock_t startVec = std::clock();
		Pmerge->sortVec();
		std::clock_t endVec = std::clock();
		std::cout << "After: " << *Pmerge << std::endl;
		std::clock_t startDeq = std::clock();
		Pmerge->sortDeq();
		std::clock_t endDeq = std::clock();
		std::cout << "Time to process a range of " << Pmerge->getVector()->size() << " elements with std::vector : " << (endVec - startVec) << " clock cycles" << std::endl;
		std::cout << "Time to process a range of " << Pmerge->getDeque()->size() << " elements with std::deque : " << (endDeq - startDeq) << " clock cycles" << std::endl;
	} else
		std::cout << std::endl;
	if (Pmerge)
		delete Pmerge;
	return (0);
}