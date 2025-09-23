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

bool BitcoinExchange::validateValue(double value)
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

std::string_view BitcoinExchange::trim(std::string_view str)
{
	const char* whitespace = " \t\r\n\f\v";
	auto start = str.find_first_not_of(whitespace);
	auto end = str.find_last_not_of(whitespace);

	if (start == std::string_view::npos)
		return ("");
	return str.substr(start, end - start + 1);
}
void BitcoinExchange::logData(const chrono& ymd, double value,
								double rate) const
{
	std::cout << static_cast<int>(ymd.year()) << "-" << std::setw(2)
				<< std::setfill('0') << static_cast<unsigned>(ymd.month()) << "-"
				<< std::setw(2) << std::setfill('0')
				<< static_cast<unsigned>(ymd.day()) << " => " << value << " = ";

	double result = value * rate;

	if (result == std::floor(result))
		std::cout << static_cast<int>(result);
	else
	{
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(2) << result;
		std::string resultStr = oss.str();
		resultStr.erase(resultStr.find_last_not_of('0') + 1, std::string::npos);
		std::cout << resultStr;
	}
	std::cout << std::endl;
}

double BitcoinExchange::getExchangeRate(const chrono& date) const
{
	auto it = exchangeData_.lower_bound(date);
	if (it != exchangeData_.end() && it->first == date)
		return (it->second);
	if (it == exchangeData_.begin())
		return (-1);
	--it;
	return (it->second);
}

chrono BitcoinExchange::validateDate(const std::string& date)
{
	if (date.empty() || std::count(date.begin(), date.end(), '-') != 2)
		return {};

	chrono				ymd;
	std::tm				tm{};
	std::stringstream	ss(date);

	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail())
		return {};
	try
	{
		ymd = chrono{std::chrono::year{ 1900 + tm.tm_year },
						std::chrono::month{ static_cast<unsigned int>(tm.tm_mon + 1) },
						std::chrono::day{ static_cast<unsigned int>(tm.tm_mday)} };
		return (ymd);
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error validateDate: " << e.what() << RESET
					<< std::endl;
		return {};
	}
}

std::optional<double> BitcoinExchange::stringToDouble(const std::string& valueString)
{
	auto trimString = valueString;

	trimString.erase(0, trimString.find_first_not_of(' '));
	trimString.erase(trimString.find_last_not_of(' ') + 1);

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

bool BitcoinExchange::loadData(const std::filesystem::path& filePath)
{
	std::ifstream dataFile(filePath);
	std::string line;

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
	line = trim(line);
	if (line != "date,exchange_rate")
	{
		std::cerr << RED << "Error: invalid csv header" << RESET << std::endl;
		return (false);
	}
	while (std::getline(dataFile, line))
	{
		if (line.empty() || line[0] == '#' || line == "date,exchange_rate")
			continue;
		processDataFileLine(line);
	}
	dataFile.close();
	return (true);
}

void BitcoinExchange::processDataFileLine(const std::string& line)
{
	chrono ymd;
	std::string dateString;
	std::string valueString;
	std::optional<double> value;

	dateString = line.substr(0, line.find(','));
	valueString = line.substr(line.find(',') + 1);
	try
	{
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
	catch (std::exception& e)
	{
		std::cerr << RED << "Error: bad input => " << line << " (" << e.what()
					<< ")" << RESET << std::endl;
		return;
	}
}
