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
	std::cout << "\n=== Testing with int array ===" << std::endl;
	int intArr[] = {1, 2, 3, 4, 5};
	std::cout << "Original intArr: \n";
	::iter(intArr, 5, print<int>);
	std::cout << std::endl;

	std::cout << "Adjusted intArr: \n";
	::iter(intArr, 5, adjustValue);
	::iter(intArr, 5, print<int>);
	std::cout << std::endl;

	std::cout << "\n=== Testing with string array ===" << std::endl;
	std::string stringArr[] = {"Hello", "World", "!"};
	std::cout << "Original stringArr: \n";
	::iter(stringArr, 3, print<std::string>);
	std::cout << std::endl;

	std::cout << "Upper case string: \n";
	::iter(stringArr, 3, upperCase);
	::iter(stringArr, 3, print<std::string>);
	std::cout << std::endl;

	std::cout << "\n === Testing with const int array ===" << std::endl;
	const int constIntArr[] = {2, 4, 6, 8, 10};
	std::cout << "Original constIntArr: \n";
	::iter(constIntArr, 5, print<int>);
	std::cout << std::endl;
	return (0);
}
