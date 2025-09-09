/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/02 14:49:29 by bewong        #+#    #+#                 */
/*   Updated: 2025/09/04 11:22:20 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

void testValidForms()
{
	std::cout << YELLOW << "\n=== Testing Valid Form Creation ===" << RESET << std::endl;
	try {
		Intern someRandomIntern;
		Bureaucrat bob("Bob", 1);

		AForm* forms[] = {
			someRandomIntern.makeForm("shrubbery creation", "home"),
			someRandomIntern.makeForm("robotomy request", "Bender"),
			someRandomIntern.makeForm("presidential pardon", "Zaphod")
		};

		for (size_t i = 0; i < 3; ++i)
		{
			std::cout << GREEN << "\nTesting " << forms[i]->getName() << RESET << std::endl;
			bob.signForm(*forms[i]);
			bob.executeForm(*forms[i]);
			delete forms[i];
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
}

void testInvalidForm()
{
	std::cout << YELLOW << "\n=== Testing Invalid Form Creation ===" << RESET << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* invalid = someRandomIntern.makeForm("invalid form", "target");

		delete invalid;
	}
	catch (const std::exception& e)
	{
		std::cerr << GREEN << "✓ Caught expected error: " << e.what() << RESET << std::endl;
	}
}

// void testWarning()
// {
// 	std::cout << YELLOW << "\n=== Testing Warning ===" << RESET << std::endl;
// 	try
// 	{
// 		Intern intern;
// 		intern.makeForm("shrubbery creation", "home");
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// }

int	main()
{
	std::cout << BOLD << BLUE << "=== Starting Intern Tests ===" << RESET << std::endl;
	
	testValidForms();
	testInvalidForm();
	// testWarning();
	std::cout << BOLD << BLUE << "\n=== Tests Complete ===" << RESET << std::endl;
	return 0;
}
