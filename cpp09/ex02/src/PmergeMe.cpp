/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/25 11:49:52 by bewong        #+#    #+#                 */
/*   Updated: 2025/09/30 16:55:07 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>
#include <iostream>


int	PmergeMe::jacobsthalNum(size_t n)
{
	return ((std::pow(2, n) - std::pow(-1, n)) / 3);
}

bool	PmergeMe::isAllDigits(std::string_view str)
{
	return (!str.empty() && std::all_of(str.begin(), str.end(), ::isdigit));
}

Sequence	PmergeMe::handleVector(int size, char** argv)
{
	Sequence	c;
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
			c.emplace_back(std::move(value));
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
	return (c);
}

void printSequence(const Sequence& seq)
{
	std::cout << "printSequence: ";
	std::cout << "[";
	for (auto it = seq.begin(); it != seq.end(); ++it)
	{
		if (it != seq.begin()) std::cout << " ";
		std::cout << *it;
	}
	std::cout << "]";
}


void printPairs(const std::vector<Pair>& pairs)
{
	for (size_t idx = 0; idx < pairs.size(); ++idx)
	{
		std::cout << "Pair " << idx << ": ";
		printSequence(pairs[idx].first);
		std::cout << " , ";
		printSequence(pairs[idx].second);
		std::cout << std::endl;
	}
}

Pair PmergeMe::splitAndOrderChunk(Sequence::const_iterator start, size_t pairLevel)
{
	Sequence seq_one(start, std::next(start, pairLevel));
	Sequence seq_two(std::next(start, pairLevel), std::next(start, 2 * pairLevel));

	if (seq_one.back() > seq_two.back())
		std::swap(seq_one, seq_two);

	return {std::move(seq_one), std::move(seq_two)};
}

void	PmergeMe::moveChunk(const Sequence::const_iterator start,
							const Sequence::const_iterator end,
							Sequence& target)
{
	for (auto it = start; it != end; ++it)
		target.push_back(std::move(*it));
}

void	PmergeMe::moveChunk(const Sequence::const_iterator start,
						const Sequence::const_iterator end,
						std::vector<Sequence>& target)
{
	if (start == end)
		return;
	Sequence chunk(start, end);
	target.push_back(std::move(chunk));
}


std::vector<Pair>	PmergeMe::makePairs(const Sequence& c, size_t pairLevel,
					Sequence& odd, Sequence& stray, size_t& comparison_nbr)
{
	size_t				pairChunk;
	bool				isOdd;
	size_t				offset;
	std::vector<Pair>	pairs;
	size_t				end;

	pairChunk = c.size() / pairLevel;
	isOdd = (pairChunk % 2 == 1);
	offset = 2 * pairLevel;
	end = pairLevel * pairChunk - (isOdd ? pairLevel : 0);
	
	for(size_t i = 0; i < end; i += offset)
	{
		auto [seq_one, seq_two] = splitAndOrderChunk(c.begin() + i, pairLevel);
		pairs.emplace_back(std::move(seq_one), std::move(seq_two));
		comparison_nbr++;
	}
	if (isOdd)
	{
		moveChunk(c.begin() + end, std::next(c.begin() + end, pairLevel), odd);
		end += pairLevel;
	}

	if (end < c.size())
		moveChunk(c.begin() + end, c.end(), stray);
	return (pairs);
}

// copy: allocate new memory for new v, then copies each element O(n)
// move: just copies the internal pointer and size/capacity, no element copies O(1)
// std::make_move_iterator(for range): when dereferncing it(*it), it gives an rvalue (T&&) instead of t&
void	PmergeMe::flattenPairs(Sequence& c, std::vector<Pair>& pairs,
			Sequence& odd, Sequence& stray)
{
	printPairs(pairs);
	c.clear();
	c.reserve(pairs.size() * 2 * (pairs[0].first.size()) + odd.size() + stray.size());
	for (auto& pair : pairs)
	{
		c.insert(c.end(), std::make_move_iterator(pair.first.begin()), std::make_move_iterator(pair.first.end()));
		c.insert(c.end(), std::make_move_iterator(pair.second.begin()), std::make_move_iterator(pair.second.end()));
	}
	c.insert(c.end(), std::make_move_iterator(odd.begin()), std::make_move_iterator(odd.end()));
	c.insert(c.end(), std::make_move_iterator(stray.begin()), std::make_move_iterator(stray.end()));
	
	for (auto i : c)
		std::cout << " " << i;
	std::cout << std::endl;
}

void	PmergeMe::buildMainPend(const Sequence& c, std::vector<Sequence>& main,
					std::vector<Sequence>& pend, size_t pairLevel)
{
	size_t				pairChunk;
	bool				isOdd;
	size_t				offset;
	std::vector<Pair>	pairs;
	size_t				end;

	pairChunk = c.size() / pairLevel;
	isOdd = (pairChunk % 2 == 1);
	offset = 2 * pairLevel;
	end = pairLevel * pairChunk - (isOdd ? pairLevel : 0);

	(void) pend;
	(void) main;
}

// void	PmergeMe::jacobsthalInsert(std::vector<Sequence>& main, std::vector<Sequence>& pend,
// 					size_t& comparison_nbr)
// {
	
// }

// void	PmergeMe::insertOddNStray(std::vector<Sequence>& main, const Sequence& odd,
// 					const Sequence& stray, size_t& comparison_nbr)
// {
	
// }

// void	PmergeMe::flattenMain(Sequence& c, const std::vector<Sequence>& main)
// {
	
// }

size_t	PmergeMe::binarySearch(const Sequence& c, int target,
			size_t left, size_t right)
{
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (c[mid] == target)
			return (mid);
		if (c[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

void	PmergeMe::mergeInsertionSort(Sequence& c, size_t pairLevel)
{
	size_t					pairChunk;
	size_t					comparison_nbr;
	Sequence				odd;
	Sequence				stray;
	std::vector<Sequence>	main;
	std::vector<Sequence>	pend;

	pairChunk = c.size() / pairLevel;
	if (pairChunk < 2)
		return ;
	comparison_nbr = 0;
	auto pairs = makePairs(c, pairLevel, odd, stray, comparison_nbr);
	flattenPairs(c, pairs, odd, stray);
	mergeInsertionSort(c, pairLevel * 2);
	buildMainPend(c, main, pend, pairLevel);
	// jacobsthalInsert(main, pend, comparison_nbr);
	// insertOddNStray(main, odd, stray, comparison_nbr);
	// flattenMain(c, main);
}
