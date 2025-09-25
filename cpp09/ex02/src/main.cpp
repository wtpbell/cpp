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
#include <iostream>
#include <string>
#include <algorithm>

bool	isAllDigits(std::string_view str)
{
	return (!str.empty() && std::all_of(str.begin(), str.end(), ::isdigit));
}

std::vector<int>	handleVector(int size, char** argv)
{
	std::vector<int>	v;
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
			v.emplace_back(value);
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
	for (int n : v)
		std::cout << n << std::endl;
	return (v);
}


int	main(int argc, char** argv)
{
	std::vector<int>	vect;

	if (argc < 2)
	{
		std::cerr << "Error [usage]: " << argv[0] << " <unsorted / sorted container>" << std::endl;
		return (1);
	}
	try
	{
		vect = handleVector(argc, argv);
	}
	catch (...)
	{
		return (1);
	}

	return (0);
}
