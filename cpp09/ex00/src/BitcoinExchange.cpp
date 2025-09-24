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

#include <cmath>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <ctime>

#include "BitcoinExchange.hpp"
#include <chrono>

bool	BitcoinExchange::validateValue(double value)
{
	if (value < 0)
	{
		std::cerr << YELLOW << "Error: not a positive number." << RESET
		<< std::endl;
	}
	else if (value > 1000)
		std::cerr << CYAN << "Error: too large a number." << RESET << std::endl;
	return (value >= 0 && value <= 1000);
}

void	BitcoinExchange::trim(std::string& str)
{
	const char* whitespace = " \t\r\n\f\v";
	size_t start = str.find_first_not_of(whitespace);
	size_t end = str.find_last_not_of(whitespace);

	if (start == std::string::npos)
	{
		str.clear();
		return ;
	}
	if (end != std::string::npos && end + 1 < str.length())
		str.erase(end + 1);
	if (start > 0)
		str.erase(0, start);
}

void	BitcoinExchange::logData(const chrono& ymd, double value,
								double rate) const
{
	std::cout << static_cast<int>(ymd.year()) << "-" << std::setw(2)
				<< std::setfill('0') << static_cast<unsigned>(ymd.month()) << "-"
				<< std::setw(2) << std::setfill('0')
				<< static_cast<unsigned>(ymd.day()) << " => " << value << " = ";

	double				result = value * rate;
	std::ostringstream	oss;

	result = std::round(result * 100.0) / 100.0;
	oss << result;
	std::cout << oss.str();
	std::cout << std::endl;
}

std::optional<double>	BitcoinExchange::getExchangeRate(const chrono& date) const
{
	auto it = exchangeData_.lower_bound(date);
	if (it != exchangeData_.end() && it->first == date)
		return (it->second);
	if (it == exchangeData_.begin())
		return (std::nullopt);
	--it;
	return (it->second);
}

chrono	BitcoinExchange::validateDate(const std::string& date)
{
	if (date.empty())
		return {};

	chrono				ymd;
	std::tm				tm{};
	std::stringstream	ss(date);

	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail() || !ss.eof())
		return {};
	ymd = chrono{std::chrono::year{ 1900 + tm.tm_year },
					std::chrono::month{ static_cast<unsigned int>(tm.tm_mon + 1) },
					std::chrono::day{ static_cast<unsigned int>(tm.tm_mday)} };
	return (ymd);
}

std::optional<double>	BitcoinExchange::stringToDouble(const std::string& valueString)
{
	auto trimString = valueString;

	trim(trimString);
	static const std::regex floatRegex(
		R"(^[+-]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?$)");

	if (!std::regex_match(trimString, floatRegex))
		return (std::nullopt);
	try
	{
		return (std::stod(trimString));
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
	std::string		line;

	if (!dataFile.is_open())
	{
		std::cerr << RED << "Error: could not open file" << RESET << std::endl;
		return (false);
	}

	if (!std::getline(dataFile, line))
	{
		std::cerr << RED << "Error: empty file" << RESET << std::endl;
		return (false);
	}
	while (std::getline(dataFile, line))
	{
		trim(line);
		if (line.empty() || line[0] == '#')
			continue;
		processDataFileLine(line);
	}
	dataFile.close();
	return (true);
}

void	BitcoinExchange::processDataFileLine(const std::string& line)
{
	chrono					ymd;
	std::string				dateString;
	std::string				valueString;
	std::optional<double>	value;

	dateString = line.substr(0, line.find(','));
	valueString = line.substr(line.find(',') + 1);
	ymd = validateDate(dateString);
	if (!ymd.ok() || ymd < minDate_ || ymd > maxDate_)
	{
		std::cerr << RED << "Error loadData: invalid date on line: " << line
					<< " with date: " << dateString << RESET << std::endl;
		return;
	}
	value = stringToDouble(valueString);
	if (!value.has_value())
	{
		std::cerr << RED
					<< "Error loadData: invalid value on line: " << line
					<< " with value: " << valueString << RESET << std::endl;
		return ;
	}
	exchangeData_[ymd] = value.value();
}

bool	BitcoinExchange::exchangeData(const std::filesystem::path& filePath)
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
	while (std::getline(inputFile, line))
	{
		trim(line);
		if (line.empty() || line[0] == '#')
			continue;
		processInputFileLine(line);
	}
	inputFile.close();
	return (true);
}

void	BitcoinExchange::processInputFileLine(const std::string& line)
{
	std::string				dateString;
	std::string				valueString;
	chrono					ymd;
	std::optional<double>	value;
	std::optional<double>	rate;
	size_t					separatorPos;

	separatorPos = line.find('|');
	if (separatorPos == std::string::npos)
	{
		std::cerr << RED << "Error: bad input (missing '|' separator) => " << line << RESET << std::endl;
		return ;
	}
	dateString = line.substr(0, separatorPos);
	valueString = line.substr(separatorPos + 1);
	trim(dateString);
	trim(valueString);
	
	if (dateString.empty() || valueString.empty())
	{
		std::cerr << RED << "Error: bad input (empty date or value) => " << line << RESET << std::endl;
		return ;
	}

	ymd = validateDate(dateString);
	value = stringToDouble(valueString);

	if (!ymd.ok() || !value.has_value())
	{
		std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
		return ;
	}
	if (!validateValue(value.value()))
		return ;

	rate = getExchangeRate(ymd);
	if (!rate.has_value())
	{
		std::cerr << "Error: out of range => " << dateString << std::endl;
		return;
	}
	logData(ymd, value.value(), rate.value());
}
