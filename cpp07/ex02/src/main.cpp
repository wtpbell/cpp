/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:28:15 by bewong            #+#    #+#             */
/*   Updated: 2025/09/11 10:28:15 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	std::cout << CYAN << "\n=== Testing with empty array ===" << RESET << std::endl;
	Array<int> emptyArray;
	std::cout << "Size: " << emptyArray.size() << std::endl;

	std::cout << CYAN << "\n=== Testing with creating array with size ===" << RESET << std::endl;
	try
	{
		Array<int> array(5);
		std::cout << "Size: " << array.size() << std::endl;
		for (uint32_t i = 0; i < array.size(); i++)
			array[i] = i;
		for (uint32_t i = 0; i < array.size(); i++)
			std::cout << array[i] << " ";
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Testing with string array ===" << RESET << std::endl;
	try
	{
		Array<std::string> stringArray(5);
		for (uint32_t i = 0; i < stringArray.size(); i++)
			stringArray[i] = "Hello";
		for (uint32_t i = 0; i < stringArray.size(); i++)
			std::cout << stringArray[i] << " ";
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Testing with array within array ===" << RESET << std::endl;
	try
	{
		Array<Array<std::string>> array(5);
		for (uint32_t i = 0; i < array.size(); i++)
		{
			array[i] = i;
			for (uint32_t j = 0; j < array[i].size(); j++)
				array[i][j] = 'A' + j;
		}
		for (uint32_t i = 0; i < array.size(); i++)
		{
			for (uint32_t j = 0; j < array[i].size(); j++)
				std::cout << array[i][j] << " ";
			std::cout << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}


	std::cout << CYAN << "\n=== Testing with out of bound index ===" << RESET << std::endl;
	Array<int> array(5);
	try
	{
		array[5] = 42;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Array range " << "0 - " << array.size() - 1 << ": " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Testing with copy assignment operator ===" << RESET << std::endl;
	try
	{
		Array<double> originalArray(5);
		for (uint32_t i = 0; i < originalArray.size(); i++)
			originalArray[i] = i / 2.0;
		Array<double> copyArray(originalArray);
		for (uint32_t i = 0; i < copyArray.size(); i++)
			std::cout << "copyArray: [" << i << "] " << copyArray[i] * 2 << "\n";
		for (uint32_t i = 0; i < originalArray.size(); i++)
			std::cout << "originalArray: [" << i << "] " << originalArray[i]<< "\n";
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Testing with copy constructor ===" << RESET << std::endl;
	try
	{
		Array<int> array2(5);
		for (uint32_t i = 0; i < array2.size(); i++)
		{
			array2[i] = i * 2;
			std::cout << "array2: [" << i << "] " << array2[i] << "\n";
		}
		Array<int> copyArray = array2;
		for (uint32_t i = 0; i < copyArray.size(); i++)
		{
			std::cout << "copyArray: [" << i << "]" << copyArray[i] << "\n";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Testing with move constructor ===" << RESET << std::endl;
	try
	{
		Array<int> array3(5);
		for (uint32_t i = 0; i < array3.size(); i++)
			array3[i] = i * 10;
		Array<int> moveArray = std::move(array3);
		for (uint32_t i = 0; i < moveArray.size(); i++)
			std::cout << "moveArray: [" << i << "] " << moveArray[i] << "\n";
		std::cout << "array3.size() after move: " << array3.size() << "\n";
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Testing with move assignment operator ===" << RESET << std::endl;
	try
	{
		Array<char> array4(5);
		for (uint32_t i = 0; i < array4.size(); i++)
		{
			array4[i] = 'a' + i;
			std::cout << "array4: [" << i << "] " << array4[i] << "\n";
		}
		Array<char> moveArray2(5);
		for (uint32_t i = 0; i < moveArray2.size();	i++)
		{
			moveArray2[i] = 'A' + i;
			std::cout << "Before move moveArray2: [" << i << "] " << moveArray2[i] << "\n";
		}
		moveArray2 = std::move(array4);
		for (uint32_t i = 0; i < moveArray2.size(); i++)
			std::cout << "After move moveArray2: [" << i << "] " << moveArray2[i] << "\n";
		std::cout << "array4.size() after move: " << array4.size() << "\n";
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Testing with destructor ===" << RESET << std::endl;
	try
	{
		Array<int> array5(10);
		std::cout << "array5.size() before end of scope: " << array5.size() << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	return (0);
}
