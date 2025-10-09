/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:49:52 by bewong            #+#    #+#             */
/*   Updated: 2025/10/09 21:37:29 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMe.tpp"
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

PmergeMe::VectorPair PmergeMe::splitAndOrderChunk(Vector::const_iterator start,size_t pairLevel)
{
	Vector seq_one(start, std::next(start, pairLevel));
	Vector seq_two(std::next(start, pairLevel), std::next(start, 2 * pairLevel));

	if (seq_one.back() > seq_two.back())
		std::swap(seq_one, seq_two);

	return {std::move(seq_one), std::move(seq_two)};
}

PmergeMe::ListPair PmergeMe::splitAndOrderChunk(List::const_iterator start, size_t pairLevel)
{
	List seq_one(start, std::next(start, pairLevel));
	List seq_two(std::next(start, pairLevel), std::next(start, 2 * pairLevel));

	if (seq_one.back() > seq_two.back())
		std::swap(seq_one, seq_two);

	return {std::move(seq_one), std::move(seq_two)};
}

PmergeMe::VectorOfPairs	PmergeMe::makePairs(const Vector& c, size_t pairLevel,
					Vector& odd, Vector& stray, size_t& comparison_nbr)
{
	VectorOfPairs	pairs;
	PairingInfo		info(c.size(), pairLevel);

	for (size_t i = 0; i < info.end; i += info.offset)
	{
		auto [seq_one, seq_two] = splitAndOrderChunk(c.begin() + i, pairLevel);
		pairs.emplace_back(std::move(seq_one), std::move(seq_two));
		comparison_nbr++;
	}

	if (info.isOdd)
	{
		moveBatch<Vector, Vector>(c.begin() + info.end, 
								std::next(c.begin() + info.end, pairLevel), 
								odd);
		info.end += pairLevel;
	}

	if (info.end < c.size())
		moveBatch<Vector, Vector>(c.begin() + info.end, c.end(), stray);
	return (pairs);
}

PmergeMe::ListOfPairs	PmergeMe::makePairs(const List& c, size_t pairLevel,
				List& odd, List& stray, size_t& comparison_nbr)
{
	ListOfPairs	pairs;
	auto		it = c.begin();
	size_t		remaining = std::distance(c.begin(), c.end());

	while (remaining >= 2 * pairLevel)
	{
		auto	next = std::next(it, pairLevel * 2);
		auto	[seq_one, seq_two] = splitAndOrderChunk(it, pairLevel);
		
		pairs.emplace_back(std::move(seq_one), std::move(seq_two));
		comparison_nbr++;
		it = next;
		remaining = std::distance(it, c.end());
	}

	if (remaining > 0)
	{
		if (remaining >= pairLevel)
		{
			auto next = std::next(it, pairLevel);
			moveBatch<List, List>(it, next, odd);
			it = next;
			remaining = std::distance(it, c.end());
		}
		if (it != c.end())
			moveBatch<List, List>(it, c.end(), stray);
	}
	return (pairs);
}

void	PmergeMe::flattenPairs(Vector& c, VectorOfPairs& pairs)
{
	c.clear();
	c.reserve(pairs.size() * 2 * pairs[0].first.size());

	for (auto& pair : pairs)
	{
		c.insert(c.end(), pair.first.begin(), pair.first.end());
		c.insert(c.end(), pair.second.begin(), pair.second.end());
	}
}

void	PmergeMe::flattenPairs(List& c, ListOfPairs& pairs)
{
	c.clear();

	for (auto& pair : pairs)
	{
		c.splice(c.end(), pair.first);
		c.splice(c.end(), pair.second);
	}
}

void	PmergeMe::buildMainPend(const Vector& c, VectorOfVectors& main,
					VectorOfVectors& pend, Vector& stray, size_t pairLevel)
{	
	PairingInfo info(c.size(), pairLevel);
	
	for (size_t i = 0; i < info.end; i += info.offset)
	{
		auto [seq_one, seq_two] = splitAndOrderChunk(c.begin() + i, pairLevel);
		if (main.empty())
		{
			main.push_back(std::move(seq_one));
			main.push_back(std::move(seq_two));
		}
		else
		{
			main.push_back(std::move(seq_two));
			pend.push_back(std::move(seq_one));
		}
	}

	if (info.isOdd)
	{
		moveBatch<Vector, Vector>(c.begin() + info.end,
								std::next(c.begin() + info.end, pairLevel), 
								stray);
		
		info.end += pairLevel;
	}

	if (info.end < c.size())
		moveBatch<Vector, Vector>(c.begin() + info.end, c.end(), stray);
}

void	PmergeMe::buildMainPend(const List& c, ListOfLists& main,
					ListOfLists& pend, List& stray, size_t pairLevel)
{
	auto it = c.begin();
	size_t remaining = std::distance(c.begin(), c.end());
	bool is_first = true;

	while (remaining >= 2 * pairLevel)
	{
		auto next = std::next(it, 2 * pairLevel);
		auto [seq_one, seq_two] = splitAndOrderChunk(it, pairLevel);
		
		if (is_first)
		{
			main.push_back(std::move(seq_one));
			main.push_back(std::move(seq_two));
			is_first = false;
		}
		else
		{
			main.push_back(std::move(seq_two));
			pend.push_back(std::move(seq_one));
		}
		
		it = next;
		remaining = std::distance(it, c.end());
	}

	if (remaining > 0)
	{
		List temp;
		moveBatch<List, List>(it, c.end(), temp);
		stray.splice(stray.end(), temp);
	}
}

std::vector<size_t>	PmergeMe::jacobsthalOrderFor(size_t m)
{
	std::vector<size_t>	order;
	
	if (m == 0)
		return order;

	order.push_back(0);

	size_t	j_prev_prev = 0;
	size_t	j_prev = 1;
	size_t	j = j_prev_prev + 2 * j_prev;

	while (j < m)
	{
		order.push_back(j - 1);
		j_prev_prev = j_prev;
		j_prev = j;
		j = j_prev_prev + 2 * j_prev;
	}

	size_t	last = j_prev - 1;
	for (size_t i = m - 1; i > last; --i)
		order.push_back(i);
	return (order);
}

void	PmergeMe::flattenMain(Vector& c, const VectorOfVectors& main)
{
	c.clear();
	size_t total_size = 0;
	for (const auto& seq : main)
		total_size += seq.size();
	c.reserve(total_size);

	for (const auto& seq : main)
		c.insert(c.end(), seq.begin(), seq.end());
}

void PmergeMe::flattenMain(List& c, const ListOfLists& main)
{
	c.clear();
	for (const auto& seq : main)
		c.splice(c.end(), const_cast<List&>(seq));
}

void PmergeMe::sort(Vector& c, size_t pairLevel, MergeInsertionTracer& tracer)
{
	size_t			comparison_nbr = 0;
	Vector			odd;
	Vector			stray;
	Vector			localStray;
	VectorOfVectors	main;
	VectorOfVectors	pend;

	tracer.levelStart(pairLevel, c);

	size_t			pairChunk = c.size() / pairLevel;
	if (pairChunk < 2)
	{
		tracer.levelFinal(c);
		return;
	}

	auto			pairs = makePairs(c, pairLevel, odd, stray, comparison_nbr);
	tracer.levelOddStray(odd, stray);
	tracer.levelPairs(pairs);

	if (!stray.empty())
		localStray.insert(localStray.end(), stray.begin(), stray.end());

	flattenPairs(c, pairs);
	sort(c, pairLevel * 2, tracer);
	buildMainPend(c, main, pend, localStray, pairLevel);
	if (!localStray.empty())
		insertOddNStray(main, Vector(), localStray, comparison_nbr);
	tracer.mainPendStart(pairLevel, c);
	tracer.showMainPend(main, pend);
	tracer.jacobsthalOrder(jacobsthalOrderFor(pend.size()));
	jacobsthalInsert(main, pend, comparison_nbr);
	if (!odd.empty())
		tracer.insertingOdd(odd), insertOddNStray(main, odd, Vector(), comparison_nbr);
	flattenMain(c, main);
	tracer.finalAfter(c);
}


void	PmergeMe::sort(List& c, size_t pairLevel, MergeInsertionTracer& tracer)
{
	size_t comparison_nbr = 0;
	List odd;
	List stray;
	List localStray;
	ListOfLists main;
	ListOfLists pend;
	size_t pairChunk = std::distance(c.begin(), c.end()) / pairLevel;

	if (pairChunk < 2)
		return ;

	auto pairs = makePairs(c, pairLevel, odd, stray, comparison_nbr);

	flattenPairs(c, pairs);
	sort(c, pairLevel * 2, tracer);
	if (!stray.empty())
		localStray.splice(localStray.end(), stray);
	buildMainPend(c, main, pend, localStray, pairLevel);
	jacobsthalInsert(main, pend, comparison_nbr);
	List combinedStray = std::move(stray);
	combinedStray.splice(combinedStray.end(), localStray);
	insertOddNStray(main, odd, combinedStray, comparison_nbr);
	flattenMain(c, main);
}

