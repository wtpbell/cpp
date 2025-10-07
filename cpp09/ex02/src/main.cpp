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
#include "MergeInsertionTracer.hpp"
#include <iostream>
#include <string>
#include <algorithm>

// https://medium.com/@ryan_forrester_/binary-sort-in-c-complete-guide-0afcb29c9aec

int	main(int argc, char** argv)
{
	std::vector<int>	vect;
	PmergeMe			mergeMe;
	MergeInsertionTracer tracer(true);
	size_t				pairLevel = 1;

	if (argc < 2)
	{
		std::cerr << "Error [usage]: " << argv[0] << " <unsorted / sorted container>" << std::endl;
		return (1);
	}
	try
	{
		vect = mergeMe.handleVector(argc, argv);
		if (is_sorted(vect.begin(), vect.end()))
			throw std::runtime_error("The input is already sorted.");
	}
	catch (std::runtime_error const& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	catch (...)
	{
		return (1);
	}
	
	mergeMe.mergeInsertionSort(vect, pairLevel, tracer);
	return (0);
}
