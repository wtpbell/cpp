/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/05 17:56:28 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/06 18:02:33 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "Phonebook.hpp"
#include "Contact.hpp"
int main(void)
{
	PhoneBook	phonebook;
	std::string	line;

	std::cout << "  ____     __                                   __                         __         " << std::endl;
	std::cout << " /\\  _`\\  /\\ \\                                 /\\ \\                       /\\ \\       " << std::endl;
	std::cout << "\\ \\ \\L\\ \\\\ \\ \\___      ___     ___       __   \\ \\ \\____    ___     ___   \\ \\ \\'\\    " << std::endl;
	std::cout << " \\ \\ ,__/ \\ \\  _ `\\   / __`\\ /' _ `\\   /'__`\\  \\ \\ '__`\\  / __`\\  / __`\\  \\ \\ , <    " << std::endl;
	std::cout << "  \\ \\ \\/   \\ \\ \\ \\ \\\\ \\ \\L\\ \\\\ \\ \\/\\ \\\\ \\  __/   \\ \\ \\L\\ \\\\ \\L\\ \\\\ \\L\\ \\  \\ \\ \\\\`\\  " << std::endl;
	std::cout << "   \\ \\_\\    \\ \\_\\ \\_\\\\ \\____/\\ \\_\\ \\_\\\\ \\_____\\   \\ \\_,__/ \\____/ \\____/   \\ \\_\\ \\_\\ " << std::endl;
	std::cout << "    \\/_/     \\/_/\\/_/ \\/___/  \\/_/\\/_/ \\/_____/    \\/___/  \\/___/  \\/___/     \\/_/\\/_/ " << std::endl;
	std::cout << std::endl;
    std::cout << "Welcome to the Simple Phonebook!" << std::endl;
    std::cout << "---------------------------------" << std::endl;
	std::cout << "Enter 'ADD' to add the contact to the phonebook." << std::endl;
	std::cout << "Enter 'SEARCH' to search for contacts." << std::endl;
	std::cout << "Enter 'EXIT' to quit the program." << std::endl;

	while (std::getline(std::cin, line))
	{
		std::string	input(line);

		for (auto &c: line)
			c = std::toupper(c);

		if (input == "EXIT")
			break ; 	
		else if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else
			std::cout << "ERROR: Please enter a correct command." << std::endl;
	}
	std::cout << "Exiting Phonebook. Goodbye!" << std::endl;
	return (0);
}
