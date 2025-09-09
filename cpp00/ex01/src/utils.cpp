/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/08 13:15:47 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/08 15:09:34 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

bool	isPrintable(const std::string& str)
{
	for (char c : str)
	{
		if (!std::isprint(static_cast<unsigned char>(c)))
			return (false);
	}
	return (true);
}

bool	isValidIndex(const std::string& input, unsigned int& index)
{
	if (input.empty())
		return (false);
	for (char c : input)
	{
		if (!std::isdigit(static_cast<unsigned char>(c)))
			return (false);
	}
	index = std::stoi(input);
	return (index <= 7);
}

bool	isDigitsOnly(const std::string& digits)
{
	for (char d : digits)
	{
		if (!std::isdigit(static_cast<unsigned char>(d)))
			return (false);
	}
	return (true);
}

std::string	truncateField(const std::string& str)
{
	return ((str.length() > 10) ? str.substr(0, 9) + "." : str);
}

bool	getInput(std::string &field, const std::string &prompt, bool isDigits = false)
{
	std::cout << BOLD << prompt << RESET;
	while (std::getline(std::cin, field))
	{
		if (!field.empty() && isPrintable(field))
		{
			if (isDigits)
			{
				if (isDigitsOnly(field))
					return (true);
				else
				{
					std::cerr << RED << BOLD << "Phone number must contain only digits!" << RESET << std::endl;
					std::cout << BOLD << prompt << RESET;
					continue ;
				}
			}
			else
				return (true);
		}
		std::cerr << RED << BOLD "This field cannot be empty, it must contain printable characters!" << RESET << std::endl;
		std::cout << BOLD << prompt << RESET;
	}
	return (false);
}
