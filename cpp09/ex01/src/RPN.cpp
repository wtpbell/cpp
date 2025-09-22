/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:50:06 by bewong            #+#    #+#             */
/*   Updated: 2025/09/22 10:50:06 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <iostream>

int	RPN::calculateOperation(int left, int right, char op)
{
	switch (op)
	{
		case '+':
			return (left + right);
		case '-':
			return (left - right);
		case '*':
			return (left * right);
		case '/':
			if (right == 0)
				throw std::runtime_error("Division by zero");
			return (left / right);
		default:
			throw std::runtime_error("Invalid operator");
	}
}

int	RPN::calculate(const std::string& expression)
{
	if (expression.empty() || expression.find_first_not_of(' ') == std::string::npos)
		throw std::runtime_error("Empty expression");
	if (expression.find_first_not_of("0123456789 +-*/") != std::string::npos)
		throw std::runtime_error("Error");

	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token)
	{
		if (token.size() != 1)
			throw std::runtime_error("Invalid token");
		if (std::isdigit(token[0]))
			stack_.emplace(token[0] - '0');
		else 
		{
			if (stack_.size() < 2)
				throw std::runtime_error("Not enough operands");
			int	right = stack_.top(); stack_.pop();
			int	left = stack_.top(); stack_.pop();
			try
			{
				stack_.emplace(calculateOperation(left, right, token[0]));
			}
			catch (const std::exception& e)
			{
				throw std::runtime_error(e.what());
			}
		}
	}
	if (stack_.size() != 1)
		throw std::runtime_error("Error: Invalid expression");
	return (stack_.top());
}
