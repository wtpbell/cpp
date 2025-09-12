/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:12:02 by bewong            #+#    #+#             */
/*   Updated: 2025/09/10 10:12:02 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

//this is a template not function, it becomes a function when instantiated with a type
// cant take its address or pass it directly to a function, that why need to explicitly call it with the type
template <typename T>
void	print(T s)
{
	std::cout << s << std::endl;
}

void	adjustValue(int& value)
{
	value++;
}

void	upperCase(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

int main(void)
{
	std::cout << CYAN << "\n=== Testing with int array ===" << RESET << std::endl;
	int intArr[] = {1, 2, 3, 4, 5};
	std::cout << "Original intArr: \n";
	::iter(intArr, 5, print<int>);
	std::cout << std::endl;

	std::cout << "Adjusted intArr: \n";
	::iter(intArr, 5, adjustValue);
	::iter(intArr, 5, print<int>);
	std::cout << std::endl;

	std::cout << CYAN << "\n=== Testing with string array ===" << RESET << std::endl;
	std::string stringArr[] = {"Hello", "World", "!"};
	std::cout << "Original stringArr: \n";
	::iter(stringArr, 3, print<std::string>);
	std::cout << std::endl;

	std::cout << "Upper case string: \n";
	::iter(stringArr, 3, upperCase);
	::iter(stringArr, 3, print<std::string>);
	std::cout << std::endl;

	// lambda create an anonymous function object(closure) - unnamed function object with a call operator
	// syntax: [capture](parameters) -> return_type { body }
	// [] not using any variables out of the scope;
	// lambda function is a concrete object, the operator() is a template that gets instantiated when called
	std::cout << CYAN << "\n === Testing with lambda function ===" << RESET << std::endl;
	int intArr2[] = {1, 2, 3, 4, 5};
	std::cout << "Original intArr2: \n";
	::iter(intArr2, 5, print<int>);
	std::cout << std::endl;

	std::cout << "Adjusted intArr2: \n";
	::iter(intArr2, 5, [](auto &value){ value *= 2; });
	::iter(intArr2, 5, print<int>);
	std::cout << std::endl;

	std::cout << CYAN << "\n === Testing with const int array ===" << RESET << std::endl;
	const int constIntArr[] = {2, 4, 6, 8, 10};
	std::cout << "Original constIntArr: \n";
	::iter(constIntArr, 5, print<int>);
	std::cout << std::endl;

	std::cout << CYAN << "\n === Testing with const string array ===" << RESET << std::endl;
	const std::string constStringArr[] = {"Bye", "World", "!"};
	::iter(constStringArr, 3, print<const std::string>);
	std::cout << std::endl;

	return (0);
}
