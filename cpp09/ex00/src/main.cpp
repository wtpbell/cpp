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

bool BitcoinExchange::exchangeData(const std::filesystem::path& filePath)
{
	std::ifstream	inputFile(filePath);
	std::string		line;

	if (!inputFile.is_open())
	{
		std::cerr << RED << "Error: could not open file" << RESET << std::endl;
		return (false);
	}

	if (!std::getline(inputFile, line))
	{
		std::cerr << RED << "Error: empty file" << RESET << std::endl;
		return (false);
	}
	line = trim(line);
	if (line != "date | value")
	{
		std::cerr << RED << "Error: invalid .txt header" << RESET << std::endl;
		return (false);
	}
	while (std::getline(inputFile, line))
	{
		line = trim(line);
		if (line.empty() || line[0] == '#' || line == "date | value")
			continue;
		processInputFileLine(line);
	}
	inputFile.close();
	return (true);
}

void BitcoinExchange::processInputFileLine(const std::string& line)
{
	std::string				dateString;
	std::string				valueString;
	chrono					ymd;
	std::optional<double>	value;
	double					rate;

	dateString = trim(line.substr(0, line.find('|')));
	valueString = trim(line.substr(line.find('|') + 1));
	ymd = validateDate(dateString);
	value = stringToDouble(valueString);

	if (valueString.empty() || !ymd.ok() || !value.has_value())
	{
		std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
		return ;
	}
	if (!validateValue(value.value()))
		return ;

	rate = getExchangeRate(ymd);
	if (rate == -1)
	{
		std::cerr << "Error: out of range => " << dateString << std::endl;
		return;
	}
	logData(ymd, value.value(), rate);
}

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
