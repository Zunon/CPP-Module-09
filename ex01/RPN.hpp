/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:27:15 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/18 18:27:57 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stdexcept>
# include <stack>
# include <sstream>
# define IS_OPERATOR(c) (c == '+' || c == '-' || c == '*' || c == '/')

typedef enum	e_operator {
	PLUS = '+',
	MINUS = '-',
	MULT = '*',
	DIV = '/',
}				t_operator;

typedef struct s_expression {
	int			left;
	int			right;
	t_operator	op;
}				t_expression;

class RPN {
	private:
		std::stack<int>	*_memory;
		std::string		_expression;
		static void		validateChars(std::string &);
		static int		compute(int, int, t_operator);
		static int		add(int, int);
		static int		subtract(int, int);
		static int		multiply(int, int);
		static int		divide(int, int);
	public:
		RPN		(void);
		RPN		(std::string &);
		RPN		(const char *);
		RPN		(RPN const &);
		~RPN	(void);
		RPN		&operator=(RPN const &);
		
		int			compute(void) const;
		void		setExpression(std::string &);
		void		setExpression(const char *);
		std::string	getExpression(void) const;
		
		class InvalidExpressionException : public std::exception {
			private:
				std::string	_error;
			public:
				InvalidExpressionException	(void);
				InvalidExpressionException	(std::string);
				InvalidExpressionException	(const InvalidExpressionException &);
				~InvalidExpressionException	(void) throw();
				InvalidExpressionException	&operator=(const InvalidExpressionException &);
				virtual const char			*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &, const RPN &);

#endif