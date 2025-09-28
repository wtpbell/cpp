/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:39:11 by bewong            #+#    #+#             */
/*   Updated: 2025/09/24 19:39:11 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <algorithm>

// https://medium.com/@ryan_forrester_/binary-sort-in-c-complete-guide-0afcb29c9aec

bool	isAllDigits(std::string_view str)
{
	return (!str.empty() && std::all_of(str.begin(), str.end(), ::isdigit));
}

std::vector<int>	handleVector(int size, char** argv)
{
	std::vector<int>	v;
	int					value;

	for (int i = 1; i < size; i++)
	{
		try
		{
			if (argv[i][0] == '-')
				throw std::invalid_argument("argument must be positive");
			if (!isAllDigits(argv[i]))
				throw std::invalid_argument("argument must be a number");
			value = std::stoi(argv[i]);
			v.emplace_back(value);
		}
		catch (std::invalid_argument const& e)
		{
			std::cerr << "Invalid arguement: " << argv[i] << std::endl;
			throw ;
		}
		catch (std::out_of_range const& e)
		{
			std::cerr << "Arguement out of range [MIN_INT - MAX_INT]: " << argv[i] << std::endl;
			throw ;
		}
	}
	for (int n : v)
		std::cout << n << std::endl;
	return (v);
}

std::vector<std::pair<int, int>>	pairup(std::vector<int>& v)
{
	std::vector<std::pair<int, int>> pairs;
	int					solo = 0;
	bool				is_odd = false;

	std::cout << "Before:";
	for (auto num : v)
		std::cout << " " << num;
	std::cout << std::endl;

	if (v.size() % 2 != 0)
	{
		is_odd = true;
		solo = v.back();
		v.pop_back();
	}

	for (size_t i = 0; i < v.size(); i += 2)
	{
		if (i + 1 < v.size())
			pairs.emplace_back(std::make_pair(v[i], v[i + 1]));
	}

	std::cout << "After: ";
	for (const auto& pair : pairs)
		std::cout << "(" << pair.first << ", " << pair.second << ") ";
	if (is_odd)
		std::cout << solo << " (unpaired)";
	std::cout << std::endl;

	v.clear();
	for (const auto& pair : pairs)
	{
		v.emplace_back(pair.first);
		v.emplace_back(pair.second);
	}
	if (is_odd)
		v.emplace_back(solo);
	return (pairs);
}

void	swapPair(std::vector<std::pair<int, int>>& v)
{
	for (auto& [first, second] : v)
		if (first > second)
			std::swap(first, second);
	std::cout << "After: ";
	for (const auto& pair : v)
		std::cout << "(" << pair.first << ", " << pair.second << ") ";
	std::cout << std::endl;
}

size_t	binarySearch(const std::vector<int>& v, int target, size_t left, size_t right)
{
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (v[mid] == target)
			return (mid);
		if (v[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

int	main(int argc, char** argv)
{
	std::vector<int>	vect;

	if (argc < 2)
	{
		std::cerr << "Error [usage]: " << argv[0] << " <unsorted / sorted container>" << std::endl;
		return (1);
	}
	try
	{
		vect = handleVector(argc, argv);
	}
	catch (...)
	{
		return (1);
	}
	auto pairs = pairup(vect);
	swapPair(pairs);
	return (0);
}
