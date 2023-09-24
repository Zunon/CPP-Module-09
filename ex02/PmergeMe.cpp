/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:23:17 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/24 23:33:48 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void): _vec(new std::vector<int>), _deq(new std::deque<int>) {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	if (this != &other) {
		delete _vec;
		_vec = new std::vector<int>;
		*_vec = *other._vec;
		delete _deq;
		_deq = new std::deque<int>;
		*_deq = *other._deq;
	}
}

PmergeMe::~PmergeMe(void) {
	delete _vec;
	delete _deq;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		delete _vec;
		_vec = new std::vector<int>;
		*_vec = *other._vec;
		delete _deq;
		_deq = new std::deque<int>;
		*_deq = *other._deq;
	}
	return (*this);
}

void	PmergeMe::addNumber(int n) {
	_vec->push_back(n);
	_deq->push_back(n);
}

void	PmergeMe::sortDeq(void) {
	sortDeq(*_deq);
}

std::deque<int>	PmergeMe::binarySearchInsertionDeq(std::deque<int> &sortedList, int number) {
	std::deque<int>::iterator iter = std::lower_bound(sortedList.begin(), sortedList.end(), number);
	sortedList.insert(iter, number);
	return (sortedList);
}

std::deque< std::deque<int> > PmergeMe::sortList2DDeq(const std::deque< std::deque<int> > &list2D) {
	if (list2D.size() <= 1)
		return (list2D);
	
	size_t middle = list2D.size() / 2;
	std::deque< std::deque<int> > left(list2D.begin(), list2D.begin() + middle);
	std::deque< std::deque<int> > right(list2D.begin() + middle, list2D.end());

	left = sortList2DDeq(left);
	right = sortList2DDeq(right);

	std::deque< std::deque<int> > result;
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(result));

	return (result);
}

// Ford-Johnson algorithm / Merge Insertion Sort
 void	PmergeMe::sortDeq(std::deque<int> &numbers) {
	if (numbers.size() <= 1)
		return ;
	
	std::deque< std::deque<int> > pairs;
	bool has_odd = false;

	for (size_t i = 0; i < numbers.size(); i += 2) {
		if (i == numbers.size() - 1)
			has_odd = true;
		else {
			std::deque<int> pair(2);
			pair[0] = std::min(numbers[i], numbers[i + 1]);
			pair[1] = std::max(numbers[i], numbers[i + 1]);
			pairs.push_back(pair);
		}
	}

	std::deque< std::deque<int> > sortedPairs = sortList2DDeq(pairs);

	std::deque<int> result;
	for (size_t i = 0; i < sortedPairs.size(); i++)
		result.push_back(sortedPairs[i][0]);
	result.push_back(sortedPairs.back()[1]);

	if (has_odd) {
		int pivot = numbers.back();
		result = binarySearchInsertionDeq(result, pivot);
	}

	bool isLastOddItemInsertedBeforeThisIndex = false;
	for (size_t i = 0; i < sortedPairs.size() - 1; ++i) {
		if (result[i] == numbers[numbers.size() - 1 - i])
			isLastOddItemInsertedBeforeThisIndex = true;
		int pivot = sortedPairs[i][1];
		if (isLastOddItemInsertedBeforeThisIndex) {
			std::deque<int> portion(result.begin() + i + 2, result.end());
			std::deque<int> temp = binarySearchInsertionDeq(portion, pivot);
			result.erase(result.begin() + i + 2, result.end());
			result.insert(result.end(), temp.begin(), temp.end());
		} else {
			std::deque<int> portion(result.begin() + i + 1, result.end());
			std::deque<int> temp = binarySearchInsertionDeq(portion, pivot);
			result.erase(result.begin() + i + 1, result.end());
			result.insert(result.end(), temp.begin(), temp.end());
		}
	}

	numbers = result;
}

std::vector<int>	PmergeMe::binarySearchInsertionVec(std::vector<int> &sortedList, int number) {
	std::vector<int>::iterator iter = std::lower_bound(sortedList.begin(), sortedList.end(), number);
	sortedList.insert(iter, number);
	return (sortedList);
}

std::vector< std::vector<int> > PmergeMe::sortList2DVec(const std::vector< std::vector<int> > &list2D) {
	if (list2D.size() <= 1)
		return (list2D);
	
	size_t middle = list2D.size() / 2;
	std::vector< std::vector<int> > left(list2D.begin(), list2D.begin() + middle);
	std::vector< std::vector<int> > right(list2D.begin() + middle, list2D.end());

	left = sortList2DVec(left);
	right = sortList2DVec(right);

	std::vector< std::vector<int> > result;
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(result));

	return (result);
}

void	PmergeMe::sortVec(void) {
	sortVec(*_vec);
}

// Ford-Johnson algorithm / Merge Insertion Sort
 void	PmergeMe::sortVec(std::vector<int> &numbers) {
	if (numbers.size() <= 1)
		return ;
	
	std::vector< std::vector<int> > pairs;
	bool has_odd = false;

	for (size_t i = 0; i < numbers.size(); i += 2) {
		if (i == numbers.size() - 1)
			has_odd = true;
		else {
			std::vector<int> pair(2);
			pair[0] = std::min(numbers[i], numbers[i + 1]);
			pair[1] = std::max(numbers[i], numbers[i + 1]);
			pairs.push_back(pair);
		}
	}

	std::vector< std::vector<int> > sortedPairs = sortList2DVec(pairs);

	std::vector<int> result;
	for (size_t i = 0; i < sortedPairs.size(); i++)
		result.push_back(sortedPairs[i][0]);
	result.push_back(sortedPairs.back()[1]);

	if (has_odd) {
		int pivot = numbers.back();
		result = binarySearchInsertionVec(result, pivot);
	}

	bool isLastOddItemInsertedBeforeThisIndex = false;
	for (size_t i = 0; i < sortedPairs.size() - 1; ++i) {
		if (result[i] == numbers[numbers.size() - 1 - i])
			isLastOddItemInsertedBeforeThisIndex = true;
		int pivot = sortedPairs[i][1];
		if (isLastOddItemInsertedBeforeThisIndex) {
			std::vector<int> portion(result.begin() + i + 2, result.end());
			std::vector<int> temp = binarySearchInsertionVec(portion, pivot);
			result.erase(result.begin() + i + 2, result.end());
			result.insert(result.end(), temp.begin(), temp.end());
		} else {
			std::vector<int> portion(result.begin() + i + 1, result.end());
			std::vector<int> temp = binarySearchInsertionVec(portion, pivot);
			result.erase(result.begin() + i + 1, result.end());
			result.insert(result.end(), temp.begin(), temp.end());
		}
	}

	numbers = result;
}

std::vector<int>	*PmergeMe::getVector(void) const {
	return (_vec);
}

std::deque<int>	*PmergeMe::getDeque(void) const {
	return (_deq);
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