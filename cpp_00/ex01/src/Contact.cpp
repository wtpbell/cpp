/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/05 17:56:24 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/06 19:35:08 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <cctype>

Contact::Contact(void)
{
	return ;
}
Contact::~Contact(void)
{
	return ;
}

bool	Contact::isprintable(const std::string& str)
{
	for (std::size_t i = 0; i < str.length(); i++)
	{
		if (!std::isprint(str[i]))
			return (false);
	}
	return (true);
}

void	Contact::setFirstName(const std::string& firstName)
{
	std::cout << "\e[1mFirst Name > \e[0m";
	while (std::getline(std::cin, this->firstName))
	{
		if (!std::string.is_empty() && )
	}
}
void	Contact::setLastName(const std::string& lastName)
{
	std::cout << "\e[1mLast Name > \e[0m";
}
void	Contact::setNickname(const std::string& nickName)
{
	std::cout << "\e[1mNickname > \e[0m";
}
void	Contact::setPhoneNumber(const std::string& phoneNumber)
{
	std::cout << "\e[1mPhone Number > \e[0m";
}
void	Contact::setDarkestSecret(const std::string& darkestSecret)
{
	std::cout << "\e[1mFDarkest Secret > \e[0m";
}

std::string	Contact::getFirstName(void) const
{
	return (this->firstName);
}
std::string	Contact::getLastName(void) const
{
	return (this->lastName);
}
std::string	Contact::getNickname(void) const
{
	return (this->nickName);
}
std::string	Contact::getPhoneNumber(void) const
{
	return (this->phoneNum);
}
std::string	Contact::getDarkestSecret(void) const
{
	return (this->darkestSecret);
}
