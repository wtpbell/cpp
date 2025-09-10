/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/11 11:35:34 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/18 09:10:10 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transformFile.hpp"
#include <filesystem>

static void	createTestFile(const std::string& filename, std::string content)
{
	std::ofstream file(filename);
	if (file.is_open())
	{
		file << content;
		file.close();
	}
}

static void	displayFileContent(const std::string& filename, const std::string& label)
{
	std::ifstream file(filename);
	std::string line;

	if (!file.is_open())
		return ;

	std::cout << YELLOW << label << ":" << RESET << std::endl;
	while (std::getline(file, line))
		std::cout << line << std::endl;
	std::cout << std::endl;
	file.close();
}

static void	runTest(const std::string& testName, const std::string& filename, \
					const std::string& str1, const std::string str2)
{
	std::cout << CYAN << "=== " << testName << " ==="  << RESET << std::endl;

	displayFileContent(filename, "Before");

	TransformFile file(filename, str1, str2);
	if (file.init() == SUCCESS && file.read() == SUCCESS && file.write() == SUCCESS)
	{
		displayFileContent(file.getNewFileName(), "After");
		std::cout << GREEN << "✓ Test passed" << RESET << std::endl;
	}
	else
		std::cout << RED << "✗ Test failed" << RESET << std::endl;
	std::cout << std::string(50, '-') << std::endl << std::endl;
}

int	main(void)
{
	createTestFile("test1", "Hello World\nHello evaluator\nHello Everyone");
	createTestFile("test2", "I have a cat.");
	createTestFile("test3", "aaa\naaaa\naaaaa");
	createTestFile("test4", "Hello\n\nWorld"); 
	createTestFile("test5", "   spaces   ");
	createTestFile("test6", "test1.txt is ready to be opened!");
	createTestFile("empty", "");

	runTest("Basic replacement", "test1", "Hello", "Hi");
	runTest("Replace with longer string", "test2", "a cat", "many pet, like dog, rabbit and bird");
	runTest("Empty strings", "test1", "", "                     ");
	runTest("Replace with empty string", "test2", "cat", "");
	runTest("Empty file", "empty", "anything", "something");
	runTest("Overlapping patterns", "test3", "aa", "b");
	runTest("Empty lines in file", "test4", "\n", "\t");
	runTest("Spaces in string", "test5", "   ", "_");
	runTest("Constructor message", "test6", "is ready to be opened!", "will be replaced by");
	runTest("Non-existent file", "nonexistent.txt", "a", "b");
	runTest("Directory as input", "src", "test", "replace");

	std::filesystem::remove("test1");
	std::filesystem::remove("test2");
	std::filesystem::remove("test3");
	std::filesystem::remove("test4");
	std::filesystem::remove("test5");
	std::filesystem::remove("test6");
	std::filesystem::remove("empty");

	std::filesystem::remove("test1_replace");
	std::filesystem::remove("test2_replace");
	std::filesystem::remove("test3_replace");
	std::filesystem::remove("test4_replace");
	std::filesystem::remove("test5_replace");
	std::filesystem::remove("test6_replace");
	std::filesystem::remove("empty_replace");

	return (0);
}
