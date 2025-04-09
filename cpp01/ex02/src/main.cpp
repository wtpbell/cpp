/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 14:53:17 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 15:27:00 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory address of the str: " << &str << std::endl;
	std::cout << "Memory address held by PTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by REF: " << &stringREF << std::endl;
	std::cout << "Value of the str: " << str << std::endl;
	std::cout << "Value pointed to by PTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by REF: " << stringREF << std::endl;

	return (0);
}
