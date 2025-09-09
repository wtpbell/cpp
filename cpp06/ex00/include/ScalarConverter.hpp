/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:19:59 by bewong            #+#    #+#             */
/*   Updated: 2025/09/05 10:19:59 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <limits>
#include <string>
#include <cmath>

#define MIN_INT std::numeric_limits<int>::min()
#define MAX_INT std::numeric_limits<int>::max()
#define MIN_FLOAT std::numeric_limits<float>::min()
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_DOUBLE std::numeric_limits<double>::min()
#define MAX_DOUBLE std::numeric_limits<double>::max()
#define PSEUDO_INF "inf"
#define PSEUDO_INF_MIN "-inf"
#define PSEUDO_NAN "nan"
#define PSEUDO_NANF "nanf"
#define PSEUDO_INFF "inff"
#define PSEUDO_INFF_MIN "-inff"
#define ASCII_MAX 127
#define ASCII_MIN 0

// enum class: enumerator names are local to the enum and dont implicitly
// convert to other types
//  enum: where enumerator names are in the same scope as the enum, implicitly
//  convert to integers and other types

enum class Type
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDO,
			UNKNOWN
		};

		enum class FType : uint8_t
		{
			NORMAL,
			FTYPE_NAN,
			FTYPE_INF,
		};


class ScalarConverter
{
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter&) = delete;
		ScalarConverter& operator=(const ScalarConverter&) = delete;
		~ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter&&) noexcept = delete;
		ScalarConverter& operator=(const ScalarConverter&&) noexcept = delete;
		
		static void convert(const std::string& literal);

	private:
	
		static Type identifyType(const std::string& literal);
		static FType identifyFloatType(const std::string& literal, float value);
		static FType identifyDoubleType(const std::string& literal, double value);
		static void convertFloatAndPrint(const std::string& literal);
		static void convertDoubleAndPrint(const std::string& literal);
		static void convertAndDisplay(Type type, const std::string& literal);

	
};



#endif // SCALARCONVERTER_H
