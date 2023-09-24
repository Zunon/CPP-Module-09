/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:23:17 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/24 17:31:49 by kalmheir         ###   ########.fr       */
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
	if (X.size() <= 1) return; // Base case for recursion.

	// 1. Grouping elements and finding the larger of each pair.
	size_t n = X.size();
	std::vector<int> S, Y;
	for (size_t i = 0; i + 1 < n; i += 2) {
		if (X[i] < X[i+1]) {
			S.push_back(X[i+1]);
			Y.push_back(X[i]);
		} else {
			S.push_back(X[i]);
			Y.push_back(X[i+1]);
		}
	}
	if (n % 2 == 1) Y.push_back(X[n-1]); // If there's an odd element.

	// 2. Recursively sort the larger elements.
	sort(S);

	// 3. Insert the element paired with the first and smallest element of S.
	if (!S.empty()) {
		S.insert(S.begin(), Y[0]);
		Y.erase(Y.begin());
	}

	// 4. Determine the insertion ordering for the remaining elements.
	std::vector<int> order = getOrdering(Y.size());
	std::vector<int> orderedY(Y.size());
	for (size_t i = 0; i < order.size(); ++i) {
		orderedY[i] = Y[order[i]-3];  // offset of 3 because y_3 is the first element.
	}

	// 5. Insert using binary search.
	for (size_t i = 0; i < orderedY.size(); ++i) {
		int toInsert = orderedY[i];
		auto pos = std::upper_bound(S.begin(), S.end()-i, toInsert);
		S.insert(pos, toInsert);
	}

		X = S; // Copy back the sorted sequence to X.
}

std::vector<int> PmergeMe::getOrdering(size_t n) {
	std::vector<int> order;
	std::vector<int> sizes = {2};
	for (int i = 0; order.size() < n; ++i) {
		for (int j = 0; j < sizes[i] && order.size() < n; ++j) {
			order.push_back(2 * i + 5 - j);  // Generate the sequence.
		}
		if (i % 2 == 1) sizes.push_back(2 * sizes[i] + 2); // Generate sizes: 2, 6, 22,...
	}
	return order;
}

std::vector<int>	*PmergeMe::getVector(void) const {
	return (_numbers);
}

std::ostream	&operator<<(std::ostream &o, PmergeMe const &rhs) {
	std::vector<int>	*vec = rhs.getVector();
	for (size_t i = 0; i < vec->size(); i++) {
		o << (*vec)[i];
		if (i + 1 < vec->size())
			o << " ";
	}
	return (o);
}