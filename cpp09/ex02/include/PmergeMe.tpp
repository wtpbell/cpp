/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:55:53 by bewong            #+#    #+#             */
/*   Updated: 2025/10/08 09:55:53 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_TPP
# define PMERGE_ME_TPP

#include "PmergeMe.hpp"
#include <iostream>
#include <set>
#include <chrono>
#include <iomanip>

using CHRONO = std::chrono::high_resolution_clock ;

template <typename Container>
Container PmergeMe::assignContainer(int size, char** argv)
{
	Container		c;
	int				value;
	std::set<int>	seen;

	if constexpr (requires { c.reserve(size); })
		c.reserve(size);

	for (int i = 0; i < size; i++)
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
			c.push_back(std::move(value));
		}
		catch (std::invalid_argument const& e)
		{
			std::cerr << "Argument: " << argv[i] << e.what() << std::endl;
			throw ;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error processing argument '" << argv[i] << "': " << e.what() << std::endl;
			throw ;
		}
	}
	return (c);
}

template <typename Container, typename TargetContainer>
void	PmergeMe::moveBatch(typename Container::const_iterator start,
							typename Container::const_iterator end,
							TargetContainer& target)
{
	if (start == end)
		return;
	
	if constexpr (std::is_same_v<Container, TargetContainer>)
	{
		if constexpr (std::is_same_v<Container, Vector>)
		{
			target.insert(target.end(), 
						std::make_move_iterator(start),
						std::make_move_iterator(end));
		} 
		else 
			target.insert(target.end(), start, end);
	} 
	else
		target.insert(target.end(), start, end);
}

template <typename Container>
void	PmergeMe::mergeInsertionSort(Container& c, size_t pairLevel, MergeInsertionTracer& tracer)
{
	if constexpr (std::is_same_v<Container, Vector>)
		sort(c, pairLevel, tracer);
	else if constexpr (std::is_same_v<Container, List>)
		sort(c, pairLevel, tracer);
	else
		static_assert(std::is_same_v<Container, Vector> || std::is_same_v<Container, List>,
						"Only std::vector<int> and std::list<int> are supported");
}

template <typename MainContainer, typename Sequence>
size_t	PmergeMe::binaryInsert(MainContainer& main, const Sequence& seq,
						size_t& comparison_nbr)
{
	if (seq.empty())
		return (0);

	int		target = seq.back();
	size_t	left = 0;
	size_t	right = main.size();

	while (left < right)
	{
		size_t	mid = left + (right - left) / 2;
		comparison_nbr++;
		auto	it = std::next(main.begin(), mid);
		if (it->back() < target)
			left = mid + 1;
		else
			right = mid;
	}
	main.insert(std::next(main.begin(), left), seq);
	return (left);
}

template <typename MainContainer, typename PendContainer>
void	PmergeMe::jacobsthalInsert(MainContainer& main, PendContainer& pend,
							size_t& comparison_nbr)
{
	if (pend.empty())
		return ;

	std::vector<bool>		inserted(pend.size(), false);
	std::vector<size_t>		order = jacobsthalOrderFor(pend.size());

	for (size_t seqIdx : order)
	{
		if (seqIdx >= pend.size())
			continue ;

		auto				it = pend.begin();
		std::advance(it, seqIdx);
		binaryInsert(main, *it, comparison_nbr);
		inserted[seqIdx] = true;
	}

	for (size_t i = 0; i < pend.size(); ++i)
	{
		if (!inserted[i])
		{
			auto it = pend.begin();
			std::advance(it, i);
			binaryInsert(main, *it, comparison_nbr);
		}
	}
	pend.clear();
}

template <typename MainContainer, typename OddContainer, typename StrayContainer>
void PmergeMe::insertOddNStray(MainContainer& main, const OddContainer& odd,
							const StrayContainer& stray, size_t& comparison_nbr)
{
	// Base case: main holds plain ints (last recursion level)
	if constexpr (std::is_same_v<typename MainContainer::value_type, int>)
	{
		for (int val : odd)
		{
			if constexpr (std::is_same_v<MainContainer, Vector>)
				binaryInsert(main, Vector{val}, comparison_nbr);
			else
				binaryInsert(main, List{val}, comparison_nbr);
		}
		for (int val : stray)
		{
			if constexpr (std::is_same_v<MainContainer, Vector>)
				binaryInsert(main, Vector{val}, comparison_nbr);
			else
				binaryInsert(main, List{val}, comparison_nbr);
		}
		return;
	}

	using SubSeq = typename MainContainer::value_type;

	if (!odd.empty())
	{
		SubSeq oddSeq(odd.begin(), odd.end());
		binaryInsert(main, oddSeq, comparison_nbr);
	}
	if (!stray.empty())
	{
		SubSeq straySeq(stray.begin(), stray.end());
		main.push_back(std::move(straySeq));
	}
}


template <typename Container>
void	logContainer(const std::string& prefix, const Container& c)
{
	std::cout << prefix << ": ";
	if (c.empty())
		std::cout << " (empty)";
	else
	{
		for (auto it = c.begin(); it != c.end(); ++it)
		{
			if (it != c.begin())
				std::cout << " ";
			std::cout << *it;
		}
	}
	std::cout << std::endl;
}

template <typename ContainerV, typename ContainerL>
void logTime(PmergeMe& sorter, ContainerV& containerV,
			 ContainerL& containerL, size_t pairLevel, MergeInsertionTracer& tracer)
{
	logContainer("Before", containerV);

	auto startV = std::chrono::high_resolution_clock::now();
	sorter.mergeInsertionSort(containerV, pairLevel, tracer);
	auto endV = std::chrono::high_resolution_clock::now();
	float vectorTimeMs = std::chrono::duration<float, std::milli>(endV - startV).count();

	auto startL = std::chrono::high_resolution_clock::now();
	sorter.mergeInsertionSort(containerL, pairLevel, tracer);
	auto endL = std::chrono::high_resolution_clock::now();
	float listTimeMs = std::chrono::duration<float, std::milli>(endL - startL).count();

	logContainer("After", containerV);

	std::cout << std::fixed << std::setprecision(5)
			  << "Time to process a range of " << containerV.size()
			  << " elements with std::vector: " << vectorTimeMs << " ms\n"
			  << "Time to process a range of " << containerL.size()
			  << " elements with std::list: " << listTimeMs << " ms\n";
}


#endif // PMERGE_ME_TPP
