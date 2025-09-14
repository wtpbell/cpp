/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:24:46 by bewong            #+#    #+#             */
/*   Updated: 2025/09/12 13:24:46 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array>
#include <deque>
#include <list>
#include <set>
#include <stdexcept>
#include <vector>

#include "easyfind.hpp"

// STL:
//  Sequence containers: Array, Vector, List, Deque, Forward List
//  Associative containers: Set, Map, Multiset, Multimap
//  Container adaptors: Stack, Queue, Priority Queue
template <typename T>
void print(const T& container)
{
	for (auto i : container)
		std::cout << i << " ";
	std::cout << std::endl;
}

void testWithSet()
{
	std::cout << CYAN << "\n=== Testing with set<int> ===" << RESET
				<< std::endl;
	std::set<int> s = {10, 20, 30, 40, 50};
	try
	{
		auto it = easyfind(s, 2);
		std::cout << "Found " << *it << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void testWithVector()
{
	std::cout << CYAN << "\n=== Testing with vector<int> ===" << RESET
				<< std::endl;
	std::vector<int> vec = {10, 20, 30, 40, 50};
	try
	{
		auto it = easyfind(vec, 50);
		std::cout << "Found " << *it << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void testWithArray()
{
	std::cout << CYAN << "\n=== Testing with array ===" << RESET << std::endl;
	std::array<int, 5> arr = {10, 20, 30, 40, 50};
	try
	{
		std::cout << "Before: " << arr.back() << std::endl;
		int& ref = arr.back();
		ref = 500;
		std::cout << "After: " << arr.back() << std::endl;
		auto it = easyfind(arr, 50);
		std::cout << "Found " << *it << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void testWithDeque()
{
	std::cout << CYAN << "\n=== Testing with deque ===" << RESET << std::endl;
	std::deque<int> d = {4, 10, 2, 6, 8};
	std::cout << "Deque contents: ";
	print(d);
	try
	{
		auto it = easyfind(d, 10);
		std::cout << "Found " << *it << std::endl;
		d.pop_front();
		std::cout << "After pop_front(): try to find 10" << std::endl;
		auto it2 = easyfind(d, 10);
		std::cout << "Found " << *it2 << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int main()
{
	testWithSet();
	testWithVector();
	testWithArray();
	testWithDeque();
	return (0);
}
