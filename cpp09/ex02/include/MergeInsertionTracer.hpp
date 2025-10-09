/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertionTracer.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:19:05 by bewong            #+#    #+#             */
/*   Updated: 2025/10/09 20:57:44 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <list>

class MergeInsertionTracer
{
	public:
		bool debug;

		explicit MergeInsertionTracer(bool enabled = true) : debug(enabled) {}

		template<typename T>
		void printSequence(const std::vector<T>& seq, const std::string& prefix = "", bool newline = true) const
		{
			if (!debug) return;
			if (!prefix.empty())
				std::cout << prefix << " ";
			std::cout << "(size: " << seq.size() << "): [";
			for (size_t i = 0; i < seq.size(); ++i)
			{
				std::cout << seq[i];
				if (i + 1 < seq.size())
					std::cout << " ";
			}
			std::cout << "]";
			if (newline)
				std::cout << std::endl;
		}

		template<typename T>
		void levelStart(size_t pairLevel, const std::vector<T>& seq) const
		{
			if (!debug) return;
			std::cout << "\n=== Level " << pairLevel << " ===" << std::endl;
			printSequence(seq, "Current sequence", true);
		}

		void levelFinal(const std::vector<int>& seq) const
		{
			if (!debug) return;
			std::cout << "\n=== Final sequence at base case ===" << std::endl;
			printSequence(seq, "Sequence");
			std::cout << "Size: " << seq.size() << " elements\n";
		}

		void levelOddStray(const std::vector<int>& odd, const std::vector<int>& stray) const
		{
			if (!debug) return;
			if (!odd.empty())
				printSequence(odd, "Found odd elements");
			else
				std::cout << "No odd elements found at this level\n";

			if (!stray.empty())
				printSequence(stray, "Found stray elements");
			else
				std::cout << "No stray elements found at this level\n";
		}

		void levelPairs(const std::vector<std::pair<std::vector<int>, std::vector<int>>>& pairs) const
		{
			if (!debug) return;
			std::cout << "\nPairs:\n";
			for (size_t i = 0; i < pairs.size(); ++i)
			{
				std::cout << "Pair " << i << ": ";
				printSequence(pairs[i].first, "", false);
				std::cout << " , ";
				printSequence(pairs[i].second);
			}
		}

		void mainPendStart(size_t pairLevel, const std::vector<int>& c) const
		{
			if (!debug) return;
			std::cout << "\n=== Building Main/Pend ===\n";
			std::cout << "Pair Level: " << pairLevel << "\n";
			printSequence(c, "Current sequence");
		}

		void showMainPend(const std::vector<std::vector<int>>& main,
						const std::vector<std::vector<int>>& pend) const
		{
			if (!debug) return;
			std::cout << "\nMain (" << main.size() << "):\n";
			for (size_t i = 0; i < main.size(); ++i)
			{
				std::cout << "  [" << i << "] ";
				printSequence(main[i], "", false);
				std::cout << std::endl;
			}
			std::cout << "Pend (" << pend.size() << "):\n";
			for (size_t i = 0; i < pend.size(); ++i)
			{
				std::cout << "  [" << i << "] ";
				printSequence(pend[i], "", false);
				std::cout << std::endl;
			}
		}

		void jacobsthalOrder(const std::vector<size_t>& order) const
		{
			if (!debug) return;
			std::cout << "Jacobsthal order: ";
			for (size_t i = 0; i < order.size(); ++i)
				std::cout << order[i] << (i + 1 < order.size() ? " " : "");
			std::cout << std::endl;
		}

		void insertingOdd(const std::vector<int>& odd) const
		{
			if (!debug) return;
			printSequence(odd, "Inserting remaining odd elements");
		}

		void finalAfter(const std::vector<int>& seq) const
		{
			if (!debug) return;
			std::cout << "After: ";
			printSequence(seq);
		}
};

