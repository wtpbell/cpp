/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:08:04 by bewong            #+#    #+#             */
/*   Updated: 2025/09/17 10:08:04 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <regex>

float	BitcoinExchange::getExchangeRate(const chrono& date) const
{
	auto it = exchangeData_.lower_bound(date);
	if (it == exchangeData_.begin() && it->first != date)
		return (-1);
	if (it == exchangeData_.end() && it->first != date)
		--it;
	return (it->second);
}

chrono	BitcoinExchange::validateDate(const std::string& date)
{
	chrono	ymd;
	int		year;
	int		month;
	int		day;

	if (date.empty() || std::count(date.begin(), date.end(), '-') != 2)
		return {};

	try
	{
		year = std::stoi(date.substr(0, date.find('-')));
		month = std::stoi(date.substr(date.find('-') + 1, date.rfind('-')));
		day = std::stoi(date.substr(date.rfind('-') + 1));
		ymd = chrono{std::chrono::year{ year },
				std::chrono::month{ static_cast<unsigned int>(month) },
				std::chrono::day{ static_cast<unsigned int>(day) }};
		return (ymd);
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error validateDate: " << e.what() << RESET << std::endl;
		return {};
	}
}
// optional can either contain a value or nth at all. 
std::optional<float>	BitcoinExchange::stringToFloat(const std::string& valueString)
{
	auto trimString = valueString;

	trimString.erase(0, trimString.find_first_not_of(' '));
	trimString.erase(trimString.find_last_not_of(' ') + 1);

	if (trimString.empty())
	{
		std::cerr << RED << "Error stringToFloat: empty string" << RESET << std::endl;
		return (std::nullopt);
	}
	static const std::regex floatRegex(R"(^[+-]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?$)");

	if (!std::regex_match(trimString, floatRegex))
	{
		std::cerr << RED << "Error: it is not a valid float" << RESET << std::endl;
		return (std::nullopt);
	}

	try
	{
		float	number = std::stof(trimString);
		return (number);
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error: could not convert to number: " << trimString
					<< " (" << e.what() << ")" << RESET << std::endl;
		return (std::nullopt);
	}
}

bool	BitcoinExchange::loadData(const std::filesystem::path& filePath)
{
	std::ifstream	dataFile(filePath);
	if (!dataFile.is_open())
	{
		std::cerr << RED << "Error: could not open file: " << filePath << RESET << std::endl;
		return (false);
	}

	std::string				line;
	chrono					ymd;
	std::string				dateString;
	std::string				valueString;
	std::optional<float>	value;

	std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		if (line.empty() || line[0] == '#' || line == "date,exchange_rate")
			continue ;
		dateString = line.substr(0, line.find(','));
		valueString = line.substr(line.find(',') + 1);
		try
		{
			ymd = validateDate(dateString);
			if (!ymd.ok() || ymd < minDate_ || ymd > maxDate_)
			{
				std::cerr << RED << "Error loadData: invalid date on line: " 
							<< line << " with date: " << dateString << RESET << std::endl;
				return (false);
			}
			value = stringToFloat(valueString);
			if (!value.has_value())
			{
				std::cerr << RED << "Error loadData: invalid value on line: " << line << " with value: " << valueString << RESET << std::endl;
				return (false);
			}
			exchangeData_[ymd] = value.value();
		}
		catch (std::exception& e)
		{
			std::cerr << RED << "Error: bad input => " << line << " (" << e.what() << ")" << RESET << std::endl;
			return (false);
		}
	}
	dataFile.close();
	return (true);
}

void	BitcoinExchange::logData(void)
{
	
}
