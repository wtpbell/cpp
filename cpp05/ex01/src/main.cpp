/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/02 14:49:29 by bewong        #+#    #+#                 */
/*   Updated: 2025/09/04 14:06:17 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

//==============================================EX00==============================================//

void testBasicOperations()
{
	std::cout << CYAN << "\n=== Testing Basic Operations ===" << RESET << std::endl;
	try
	{
		Bureaucrat basic("Basic", 75);
		std::cout << GREEN << "✓ Created: " << basic << RESET << std::endl;
		
		basic.incrementGrade(10);
		std::cout << "After incrementing by 10: " << basic << std::endl;
		
		basic.decrementGrade(5);
		std::cout << "After decrementing by 5: " << basic << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "✗ Error in basic operations: " << e.what() << RESET << std::endl;
	}
}

void testEdgeCases()
{
	std::cout << CYAN << "\n=== Testing Edge Cases ===" << RESET << std::endl;
	// Test grade 1 (highest)
	try
	{
		Bureaucrat high("HighRank", 1);
		std::cout << GREEN << "✓ Created: " << high << RESET << std::endl;
		high.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "✗ High rank test: " << e.what() << RESET << std::endl;
	}

	// Test grade 150 (lowest)
	try
	{
		Bureaucrat low("LowRank", 150);
		std::cout << GREEN << "✓ Created: " << low << RESET << std::endl;
		low.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "✗ Low rank test: " << e.what() << RESET << std::endl;
	}
}

void testInvalidGrades()
{
	std::cout << CYAN << "\n=== Testing Invalid Grades ===" << RESET << std::endl;
	// Test too high grade
	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "✗ Grade 0 test: " << e.what() << RESET << std::endl;
	}

	// Test too low grade
	try
	{
		Bureaucrat tooLow("TooLow", 151);
	}
	catch (const std::exception& e) 
	{
		std::cerr << RED << "✗ Grade 151 test: " << e.what() << RESET << std::endl;
	}

	// Test negative grade
	try
	{
		Bureaucrat negative("Negative", -42);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "✗ Negative grade test: " << e.what() << RESET << std::endl;
	}
}

//==============================================EX01==============================================//

void testFormCreation()
{
	std::cout << CYAN << "\n=== Testing Form Creation ===" << RESET << std::endl;
	try
	{
		Form taxForm("Tax Form", 50, 75);
		std::cout << GREEN << "✓ Created form: " << taxForm << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "✗ Failed to create form: " << e.what() << RESET << std::endl;
	}
}

void testInvalidFormCreation()
{
	std::cout << CYAN << "\n=== Testing Invalid Form Creation ===" << RESET << std::endl;
	try
	{
		Form invalidForm("Invalid Form", 0, 151);
		std::cout << RED << "✗ Should not reach here - invalid form created" << RESET << std::endl;
		// Form invalidForm("Invalid Form", 0, -1);
		// std::cout << RED << "✗ Should not reach here - invalid form created" << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << ORANGE << "✓ Caught invalid form creation: " << e.what() << RESET << std::endl;
	}
}

void testFormSigning()
{
	std::cout << CYAN << "\n=== Testing Form Signing ===" << RESET << std::endl;
	try
	{
		Form leaveForm("Leave Form", 50, 50);
		Bureaucrat manager("Manager", 10);
		manager.signForm(leaveForm);
		std::cout << "✓ Manager signed form: " << leaveForm << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "✗ Failed to sign form: " << e.what() << RESET << std::endl;
	}
}
void testInsufficientGradeSigning()
{
	std::cout << CYAN << "\n=== Testing Insufficient Grade Signing ===" << RESET << std::endl;
	try
	{
		Form raiseForm("Raise Form", 10, 10);
		Bureaucrat intern("Intern", 100);
		intern.signForm(raiseForm);
		if (!raiseForm.isSigned())
			std::cout << GREEN << "✓ Successfully prevented intern from signing the form" << RESET << std::endl;
		else 
			std::cout << RED << "✗ Form should not be signed" << RESET << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << RED << "✗ Unexpected error: " << e.what() << RESET << std::endl;
	}
}

void testDoubleSigning()
{
	std::cout << CYAN << "\n=== Testing Double Signing ===" << RESET << std::endl;
	try
	{
		Form bonusForm("Bonus Form", 30, 30);
		Bureaucrat ceo("CEO", 1);
		ceo.signForm(bonusForm);
		std::cout << GREEN << "✓ CEO signed form: " << bonusForm << RESET << std::endl;

		Bureaucrat cfo("CFO", 1);
		if (bonusForm.isSigned())
		{
			std::cout << ORANGE << "✓ Form is already signed, CFO cannot sign again" << RESET << std::endl;
			cfo.signForm(bonusForm);
		} else
			std::cout << RED << "✗ Form should be signed but isn't" << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << ORANGE << "✓ Caught exception: " << e.what() << RESET << std::endl;
	}
}

void testMinimumGradeSigning()
{
	std::cout << CYAN << "\n=== Testing Minimum Grade Signing ===" << RESET << std::endl;
	try
	{
		Form budgetForm("Budget Approval", 150, 150);
		Bureaucrat newHire("New Hire", 150);
		newHire.signForm(budgetForm);
		std::cout << GREEN << "✓ New hire signed with minimum required grade: "
				<< budgetForm << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "✗ Failed to sign with minimum grade: "
				<< e.what() << RESET << std::endl;
	}
}

int main()
{
	std::cout << BOLD << "=== Form Class Test Suite ===" << RESET << std::endl;
	
	testBasicOperations();
	testEdgeCases();
	testInvalidGrades();
	testFormCreation();
	testInvalidFormCreation();
	testFormSigning();
	testInsufficientGradeSigning();
	testDoubleSigning();
	testMinimumGradeSigning();

	std::cout << BOLD << "\n=== End of Tests ===" << RESET << std::endl;
	return (0);
}
