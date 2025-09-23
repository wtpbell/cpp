/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:08:01 by bewong            #+#    #+#             */
/*   Updated: 2025/09/17 10:08:01 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <chrono>
#include <ctime>
#include <filesystem>
#include <iostream>
#include <map>
#include <optional>

#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define BOLD "\033[1m"
#define UNDER "\033[4m"
#define RESET "\033[0m"
#define RED "\033[0;91m"
#define CYAN "\033[0;96m"
#define MAGENTA "\033[0;95m"
#define ORANGE "\033[38;5;208m"

using chrono = std::chrono::year_month_day;

class BitcoinExchange
{
public:
	BitcoinExchange() = default;
	BitcoinExchange(const BitcoinExchange& other) = default;
	BitcoinExchange& operator=(const BitcoinExchange& other) = delete;
	~BitcoinExchange() = default;

	BitcoinExchange(BitcoinExchange&& other) noexcept = default;
	BitcoinExchange& operator=(BitcoinExchange&& other) noexcept = delete;

	bool exchangeData(const std::filesystem::path& filePath);
	void processInputFileLine(const std::string& line);
	bool loadData(const std::filesystem::path& filePath);
	void processDataFileLine(const std::string& line);
	chrono validateDate(const std::string& date);
	std::optional<double> stringToDouble(const std::string& valueString);
	double getExchangeRate(const chrono& date) const;
	template <typename T>
	constexpr static bool validateValue(T value);
	static std::string_view trim(std::string_view str);

private:
	void logData(const chrono& ymd, double value, double rate) const;
	const chrono minDate_ = chrono(std::chrono::year{2009},
								std::chrono::month{1}, std::chrono::day{2});
	const chrono maxDate_ =
	    std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
	std::map<chrono, double> exchangeData_;
};

template <typename T>
constexpr bool BitcoinExchange::validateValue(T value)
{
	static_assert(std::is_same_v<T, float> || std::is_same_v<T, double> ||
	                  std::is_same_v<T, int>,
	              "Invalid type");
	if (value < 0)
	{
		std::cerr << YELLOW << "Error: not a positive number." << RESET
		<< std::endl;
	}
	else if (value > 1000)
		std::cerr << CYAN << "Error: too large a number." << RESET << std::endl;
	return (value >= 0 && value <= 1000);
}
#endif  // BITCOINEXCHANGE_HPP
