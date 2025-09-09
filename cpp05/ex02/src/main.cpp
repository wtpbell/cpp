/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/02 14:49:29 by bewong        #+#    #+#                 */
/*   Updated: 2025/09/04 14:05:51 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShrubberyForm()
{
	std::cout << CYAN << "\n=== Testing ShrubberyCreationForm ===" << RESET << std::endl;
	try
	{
		Bureaucrat gardener("Gardener", 137);
		ShrubberyCreationForm shrubbery("home");
		std::cout << ORANGE << "✓ Created gardener: " << gardener << RESET << std::endl;
		std::cout << ORANGE << "✓ Created shrubbery: " << shrubbery << RESET << std::endl;
		gardener.signForm(shrubbery);
		gardener.executeForm(shrubbery);

		std::ifstream file("home_shrubbery");
		if (file.good())
		{
			std::cout << GREEN << "✓ Shrubbery file created successfully" << RESET << std::endl;
			file.close();
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}
}

void testRobotomyForm()
{
	std::cout << CYAN << "\n=== Testing RobotomyRequestForm ===" << RESET << std::endl;
	std::srand(std::time(NULL));
	try
	{
		Bureaucrat robot("Robo", 45);
		RobotomyRequestForm robotomy("Bender");
		std::cout << ORANGE << "✓ Created robot: " << robot << RESET << std::endl;
		std::cout << ORANGE << "✓ Created robotomy: " << robotomy << RESET << std::endl;

		robot.signForm(robotomy);
		std::cout << GREEN << "✓ Signed robotomy: " << robotomy << RESET << std::endl;
		robot.executeForm(robotomy);

		for (int i = 0; i < 10; i++)
		{
			std::cout << "\n=== Test " << i + 1 << " ===" << std::endl;
			robot.executeForm(robotomy);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}
}

void testPresidentialPardonForm()
{
	std::cout << CYAN << "\n=== Testing PresidentialPardonForm ===" << RESET << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Zaphod");
		std::cout << ORANGE << "✓ Created president: " << president << RESET << std::endl;
		std::cout << ORANGE << "✓ Created pardon: " << pardon << RESET << std::endl;

		president.signForm(pardon);
		std::cout << GREEN << "✓ Signed pardon: " << pardon << RESET << std::endl;
		president.executeForm(pardon);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}
}

void testFormExecutionWithoutSigning()
{
	std::cout << CYAN << "\n=== Testing Form Execution Without Signing ===" << RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat("Bureaucrat", 1);
		ShrubberyCreationForm form("garden");
		std::cout << ORANGE << "✓ Created bureaucrat: " << bureaucrat << RESET << std::endl;
		std::cout << ORANGE << "✓ Created form: " << form << RESET << std::endl;

		bureaucrat.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << ORANGE << "✓ Caught expected error: " << e.what() << RESET << std::endl;
	}
}


void testInsufficientGradeExecution()
{
	std::cout << CYAN << "\n=== Testing Insufficient Grade for Execution ===" << RESET << std::endl;
	try
	{
		Bureaucrat lowRank("LowRank", 150);
		std::cout << ORANGE << "✓ Created bureaucrat lowRank: " << lowRank << RESET << std::endl;
		Bureaucrat highRank("HighRank", 1);
		std::cout << ORANGE << "✓ Created bureaucrat highRank: " << highRank << RESET << std::endl;
		ShrubberyCreationForm form("garden");
		std::cout << ORANGE << "✓ Created form: " << form << RESET << std::endl;

		highRank.signForm(form);
		std::cout << GREEN << "✓ Signed form: " << form << RESET << std::endl;
		lowRank.executeForm(form);
		lowRank.signForm(form);
		std::cout << GREEN << "✓ Signed form: " << form << RESET << std::endl;
		highRank.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << ORANGE << "✓ Caught expected error: " << e.what() << RESET << std::endl;
	}
}

void testInsufficientGradeSign()
{
	std::cout << CYAN << "\n=== Testing Insufficient Grade for Sign ===" << RESET << std::endl;
	try
	{
		Bureaucrat lowRank("LowRank", 150);
		std::cout << ORANGE << "✓ Created bureaucrat lowRank: " << lowRank << RESET << std::endl;
		Bureaucrat highRank("HighRank", 1);
		std::cout << ORANGE << "✓ Created bureaucrat highRank: " << highRank << RESET << std::endl;
		ShrubberyCreationForm form("garden");
		std::cout << ORANGE << "✓ Created form: " << form << RESET << std::endl;

		lowRank.signForm(form);
		std::cout << GREEN << "✓ Signed form: " << form << RESET << std::endl;
		highRank.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << ORANGE << "✓ Caught expected error: " << e.what() << RESET << std::endl;
	}
}

int	main()
{
	std::cout << BOLD << "=== Starting Form Tests ===" << RESET << std::endl;
	
	testShrubberyForm();
	testRobotomyForm();
	testPresidentialPardonForm();
	testFormExecutionWithoutSigning();
	testInsufficientGradeExecution();
	testInsufficientGradeSign();
	
	std::cout << BOLD << "\n=== End of Tests ===" << RESET << std::endl;
	return 0;
}
