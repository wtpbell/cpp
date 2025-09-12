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

#include "easyfind.hpp"

#include <vector>
#include <list>
#include <deque>
#include <array>
#include <set>
#include <stdexcept>

//STL: 
// Sequence containers: Array, Vector, List, Deque, Forward List
// Associative containers: Set, Map, Multiset, Multimap
// Container adaptors: Stack, Queue, Priority Queue
template <typename T>
void	print(const T& container)
{
	for (auto i : container)
		std::cout << i << " ";
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << CYAN << "\n=== Testing with set<int> ===" << RESET << std::endl;
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

	std::cout << CYAN << "\n=== Testing with vector<int> ===" << RESET << std::endl;
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

	std::cout << CYAN << "\n=== Testing with array ===" << RESET << std::endl;
	std::array<int, 5> arr = {10, 20, 30, 40, 50};
	try
	{
		std::cout << "Before: " << arr.back() << std::endl;
		int &ref = arr.back();
		ref = 500;
		std::cout << "After: " << arr.back() << std::endl;
		auto it = easyfind(arr, 50);
		std::cout << "Found " << *it << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Testing with deque ==="<< RESET << std::endl;
	std::deque<int> d;
	d.push_back(2);
	d.push_front(4);
	d.push_back(6);
	d.push_back(8);
	d.push_front(10);
	std::cout << "Print deque d: ";
	print(d);
	try
	{
		auto it = easyfind(d, 10);
		std::cout << "Found " << *it << std::endl;
		d.pop_front();
		std::cout << "After pop_front(): try to find 10" << RESET << std::endl;
		auto it2 = easyfind(d, 10);
		std::cout << "Found " << *it2 << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	
	return (0);
}
