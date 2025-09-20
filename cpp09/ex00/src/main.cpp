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
#include <fstream>
#include <optional>

std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
		return "";

	size_t last = str.find_last_not_of(" \t\r\n");
	return (str.substr(first, last - first + 1));
}


bool	BitcoinExchange::exchangeData(const std::filesystem::path& filePath)
{
	std::ifstream	inputFile(filePath);
	if (!inputFile.is_open())
	{
		std::cerr << RED << "Error: could not open file: " << filePath << RESET << std::endl;
		return (false);
	}

	std::string				line;
	std::string				dateString;
	std::string				valueString;
	chrono					ymd;
	std::optional<float>	value;
	float					rate;
	int						lineNum = 0;

	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		if (line.empty() || line[0] == '#' || line == "date | value")
			continue;
		lineNum++;
		dateString = trim(line.substr(0, line.find('|')));
		valueString = trim(line.substr(line.find('|') + 1));

		try
		{

			ymd = validateDate(dateString);
			if (!ymd.ok())
			{
				std::cout << "Error: bad input => " << dateString << std::endl;
				continue ;
			}
			value = stringToFloat(valueString);
			if (!value.has_value() || !validateValue(value.value()))
			{
				continue ;
			}
			rate = getExchangeRate(ymd);
			// if (rate == -1)
			// 	std::cerr << 
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		lineNum++;
	}
	inputFile.close();
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}

	BitcoinExchange	exchange;
	if (!exchange.loadData("data.csv"))
	{
		std::cout << RED << "Error: could not open data file." << RESET << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << GREEN << "Data loaded successfully." << RESET << std::endl;
	if (!exchange.exchangeData(argv[1]))
	{
		std::cout << RED << "Error: could not open input file." << RESET << std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}
