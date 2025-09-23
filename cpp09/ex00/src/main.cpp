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

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <optional>

#include "BitcoinExchange.hpp"



int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return (EXIT_FAILURE);
	}
	BitcoinExchange exchange;
	if (!exchange.loadData("data.csv"))
		return (1);
	std::cerr << GREEN << "Data loaded successfully." << RESET << std::endl;
	if (!exchange.exchangeData(argv[1]))
		return (1);
	return (0);
}
