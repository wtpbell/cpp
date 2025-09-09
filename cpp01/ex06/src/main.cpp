/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/13 18:48:33 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/13 18:48:34 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl;
	Level	level;

	if (argc != 2)
	{
		std::cout << RED << "Usage: ./harlFilter <level>" << RESET << std::endl;
		std::cout << "Level can be: DEBUG, INFO, WARNING, or ERROR" << std::endl;
		return (1);
	}
	level = harl.getLevel(argv[1]);
	harl.filterComplain(level);
	return (0);
}
