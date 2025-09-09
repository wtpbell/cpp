/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/05 17:56:24 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/08 15:11:42 by bewong        ########   odam.nl         */
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

void	Contact::print(void)
{
	std::cout << BOLD << "First Name: " << this->firstName << RESET << std::endl;
	std::cout << BOLD << "Last Name: " << this->lastName << RESET << std::endl;
	std::cout << BOLD << "Nickname: " << this->nickname << RESET << std::endl;
	std::cout << BOLD << "Phone Number: " << this->phoneNumber << RESET << std::endl;
	std::cout << BOLD << "Darkest Secret: " << this->darkestSecret << RESET << std::endl;
}
void Contact::setFirstName(void)
{
	if (!getInput(this->firstName, "First Name: ", false))
		std::cout << std::endl;
}

void Contact::setLastName(void)
{
	if (!getInput(this->lastName, "Last Name: ", false))
		std::cout << std::endl;
}

void Contact::setNickname(void)
{
	if (!getInput(this->nickname, "Nickname: ", false))
		std::cout << std::endl;
}

void Contact::setPhoneNumber(void)
{
    // Here we pass checkDigitsOnly as true to ensure only digits are accepted
	if (!getInput(this->phoneNumber, "Phone Number: ", true))
		std::cout << std::endl;
}

void Contact::setDarkestSecret(void)
{
	if (!getInput(this->darkestSecret, "Darkest Secret: ", false))
		std::cout << std::endl;
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
	return (this->nickname);
}
std::string	Contact::getPhoneNumber(void) const
{
	return (this->phoneNumber);
}
std::string	Contact::getDarkestSecret(void) const
{
	return (this->darkestSecret);
}
