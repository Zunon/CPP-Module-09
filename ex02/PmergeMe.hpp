/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:23:15 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/24 17:30:28 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <algorithm>

class PmergeMe {
	private:
		std::vector<int>	*_numbers;
		static std::vector<int> getOrdering(size_t);
	public:
		PmergeMe	(void);
		PmergeMe	(const PmergeMe &);
		~PmergeMe	(void);
		PmergeMe	&operator=(const PmergeMe &);
		std::vector <int>	*getVector(void) const;
		void		addNumber(int);
		void		sort(void);
		static void	sort(std::vector<int> &);
};

std::ostream	&operator<<(std::ostream &, PmergeMe const &);

#endif