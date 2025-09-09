#include "Bureaucrat.hpp"

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

void testCopyAndAssignment()
{
	std::cout << CYAN << "\n=== Testing Copy and Assignment ===" << RESET << std::endl;
	try
	{
		Bureaucrat original("Original", 50);
		Bureaucrat copy = original;
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;

		copy.incrementGrade(10);
		std::cout << "After modifying copy: " << copy << std::endl;
		std::cout << "Original should be unchanged: " << original << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "✗ Copy test failed: " << e.what() << RESET << std::endl;
	}
}

int main()
{
	std::cout << BOLD << "=== Bureaucrat Class Test Suite ===" << RESET << std::endl;
	
	testBasicOperations();
	testEdgeCases();
	testInvalidGrades();
	testCopyAndAssignment();

	std::cout << BOLD << "\n=== End of Tests ===" << RESET << std::endl;
	return 0;
}
