/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/25 11:49:52 by bewong        #+#    #+#                 */
/*   Updated: 2025/10/07 16:12:09 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>
#include <iostream>
#include <set>

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
	Sequence		c;
	int				value;
	std::set<int>	seen;

	for (int i = 1; i < size; i++)
	{
		try
		{
			if (argv[i][0] == '-')
				throw std::invalid_argument(" must be positive");
			if (!isAllDigits(argv[i]))
				throw std::invalid_argument(" must be a number");
			value = std::stoi(argv[i]);
			if (!seen.insert(value).second)
				throw std::invalid_argument(" is duplicated");
			c.emplace_back(std::move(value));
		}
		catch (std::invalid_argument const& e)
		{
			std::cerr << "Argument: " << argv[i] << e.what() << std::endl;
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


Pair PmergeMe::splitAndOrderChunk(Sequence::const_iterator start, size_t pairLevel)
{
	Sequence seq_one(start, std::next(start, pairLevel));
	Sequence seq_two(std::next(start, pairLevel), std::next(start, 2 * pairLevel));

	if (seq_one.back() > seq_two.back())
		std::swap(seq_one, seq_two);

	return {std::move(seq_one), std::move(seq_two)};
}

void	PmergeMe::moveBatch(const Sequence::const_iterator start,
							const Sequence::const_iterator end,
							Sequence& target)
{
	for (auto it = start; it != end; ++it)
		target.push_back(std::move(*it));
}

void	PmergeMe::moveBatch(const Sequence::const_iterator start,
						const Sequence::const_iterator end,
						std::vector<Sequence>& target)
{
	if (start == end)
		return ;
	Sequence batch(start, end);
	target.push_back(std::move(batch));
}

std::vector<Pair>	PmergeMe::makePairs(const Sequence& c, size_t pairLevel,
					Sequence& odd, Sequence& stray, size_t& comparison_nbr)
{
	std::vector<Pair>	pairs;

	PairingInfo info(c.size(), pairLevel);
	for (size_t i = 0; i < info.end; i += info.offset)
	{
		auto [seq_one, seq_two] = splitAndOrderChunk(c.begin() + i, pairLevel);
		pairs.emplace_back(std::move(seq_one), std::move(seq_two));
		comparison_nbr++;
	}
	if (info.isOdd)
	{
		moveBatch(c.begin() + info.end, std::next(c.begin() + info.end, pairLevel), odd);
		info.end += pairLevel;
	}

	if (info.end < c.size())
		moveBatch(c.begin() + info.end, c.end(), stray);
	return (pairs);
}

void	PmergeMe::flattenPairs(Sequence& c, std::vector<Pair>& pairs)
{
	c.clear();
	c.reserve(pairs.size() * 2 * pairs[0].first.size());

	for (auto& pair : pairs)
	{
		c.insert(c.end(), pair.first.begin(), pair.first.end());
		c.insert(c.end(), pair.second.begin(), pair.second.end());
	}
}


void	PmergeMe::buildMainPend(const Sequence& c, std::vector<Sequence>& main,
					std::vector<Sequence>& pend, Sequence& stray, size_t pairLevel)
{	
	PairingInfo info(c.size(), pairLevel);
	for (size_t i = 0; i < info.end; i += info.offset)
	{
		auto [seq_one, seq_two] = splitAndOrderChunk(c.begin() + i, pairLevel);
		if (main.empty())
		{
			main.emplace_back(std::move(seq_one));
			main.emplace_back(std::move(seq_two));
		}
		else
		{
			main.emplace_back(std::move(seq_two));
			pend.emplace_back(std::move(seq_one));
		}
	}
	if (info.isOdd)
	{
		moveBatch(c.begin() + info.end, std::next(c.begin() + info.end, pairLevel), stray);
		info.end += pairLevel;
	}
	if (info.end < c.size())
		moveBatch(c.begin() + info.end, c.end(), stray);
}

std::vector<size_t>	PmergeMe::jacobsthalOrderFor(size_t m)
{
	std::vector<size_t>	order;
	order.reserve(m);
	
	std::vector<bool> used(m, false);
	for (size_t k = 1; ; ++k)
	{
		int		j;
		size_t	idx;
		
		j = jacobsthalNum(k);
		if (j <= 0 || j > (int)m)
			break ;
		idx = j - 1;
		if (!used[idx])
		{
			order.push_back(idx);
			used[idx] = true;
		}
	}
	for (size_t i = 0; i < m; ++i)
	{
		if (!used[i])
			order.push_back(i);
	}
	return (order);
}
size_t	binaryInsert(std::vector<Sequence>& main, const Sequence& seq, size_t& comparison_nbr)
{
	int		target = seq.back();
	size_t	left = 0;
	size_t	right = main.size();

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		comparison_nbr++;
		if (main[mid].back() < target)
			left = mid + 1;
		else
			right = mid;
	}

	main.insert(main.begin() + left, seq);
	return (left); // return the index for printing/debug
}

void	PmergeMe::jacobsthalInsert(std::vector<Sequence>& main, std::vector<Sequence>& pend,
					size_t& comparison_nbr)
{
	if (pend.empty())
		return ;

	std::vector<size_t> order = jacobsthalOrderFor(pend.size());;

	for (size_t seqIdx : order)
		binaryInsert(main, pend[seqIdx], comparison_nbr);
}

void	PmergeMe::insertOddNStray(std::vector<Sequence>& main, const Sequence& odd,
					const Sequence& stray, size_t& comparison_nbr)
{
	if (!odd.empty())
		binaryInsert(main, odd, comparison_nbr);

	for (int val : stray)
	{
		Sequence temp = {val};
		binaryInsert(main, temp, comparison_nbr);
	}
}

void	PmergeMe::flattenMain(Sequence& c, const std::vector<Sequence>& main)
{
	c.clear();
	size_t total_size = 0;
	for (const auto& seq : main)
		total_size += seq.size();
	c.reserve(total_size);

	for (const auto& seq : main)
		c.insert(c.end(), seq.begin(), seq.end());
}

void PmergeMe::mergeInsertionSort(Sequence& c, size_t pairLevel, MergeInsertionTracer& tracer)
{
	size_t					comparison_nbr = 0;
	Sequence				odd;
	Sequence				stray;
	Sequence				localStray;
	std::vector<Sequence>	main;
	std::vector<Sequence>	pend;
	size_t					pairChunk = c.size() / pairLevel;
	
	if (pairChunk < 2)
		return ;
	tracer.originalInput(c);
	auto pairs = makePairs(c, pairLevel, odd, stray, comparison_nbr);

	for (size_t i = 0; i < pairs.size(); ++i)
		tracer.pair(i, pairs[i].first, pairs[i].second);

	flattenPairs(c, pairs);

	mergeInsertionSort(c, pairLevel * 2, tracer);

	buildMainPend(c, main, pend, localStray, pairLevel);
	tracer.buildMainPend(pairLevel, c);
	tracer.showMainPend(main, pend);

	std::vector<size_t> order = jacobsthalOrderFor(pend.size());
	tracer.jacobsthalOrder(order);
	jacobsthalInsert(main, pend, comparison_nbr);

	Sequence combinedStray = stray;
	combinedStray.insert(combinedStray.end(), localStray.begin(), localStray.end());
	insertOddNStray(main, odd, combinedStray, comparison_nbr);

	flattenMain(c, main);

	tracer.after(c);
}

