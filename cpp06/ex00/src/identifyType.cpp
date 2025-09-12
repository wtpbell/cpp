/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifyType.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:35:22 by bewong            #+#    #+#             */
/*   Updated: 2025/09/05 19:35:22 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <regex>

#include "ScalarConverter.hpp"

static bool isPseudo(const std::string& literal, size_t len)
{
	if (len < 3 || len > 5)
		return (false);
	return (literal == PSEUDO_NAN || literal == PSEUDO_NAN_PLUS 
		|| literal == PSEUDO_NANF || literal == PSEUDO_NANF_PLUS
		|| literal == PSEUDO_INF || literal == PSEUDO_INF_PLUS
		|| literal == PSEUDO_INF_MIN || literal == PSEUDO_INFF 
		|| literal == PSEUDO_INFF_PLUS || literal == PSEUDO_INFF_MIN);
}

static bool isChar(const std::string& literal, size_t len)
{
	if (len == 1 && !std::isdigit(literal[0]))
		return (true);
	if (len == 3 && literal[0] == '\'' && literal[2] == '\'')
		return (true);
	return (false);
}

static bool isInt(const std::string& literal, size_t len)
{
	size_t i = 0;
	if (literal[i] == '-' || literal[i] == '+')
	{
		if (len == 1)
			return (false);
		i++;
	}
	for (; i < len; i++)
		if (!std::isdigit(literal[i]))
			return (false);
	return (true);
}

// ^: start, $: end, [+-]: optional sign, ?: non-capturing group, d: digit, 
// \d+\.\d*: digit(s) a dot, more digits, \.\d+: a dot follow by one or more digits \d+: one or more digits
// [eE]: e or E, [+-]?: optional sign, \d+: one or more digits, f$: end with f
static bool isFloat(const std::string& literal)
{
	static const std::regex floatRegex(R"(^[+-]?(?:\d+\.\d*|\.\d+|\d+)(?:[eE][+-]?\d+)?f$)");
	return std::regex_match(literal, floatRegex);
}

static bool isDouble(const std::string& literal)
{
	static const std::regex doubleRegex(R"(^[+-]?(?:\d+\.\d*|\.\d+|\d+)(?:[eE][+-]?\d+)?$)");
	return std::regex_match(literal, doubleRegex);
}

Type ScalarConverter::identifyType(const std::string& literal)
{
	size_t len = literal.length();

	if (literal.empty())
		return (Type::UNKNOWN);
	if (isPseudo(literal, len))
		return (Type::PSEUDO);
	if (isChar(literal, len))
		return (Type::CHAR);
	else if (isInt(literal, len))
		return (Type::INT);
	else if (isFloat(literal))
		return (Type::FLOAT);
	else if (isDouble(literal))
		return (Type::DOUBLE);
	return (Type::UNKNOWN);
}
