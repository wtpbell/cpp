/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:15:30 by bewong            #+#    #+#             */
/*   Updated: 2025/09/14 13:15:30 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <random>
#include <stdexcept>

void	printContainer(const Span& container)
{
	std::cout << "Container contents (" << container.size() << " elements): ";
	for (size_t i = 0; i < container.size(); ++i)
		std::cout << container[i] << " ";
	std::cout << std::endl;
}

static int	randomNumberGenerator(int min, int max)
{
	std::random_device r;
	std::default_random_engine el(r());
	std::uniform_int_distribution<int> dist(min, max);
	return (dist(el));
}

void	testPdfExample(void)
{
	std::cout << "\n=== Testing with pdf example ===" << std::endl;
	try
	{
		Span	sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		printContainer(sp);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error in pdf example test: " << e.what() << std::endl;
	}
}

void	testLargeContainer(void)
{
	std::cout << "\n=== Testing with large container ===" << std::endl;
	try
	{
		Span	largeSpan = Span(10000);
		for (size_t i = 0; i < 10000; ++i)
			largeSpan.addNumber(randomNumberGenerator(0, 10000));
		std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error in large container test: " << e.what() << std::endl;
	}
}

void	testRangeInsertion(void)
{
	std::cout << "\n=== Testing with Range Insertion ===" << std::endl;
	try
	{
		Span rangeSpan = Span(10);
		std::vector<int> vec;
		for (size_t i = 0; i < 10; ++i)
			vec.emplace_back(randomNumberGenerator(0, 100));
		rangeSpan.addNumber(vec.begin(), vec.end());
		printContainer(rangeSpan);
		std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error in range insertion test: " << e.what() << std::endl;
	}
}

void	testException(void)
{
	std::cout << "\n=== Testing with exception ===" << std::endl;
	try
	{
		Span	sp = Span(1);
		sp.addNumber(1);
		sp.addNumber(2);
	}
	catch (std::exception& e)
	{
		std::cout << "Error in exception test: " << e.what() << std::endl;
	}
}

int main()
{
	testPdfExample();
	testLargeContainer();
	testRangeInsertion();
	testException();
	return (0);
}
