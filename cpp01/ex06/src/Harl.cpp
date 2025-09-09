/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/13 18:48:31 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/13 18:48:32 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{

}

Harl::~Harl(void)
{

}

void	Harl::debug(void)
{
	std::cout << BOLD << YELLOW << "[ DEBUG ]" << RESET << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I just love it!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << BOLD << YELLOW << "[ INFO ]" << RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
	std::cout << "You don't put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << BOLD << RED << "[ WARNING ]" << RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming here for years and you just started working here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << BOLD << RED << "[ ERROR ]" << RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Level	Harl::getLevel(const std::string& level)
{
	if (level == "DEBUG") { return Level::DEBUG;}
	if (level == "INFO") { return Level::INFO;}
	if (level == "WARNING") { return Level::WARNING;}
	if (level == "ERROR") { return Level::ERROR;}
	return (Level::INVALID);
}

void	Harl::filterComplain(Level level)
{
	switch (level)
	{
		case Level::DEBUG:
			this->debug();
			[[fallthrough]];
		case Level::INFO:
			this->info();
			[[fallthrough]];
		case Level::WARNING:
			this->warning();
			[[fallthrough]];
		case Level::ERROR:
			this->error();
			break;
		default:
			std::cout << RED << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
			break;
	}
}
