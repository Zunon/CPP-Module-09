/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:23:15 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/24 23:31:36 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <deque>
# include <vector>
# include <algorithm>
# include <ctime>

class PmergeMe {
	private:
		std::vector<int>	*_vec;
		std::deque<int>		*_deq;
		static std::deque<int>	binarySearchInsertionDeq(std::deque<int> &, int);
		static std::deque< std::deque<int> >	sortList2DDeq(const std::deque< std::deque<int> > &);
		static std::vector<int>	binarySearchInsertionVec(std::vector<int> &, int);
		static std::vector< std::vector<int> >	sortList2DVec(const std::vector< std::vector<int> > &);
	public:
		PmergeMe	(void);
		PmergeMe	(const PmergeMe &);
		~PmergeMe	(void);
		PmergeMe	&operator=(const PmergeMe &);
		std::vector <int>	*getVector(void) const;
		std::deque <int>	*getDeque(void) const;
		void		addNumber(int);
		void		sortVec(void);
		static void	sortVec(std::vector<int> &);
		void		sortDeq(void);
		static void	sortDeq(std::deque<int> &);
};

std::ostream	&operator<<(std::ostream &, PmergeMe const &);

#endif