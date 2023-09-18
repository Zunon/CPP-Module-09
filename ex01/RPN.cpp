/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:27:24 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/18 22:05:16 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	RPN::validateChars(std::string &expression) {
	for (std::string::iterator it = expression.begin(); it != expression.end(); it++) {
		if (!IS_OPERATOR(*it) && !std::isdigit(*it) && !std::isspace(*it))
			throw RPN::InvalidExpressionException("Invalid character in expression");
	}
}

RPN::RPN(void) : _memory(new std::stack<int>), _expression("") {}

RPN::RPN(std::string &expression) : _memory(new std::stack<int>), _expression(expression) {
	validateChars(_expression);
}

RPN::RPN(const char *expression) : _memory(new std::stack<int>), _expression(expression) {
	validateChars(_expression);
}

RPN::RPN(RPN const &other) : _memory(new std::stack<int>), _expression(other._expression) {
	validateChars(_expression);
}

RPN::~RPN(void) {
	delete _memory;
}

RPN	&RPN::operator=(RPN const &other) {
	if (this != &other)
		_expression = other._expression;
	validateChars(_expression);
	return (*this);
}

void	RPN::setExpression(std::string &expression) {
	_expression = expression;
	validateChars(_expression);
}

void	RPN::setExpression(const char *expression) {
	_expression = expression;
	validateChars(_expression);
}

std::string	RPN::getExpression(void) const {
	return (_expression);
}

std::ostream	&operator<<(std::ostream &out, const RPN &rpn) {
out << rpn.compute();
	return (out);
}

RPN::InvalidExpressionException::InvalidExpressionException() : _error("Invalid expression") {}

RPN::InvalidExpressionException::InvalidExpressionException(std::string error) : _error(error) {}

RPN::InvalidExpressionException::InvalidExpressionException(const InvalidExpressionException &other)
	: _error(other._error) {}

RPN::InvalidExpressionException::~InvalidExpressionException(void) throw() {}

RPN::InvalidExpressionException	&RPN::InvalidExpressionException::operator=(const InvalidExpressionException &other) {
	if (this != &other)
		_error = other._error;
	return (*this);
}

const char	*RPN::InvalidExpressionException::what(void) const throw() {
	return (_error.c_str());
}

int RPN::compute(int a, int b, t_operator op) {
	switch (op) {
		case PLUS:
			return (add(a, b));
		case MINUS:
			return (subtract(a, b));
		case MULT:
			return (multiply(a, b));
		case DIV:
			return (divide(a, b));
		default:
			throw RPN::InvalidExpressionException("Invalid operator");
	}
}

int	RPN::add(int a, int b) {
	return (a + b);
}

int	RPN::subtract(int a, int b) {
	return (a - b);
}

int	RPN::multiply(int a, int b) {
	return (a * b);
}

int	RPN::divide(int a, int b) {
	if (b == 0)
		throw RPN::InvalidExpressionException("Division by zero");
	return (a / b);
}

int	RPN::compute(void) const {
	std::string		expression(_expression);
	std::string		token;
	size_t			pos;
	t_expression	expr;
	
	while (expression.length() > 0) {
		pos = expression.find_first_of(' ');
		token = expression.substr(0, pos);
		if (pos == std::string::npos)
			expression = "";
		else
			expression = expression.substr(pos + 1);
		if (token.length() == 0)
			continue ;
		if (IS_OPERATOR(token[0])) {
			if (token.length() > 1)
				throw RPN::InvalidExpressionException("Invalid operator");
			if (_memory->size() < 2)
				throw RPN::InvalidExpressionException("Not enough operands");
			expr.right = _memory->top();
			_memory->pop();
			expr.left = _memory->top();
			_memory->pop();
			expr.op = static_cast<t_operator>(token[0]);
			_memory->push(compute(expr.left, expr.right, expr.op));
		} else {
			std::istringstream stream(token);
			int value;
			if (!(stream >> value))
				throw RPN::InvalidExpressionException("Invalid operand");
			_memory->push(value);
		}
	}
	if (_memory->size() > 1)
		throw RPN::InvalidExpressionException("Too many operands");
	else if (_memory->size() < 1)
		throw RPN::InvalidExpressionException("Not enough operands");
		
	int result = _memory->top();
	return (result);
}
