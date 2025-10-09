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
#include "PmergeMe.tpp"
#include "MergeInsertionTracer.hpp"
#include <iostream>
#include <string>
#include <algorithm>

// https://medium.com/@ryan_forrester_/binary-sort-in-c-complete-guide-0afcb29c9aec

int	main(int argc, char** argv)
{
	PmergeMe			sorter;
	MergeInsertionTracer tracer(DEBUG);
	size_t				pairLevel = 1;

	if (argc < 2)
	{
		std::cerr << "Error [usage]: " << argv[0] << " <positive integer sequence>" << std::endl;
		return (1);
	}
	try
	{
		auto vect = sorter.assignContainer<PmergeMe::Vector>(argc - 1, argv + 1);
		auto list = sorter.assignContainer<PmergeMe::List>(argc - 1, argv + 1);
		logTime(sorter, vect, list, pairLevel, tracer);
	}
	catch (...)
	{
		return (1);
	}
	return (0);
}
