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
#include <optional>

std::chrono::year_month_day	BitcoinExchange::validateDate(const std::string& date)
{
	std::chrono::year_month_day	ymd;
	int							year;
	int							month;
	int							day;

	if (date.empty() || std::count(date.begin(), date.end(), '-') != 2)
		return {};

	try
	{
		year = std::stoi(date.substr(0, date.find('-')));
		month = std::stoi(date.substr(date.find('-') + 1, date.rfind('-')));
		day = std::stoi(date.substr(date.rfind('-') + 1));
		ymd = std::chrono::year_month_day{std::chrono::year{ year },
				std::chrono::month{ month },
				std::chrono::day{ day }};
		return (ymd);
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error validateDate: " << e.what() << RESET << std::endl;
		return {};
	}
}
// optional can either contain a value or nth at all. 
std::optional<float> stringToFloat(const std::string& valueString)
{
	auto trimString = valueString;

	trimString.erase(0, trimString.find_first_not_of(' '));
	trimString.erase(trimString.find_last_not_of(' ') + 1);

	if (trimString.empty())
	{
		std::cerr << RED << "Error stringToFloat: empty string" << RESET << std::endl;
		return (std::nullopt);
	}

	static const std::regex	floatRegex(R"(^[+]?\d*\.?\d+([eE][+-]?\d+)?$)");
	if (!std::regex_match(trimString, floatRegex))
	{
		std::cerr << RED << "Error stringToFloat: " << trimString << " is not a valid float" << RESET << std::endl;
		return (std::nullopt);
	}

	try
	{
		return (std::stof(trimString));
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

	std::string					line;
	std::chrono::year_month_day	ymd;
	std::string					dateString;
	std::string					valueString;
	std::optional<float>		value;

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
				std::cerr << RED << "Error loadData: invalid date on line: " << line << " with date: " << dateString << RESET << std::endl;
				return (false);
			}
			value = stringToFloat(valueString);
			if (!value.has_value() || !validateValue(value.value()))
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
