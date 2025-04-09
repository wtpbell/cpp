/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 10:05:19 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/08 20:14:59 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>


PhoneBook::PhoneBook(void)
{
	this->numContacts = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(void)
{
	this->contacts[this->numContacts % 8].setFirstName();
	this->contacts[this->numContacts % 8].setLastName();
	this->contacts[this->numContacts % 8].setNickname();
	this->contacts[this->numContacts % 8].setPhoneNumber();
	this->contacts[this->numContacts % 8].setDarkestSecret();
	this->numContacts++;
	std::cout << BOLD << MAGENTA << "Thanks for your input! You can continue or exit." << RESET << std::endl;
}

void	PhoneBook::search(void)
{
	std::string		input;
	unsigned int	index;

	unsigned int	numEntries = (this->numContacts > 7) ? 8 : this->numContacts;
	this->printPhonebook();
	if (numEntries == 0)
	{
		std::cout << RED << BOLD << "There is no entry in phonebook for searching yet." << RESET << std::endl;
		return ;
	}
	std::cout << BOLD << "Enter an index (0-" << (numEntries - 1) << "): " << RESET << std::endl;
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
		{
			this->add();
			return ;
		}
		else if (input == "EXIT")
		{
			std::cout << "Exiting the program..." << std::endl;
			exit(0);
		}
		else if (isValidIndex(input, index))
		{
			displaySearchResult(index);
			std::cout << MAGENTA << BOLD << "Enter another index to search again, 'ADD' to add a new contact, or 'EXIT' to quit: " << RESET << std::endl;
		}
		else
		{
			std::cout << RED << BOLD << "Invalid input! Please enter an index (0-" << (numEntries - 1) << "), or type 'ADD' to add a contact or 'EXIT' to quit: " << RESET << std::endl;
		}
	}
}

void PhoneBook::displaySearchResult(unsigned int index)
{
	if (index <= this->numContacts)
	{
		std::cout << "First name: " << this->contacts[index].getFirstName() << std::endl;
		std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
		std::cout <<"Nickname: " << this->contacts[index].getNickname() << std::endl;
		std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
		std::cout <<"Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
	}
	else
		std::cout << RED << BOLD << "Index out of range!" << RESET << std::endl;
}

void	PhoneBook::printPhonebook(void)
{
	unsigned int	numEntries = (this->numContacts > 7) ? 8 : this->numContacts;

	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│" << std::setw(10) << "Index"
			  << "│" << std::setw(10) << "First Name"
			  << "│" << std::setw(10) << "Last Name"
			  << "│" << std::setw(10) << "Nickname" << "│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;

	for (unsigned int i = 0; i < numEntries; i++)
	{
		std::string color = (i % 2 == 0) ? CYAN : MAGENTA;
		std::cout << "│" << color << std::setw(10) << i << RESET;
		std::cout << "│" << color << std::setw(10) << truncateField(this->contacts[i].getFirstName()) << RESET;
		std::cout << "│" << color << std::setw(10) << truncateField(this->contacts[i].getLastName()) << RESET;
		std::cout << "│" << color << std::setw(10) << truncateField(this->contacts[i].getNickname()) << RESET << "│" << std::endl;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}
