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

#ifndef DEBUG
# define DEBUG false
#endif

#include "MergeInsertionTracer.hpp"
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <utility>
#include <type_traits>
#include <iterator>

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
		using Vector = std::vector<int>;
		using List = std::list<int>;
		using VectorOfVectors = std::vector<Vector>;
		using ListOfLists = std::list<List>;
		using VectorPair = std::pair<Vector, Vector>;
		using ListPair = std::pair<List, List>;
		using VectorOfPairs = std::vector<VectorPair>;
		using ListOfPairs = std::list<ListPair>;

		PmergeMe() = default;
		PmergeMe(const PmergeMe& other) = default;
		PmergeMe& operator=(const PmergeMe& other) = default;
		~PmergeMe() = default;

		PmergeMe(PmergeMe&& other) noexcept = default;
		PmergeMe& operator=(PmergeMe&& other) noexcept = default;

		// Main sorting functions
		void sort(Vector& c, size_t pairLevel, MergeInsertionTracer& tracer);
		void sort(List& c, size_t pairLevel, MergeInsertionTracer& tracer);
	
		// Helper function for input validation
		static bool isAllDigits(std::string_view str);

		// In the public section of PmergeMe class
		template <typename Container>
		Container assignContainer(int size, char** argv);

		// In the private section of PmergeMe class
		template <typename Container>
		void mergeInsertionSort(Container& c, size_t pairLevel, MergeInsertionTracer& tracer);

		template <typename MainContainer, typename Sequence>
		size_t binaryInsert(MainContainer& main, const Sequence& seq, size_t& comparison_nbr);
	
	private:
		// Vector-specific functions
		VectorPair splitAndOrderChunk(Vector::const_iterator start, size_t pairLevel);
		VectorOfPairs makePairs(const Vector& v, size_t pairLevel, Vector& odd, Vector& stray, size_t& comparison_nbr);
		void flattenPairs(Vector& v, VectorOfPairs& pairs);
		void buildMainPend(const Vector& v, VectorOfVectors& main, VectorOfVectors& pend, Vector& stray, size_t pairLevel);
		void flattenMain(Vector& v, const VectorOfVectors& main);
	
		// List-specific functions
		ListPair splitAndOrderChunk(List::const_iterator start, size_t pairLevel);
		ListOfPairs makePairs(const List& c, size_t pairLevel, List& odd, List& stray, size_t& comparison_nbr);
		void flattenPairs(List& c, ListOfPairs& pairs);
		void buildMainPend(const List& c, ListOfLists& main, ListOfLists& pend, List& stray, size_t pairLevel);
		void flattenMain(List& c, const ListOfLists& main);
		// Common helper functions
		int jacobsthalNum(size_t n);
		std::vector<size_t> jacobsthalOrderFor(size_t m);
	
		// Template function for moving elements between containers
		template <typename Container, typename TargetContainer>
		void moveBatch(typename Container::const_iterator start,
					   typename Container::const_iterator end,
					   TargetContainer& target);
	
		// Template function for Jacobsthal insertion
		template <typename MainContainer, typename PendContainer>
		void jacobsthalInsert(MainContainer& main, PendContainer& pend, size_t& comparison_nbr);
	
		// Template function for inserting odd and stray elements
		template <typename MainContainer, typename OddContainer, typename StrayContainer>
		void insertOddNStray(MainContainer& main, const OddContainer& odd, const StrayContainer& stray, size_t& comparison_nbr);
};

#include "PmergeMe.tpp"

#endif // PMERGEME_HPP
