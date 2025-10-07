/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:14:42 by bewong            #+#    #+#             */
/*   Updated: 2025/09/24 19:14:42 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include "MergeInsertionTracer.hpp"
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using Sequence = std::vector<int>;
using Pair = std::pair<Sequence, Sequence>;

struct PairingInfo
{
	size_t	pairChunk;
	bool	isOdd;
	size_t	offset;
	size_t	end;

	PairingInfo(size_t totalSize, size_t pairLevel)
	{
		pairChunk = totalSize / pairLevel;
		isOdd = (pairChunk % 2 == 1);
		offset = 2 * pairLevel;
		end = pairLevel * pairChunk - (isOdd ? pairLevel : 0);
	}
};

class	PmergeMe
{
	public:
		PmergeMe() = default;
		PmergeMe(const PmergeMe& other) = default;
		PmergeMe& operator=(const PmergeMe& other) = default;
		~PmergeMe() = default;

		PmergeMe(PmergeMe&& other) noexcept = default;
		PmergeMe& operator=(PmergeMe&& other) noexcept = default;

		int					jacobsthalNum(size_t n);
		bool				isAllDigits(std::string_view str);
		Sequence			handleVector(int size, char** argv);
		std::vector<size_t>	jacobsthalOrderFor(size_t m);
		Pair				splitAndOrderChunk(Sequence::const_iterator start, size_t pairLevel);
		void				moveBatch(const Sequence::const_iterator start, const Sequence::const_iterator end,
									Sequence& target);
		void				moveBatch(const Sequence::const_iterator start,
									const Sequence::const_iterator end,
									std::vector<Sequence>& target);
		std::vector<Pair>	makePairs(const Sequence& v, size_t pairLevel,
									Sequence& odd, Sequence& stray, size_t& comparison_nbr);
		void				flattenPairs(Sequence& v, std::vector<Pair>& pairs);
		void				buildMainPend(const Sequence& v, std::vector<Sequence>& main,
									std::vector<Sequence>& pend, Sequence& stray, size_t pairLevel);
		void				jacobsthalInsert(std::vector<Sequence>& main, std::vector<Sequence>& pend,
									size_t& comparison_nbr);
		void				mergeInsertionSort(Sequence& c, size_t pairLevel, MergeInsertionTracer& tracer);
		void				flattenMain(Sequence& v, const std::vector<Sequence>& main);
		void				insertOddNStray(std::vector<Sequence>& main, const Sequence& odd,
									const Sequence& stray, size_t& comparison_nbr);


	private:
		
};

#endif // PMERGEME_HPP
