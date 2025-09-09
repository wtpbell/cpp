/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/05 17:56:28 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/07 17:42:56 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "Phonebook.hpp"
#include "Contact.hpp"

# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"

int main(void)
{
	PhoneBook	phonebook;
	std::string	line;

	std::cout << YELLOW
			  << "   ____     __                                   __                         __         \n"
			  << "  /\\  _`\\  /\\ \\                                 /\\ \\                       /\\ \\        \n"
			  << "  \\ \\ \\L\\ \\\\ \\ \\___      ___     ___       __   \\ \\ \\____    ___     ___   \\ \\ \\'\\     \n"
			  << "   \\ \\ ,__/ \\ \\  _ `\\   / __`\\  /' _ `\\   /'__`\\  \\ \\ '__`\\  / __`\\  / __`\\  \\ \\ , <     \n"
			  << "    \\ \\ \\/   \\ \\ \\ \\ \\\\ \\ \\L\\ \\\\ \\ \\/\\ \\\\ \\  __/   \\ \\ \\L\\ \\\\ \\L\\ \\\\ \\L\\ \\  \\ \\ \\\\`\\   \n"
			  << "     \\ \\_\\    \\ \\_\\ \\_\\\\ \\____/ \\ \\_\\ \\_\\\\ \\_____\\  \\ \\_,__/ \\____/ \\____/   \\ \\_\\ \\_\\  \n"
			  << "      \\/_/     \\/_/\\/_/ \\/___/   \\/_/\\/_/ \\/_____/   \\/___/  \\/___/  \\/___/     \\/_/\\/_/  \n"
			<< RESET << std::endl;
	std::cout << BOLD << GREEN << "  Welcome to the Simple Phonebook!" << RESET << std::endl;
	std::cout << "---------------------------------------------------------------------------------------" << std::endl;
	std::cout << BOLD << "Enter '" << GREEN << "ADD" << RESET << BOLD << "' to add the contact to the phonebook." << RESET << std::endl;
	std::cout << BOLD << "Enter '" << GREEN << "SEARCH" << RESET << BOLD << "'  to search for contacts." << RESET << std::endl;
	std::cout << BOLD << "Enter '" << RED << "EXIT" << RESET << BOLD << "'  to quit the program." << RESET << std::endl;

	while (std::getline(std::cin, line))
	{
		std::string	input(line);

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
