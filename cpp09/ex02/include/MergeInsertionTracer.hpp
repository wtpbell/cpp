/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MergeInsertionTracer.hpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 15:19:05 by bewong        #+#    #+#                 */
/*   Updated: 2025/10/07 16:14:37 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <string>

class MergeInsertionTracer
{
	public:
		bool debug;

		MergeInsertionTracer(bool enabled = true) : debug(enabled) {}

		// ---- Sequence printing ----
		template<typename T>
		void printSequence(const std::vector<T>& seq, bool newline = true) const
		{
			if (!debug)
				return;
			std::cout << "printSequence: [";
			for (size_t i = 0; i < seq.size(); ++i)
				std::cout << seq[i] << (i + 1 < seq.size() ? " " : "");
			std::cout << "]";
			if (newline)
				std::cout << std::endl;
		}

		// ---- High-level trace ----
		template<typename T>
		void before(const std::vector<T>& seq) const
		{
			if (!debug)
				return;
			std::cout << "Before: ";
			printSequence(seq);
			std::cout << std::endl;
		}

		template<typename T>
		void after(const std::vector<T>& seq) const
		{
			if (!debug)
				return;
			std::cout << "After: ";
			printSequence(seq);
			std::cout << std::endl;
		}

		template<typename T>
		void pair(size_t index, const std::vector<T>& seq1, const std::vector<T>& seq2) const
		{
			if (!debug)
				return;
			std::cout << "Pair " << index << ": ";
			printSequence(seq1, false);
			std::cout << " , ";
			printSequence(seq2);
		}

		template<typename T>
		void buildMainPend(size_t pairLevel, const std::vector<T>& seq) const
		{
			if (!debug)
				return;
			std::cout << "\nbuildMainPend called with pairLevel=" << pairLevel << ", sequence: ";
			printSequence(seq);
		}

		template<typename T>
		void showMainPend(const std::vector<std::vector<T>>& main,
						const std::vector<std::vector<T>>& pend) const
		{
			if (!debug)
				return;
			std::cout << "\nAfter buildMainPend:\n";
			std::cout << "Main (" << main.size() << "):\n";
			for (size_t i = 0; i < main.size(); ++i)
			{
				std::cout << "  [" << i << "] ";
				printSequence(main[i]);
			}
			std::cout << "Pend (" << pend.size() << "):\n";
			for (size_t i = 0; i < pend.size(); ++i)
			{
				std::cout << "  [" << i << "] ";
				printSequence(pend[i]);
			}
		}

		void	originalInput(std::vector<int> vect)
		{
			std::cout << "\nInput: ";
			for (auto n : vect) std::cout << n << " ";
				std::cout << std::endl;
		}

		void jacobsthalOrder(const std::vector<size_t>& order) const
		{
			if (!debug) 
				return;
			std::cout << "Jacobsthal order: ";
			for (size_t i = 0; i < order.size(); ++i)
				std::cout << order[i] << (i + 1 < order.size() ? " " : "");
			std::cout << std::endl;
		}

		void insertStep(size_t idx, int value, size_t pos)
		{
			if (!debug)
				return;
			std::cout << "Insert element from pend[" << idx << "] value=" << value
					<< " at main index=" << pos << std::endl;
		}

		void insertStepStray(int value, size_t pos)
		{
			if (!debug)
				return;
			std::cout << "Insert stray element value=" << value
					<< " at main index=" << pos << std::endl;
		}

};
