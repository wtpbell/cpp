/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:08:07 by bewong            #+#    #+#             */
/*   Updated: 2025/09/17 10:08:07 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

void	exchangeData(const std::filesystem::path& filePath, const BitcoinExchange& exchange)
{
	
}

int	main(int argc, char **argv)
{
	if (argv != 2)
	{
		std::cout << "Usage: ./bitcoin [file]" << std::endl;
		return (EXIT_FAILURE);
	}

	BitcoinExchange	exchange;
	if (!exchange.loadData("data.csv"))
	{
		std::cout << RED << "Error: could not open file." << RESET << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << GREEN << "Data loaded successfully." << RESET << std::endl;
	exchangeData(argv[1], exchange);
	return (0);
}
