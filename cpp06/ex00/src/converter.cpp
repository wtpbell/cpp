/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:35:55 by bewong            #+#    #+#             */
/*   Updated: 2025/09/05 19:35:55 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cerrno>
#include <stdexcept>
#include <iomanip>

#include "ScalarConverter.hpp"

FType ScalarConverter::identifyFloatType(const std::string& literal, float value)
{
	if (literal == PSEUDO_NANF || std::isnan(value))
		return FType::FTYPE_NAN;
	if (literal == PSEUDO_INFF || literal == PSEUDO_INFF_MIN || std::isinf(value))
		return FType::FTYPE_INF;
	return FType::NORMAL;
}

FType ScalarConverter::identifyDoubleType(const std::string& literal, double value)
{
	if (literal == PSEUDO_NAN || std::isnan(value))
		return FType::FTYPE_NAN;
	if (literal == PSEUDO_INF || literal == PSEUDO_INF_MIN || std::isinf(value))
		return FType::FTYPE_INF;
	return FType::NORMAL;
}

static void	printChar(char c)
{
	std::cout << "char: ";
	(std::isprint(c))
		? std::cout << "'" << c << "'" << std::endl
		: std::cout << "Non displayable" << std::endl;
}

static void printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

static void	printFloat(float f)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void	printDouble(double d)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

static void printPseudo(FType type, bool isFloat, bool isNegative)
{
	if (type == FType::FTYPE_NAN)
		std::cout << (isFloat ? "float: nanf" : "double: nan") << std::endl;
	else if (type == FType::FTYPE_INF)
	{
		if (!isNegative)
			std::cout << (isFloat ? "float: inff" : "double: inf") << std::endl;
		else
			std::cout << (isFloat ? "float: -inff" : "double: -inf") << std::endl;
	}
}

static void	printAllImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void convertCharAndPrint(const std::string& literal)
{
	char c = (literal.length() == 1) ? literal[0] : literal[1];

	printChar(static_cast<unsigned char>(c));
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

static void convertIntAndPrint(const std::string& literal)
{
	try
	{
		long l = std::stol(literal);

		if (l < ASCII_MIN || l > ASCII_MAX)
			std::cout << "char: impossible" << std::endl;
		else		
			printChar(static_cast<unsigned char>(l));

		if (l < MIN_INT || l > MAX_INT)
			std::cout << "int: impossible" << std::endl;
		else
			printInt(static_cast<int>(l));

		printFloat(static_cast<float>(l));
		printDouble(static_cast<double>(l));
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Error: Out of range " << e.what() << std::endl;
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "Error: Invalid argument " << e.what() << std::endl;
	}
}
void ScalarConverter::convertFloatAndPrint(const std::string& literal)
{
	std::string	numStr;
	float		f;
	double		d;
	FType		type;

	try
	{
		numStr = literal;
		if (numStr.back() == 'f' || numStr.back() == 'F')
			numStr = numStr.substr(0, numStr.length() - 1);
		f = std::stof(numStr);

		type = identifyFloatType(literal, f);

		if (type == FType::FTYPE_NAN || type == FType::FTYPE_INF || f < ASCII_MIN || f > ASCII_MAX)
			std::cout << "char: impossible" << std::endl;
		else
			printChar(static_cast<unsigned char>(f));

		d = static_cast<double>(f);
		if (type == FType::FTYPE_NAN || type == FType::FTYPE_INF ||
			d < static_cast<double>(MIN_INT) || d > static_cast<double>(MAX_INT))
			std::cout << "int: impossible" << std::endl;
		else
			printInt(static_cast<int>(d));

		if (type == FType::FTYPE_NAN || type == FType::FTYPE_INF)
			printPseudo(type, true, (f < 0));
		else
		{
			printFloat(f);
			printDouble(static_cast<double>(f));
		}
	}
	catch (const std::exception& e)
	{
		printAllImpossible();
	}
}

void ScalarConverter::convertDoubleAndPrint(const std::string& literal)
{

	double	d;
	FType	type;

	try
	{
		d = std::stod(literal);

		type = identifyDoubleType(literal, d);

		if (type == FType::FTYPE_NAN || type == FType::FTYPE_INF || d < ASCII_MIN || d > ASCII_MAX)
			std::cout << "char: impossible" << std::endl;
		else
			printChar(static_cast<unsigned char>(d));

		if (type == FType::FTYPE_NAN || type == FType::FTYPE_INF ||
			d < static_cast<double>(MIN_INT) || d > static_cast<double>(MAX_INT))
			std::cout << "int: impossible" << std::endl;
		else
			printInt(static_cast<int>(d));

		if (d < static_cast<double>(MIN_FLOAT) || d > static_cast<double>(MAX_FLOAT))
			std::cout << "float: impossible" << std::endl;
		else
			printFloat(static_cast<float>(d));

		if (type == FType::FTYPE_NAN || type == FType::FTYPE_INF)
			printPseudo(type, false, (d < 0));
		else
			printDouble(d);

	}
	catch (const std::exception& e)
	{
		printAllImpossible(); 
	}
}

static void convertPseudoAndPrint(const std::string& literal)
{
	FType	fType;
	FType	dType;
	
	if (literal == PSEUDO_NANF || literal == PSEUDO_INFF || literal == PSEUDO_INFF_MIN)
	{
		fType = (literal == PSEUDO_NANF) ? FType::FTYPE_NAN : FType::FTYPE_INF;
		dType = (literal == PSEUDO_NANF) ? FType::FTYPE_NAN : FType::FTYPE_INF;
	}
	else
	{
		dType = (literal == PSEUDO_NAN) ? FType::FTYPE_NAN : FType::FTYPE_INF;
		fType = dType;
	}

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	printPseudo(fType, true, (literal == PSEUDO_INF_MIN || literal == PSEUDO_INFF_MIN));
	printPseudo(dType, false, (literal == PSEUDO_INF_MIN || literal == PSEUDO_INFF_MIN));
}

void ScalarConverter::convertAndDisplay(Type type, const std::string& literal)
{
	switch (type)
	{
		case Type::CHAR:
			convertCharAndPrint(literal);
			break;
		case Type::INT:
			convertIntAndPrint(literal);
			break;
		case Type::FLOAT:
			convertFloatAndPrint(literal);
			break;
		case Type::DOUBLE:
			convertDoubleAndPrint(literal);
			break;
		case Type::PSEUDO:
			convertPseudoAndPrint(literal);
			break;
		default:
			printAllImpossible();
	}
}
