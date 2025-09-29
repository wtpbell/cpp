/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/25 11:49:52 by bewong        #+#    #+#                 */
/*   Updated: 2025/09/29 18:07:16 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>
#include <iostream>

int	PmergeMe::jacobsthalNum(size_t n)
{
	return ((std::pow(2, n) - std::pow(-1, n)) / 3);
}

void	PmergeMe::swapPair(Pair& v)
{
	for (auto& [first, second] : v)
		if (first > second)
			std::swap(first, second);
	// std::cout << "After: ";
	// for (const auto& pair : v)
	// 	std::cout << "(" << pair << ", " << pair.second << ") ";
	// std::cout << std::endl;
}

bool	PmergeMe::isAllDigits(std::string_view str)
{
	return (!str.empty() && std::all_of(str.begin(), str.end(), ::isdigit));
}

Sequence	PmergeMe::handleVector(int size, char** argv)
{
	Sequence	v;
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

Pair	PmergeMe::makePairs(const Sequence& v, size_t pairLevel,
					Sequence& odd, Sequence& stray)
{

	std::cout << "Before:";
	for (auto num : v)
		std::cout << " " << num;
	std::cout << std::endl;
}

void	PmergeMe::flattenPairs(Sequence& v, const std::vector<Pair>& pairs,
								const Sequence& odd, const Sequence& stray)
{
	
}

void	PmergeMe::buildMainPend(const Sequence& v, std::vector<Sequence>& main,
					std::vector<Sequence>& pend)
{
	
}



void	PmergeMe::jacobsthalInsert(std::vector<Sequence>& main, std::vector<Sequence>& pend)
{
	
}

void	PmergeMe::insertOddNStray(std::vector<Sequence>& main, const Sequence& odd, const Sequence& stray)
{
	
}

void	PmergeMe::flattenMain(Sequence& v, const std::vector<Sequence>& main)
{
	
}

size_t	PmergeMe::binarySearch(const Sequence& v, int target,
			size_t left, size_t right)
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

void	PmergeMe::mergeInsertionSort(Sequence& v, size_t pairLevel)
{
	size_t		pairChunk;
	Sequence	odd;
	Sequence	stray;

	pairChunk = v.size() / pairLevel;
	if (pairChunk < 2)
		return ;
	auto pairs = makePairs(v, pairLevel, odd, stray);
}
