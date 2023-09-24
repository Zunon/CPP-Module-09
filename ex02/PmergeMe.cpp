/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:23:17 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/24 17:10:43 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void): _numbers(new std::vector<int>) {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	if (this != &other) {
		delete _numbers;
		_numbers = new std::vector<int>;
		*_numbers = *other._numbers;
	}
}

PmergeMe::~PmergeMe(void) {
	delete _numbers;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		delete _numbers;
		_numbers = new std::vector<int>;
		*_numbers = *other._numbers;
	}
	return (*this);
}

void	PmergeMe::addNumber(int n) {
	_numbers->push_back(n);
}

void	PmergeMe::sort(void) {
	sort(*_numbers);
}

// Ford-Johnson algorithm / Merge Insertion Sort
void	PmergeMe::sort(std::vector<int>& X) {
	// Step 1: Group the elements of X into pairs
	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i < X.size(); i += 2) {
		if (i + 1 < X.size()) {
			if (X[i] < X[i + 1]) {
				pairs.push_back(std::make_pair(X[i], X[i + 1]));
			} else {
				pairs.push_back(std::make_pair(X[i + 1], X[i]));
			}
		} else {
			pairs.push_back(std::make_pair(X[i], X[i]));
		}
	}

	// Step 2: Recursively sort the larger elements from each pair
	std::vector<int> S;
	for (size_t i = 0; i < pairs.size(); i++) {
		S.push_back(pairs[i].second);
	}
	PmergeMe::sort(S);

	// Step 3: Insert the smallest element of X into S
	std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), X[0]);
	S.insert(it, X[0]);

	// Step 4: Insert the remaining elements of X into S
	std::vector<int> Y;
	for (size_t i = 1; i < X.size(); i++) {
		if (X[i] <= S[0]) {
			Y.push_back(X[i]);
		} else {
			it = std::lower_bound(S.begin(), S.end(), X[i]);
			S.insert(it, X[i]);
		}
	}

	// Step 5: Insert the remaining elements of Y into S
	std::vector<int>::reverse_iterator rit = Y.rbegin();
	for (size_t i = 0; i < pairs.size(); i++) {
		it = std::lower_bound(S.begin(), S.end(), pairs[i].first);
		S.insert(it, pairs[i].first);
		if (pairs[i].second != pairs[i].first) {
			it = std::lower_bound(S.begin(), S.end(), pairs[i].second);
			S.insert(it, pairs[i].second);
		} else if (rit != Y.rend()) {
			S.insert(S.begin() + 1, *rit);
			rit++;
		}
	}

	// Step 6: Copy the sorted elements back into X
	for (size_t i = 0; i < X.size(); i++) {
		X[i] = S[i];
	}
}

std::ostream	&operator<<(std::ostream &o, PmergeMe const &rhs) {
	std::vector<int>::const_iterator it = rhs._numbers->begin();
	std::vector<int>::const_iterator ite = rhs._numbers->end();
	while (it != ite) {
		o << *it;
		if (++it != ite)
			o << " ";
	}
	return (o);
}