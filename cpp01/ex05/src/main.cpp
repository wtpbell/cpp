/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/13 14:14:19 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/18 09:11:49 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	 harl;

	std::cout << CYAN << "=== Testing all Harl's complaint levels ==="  << RESET << std::endl;
	std::cout << std::string(50, '-') << std::endl;

	std::cout << MAGENTA << "Testing DEBUG level:" << RESET << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << MAGENTA << "Testing INFO level:" << RESET << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << MAGENTA << "Testing WARNING level:" << RESET << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << MAGENTA << "Testing ERROR level:" << RESET << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << MAGENTA << "Testing invalid levels:" << RESET << std::endl;
	harl.complain("INVALID");
	harl.complain("debug");
	harl.complain("");
	harl.complain("!@#$%^&*()");
	harl.complain("1234567890");
	harl.complain("D_E_B_U_G");
	std::cout << std::endl;

	return (0);
}
