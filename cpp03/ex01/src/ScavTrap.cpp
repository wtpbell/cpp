/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:40:59 by bewong            #+#    #+#             */
/*   Updated: 2025/04/17 19:40:59 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap: default constructor called" << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << BOLD << "ScavTrap: parameterized constructor " << name << " called" << RESET << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj): ClapTrap(obj)
{
	std::cout << BOLD << "ScavTrap: copy constructor " << obj.name << " called" << RESET << std::endl;
	*this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << BOLD << "ScavTrap: assignment operator " << rhs.name << " called" << RESET << std::endl;
	if(this != &rhs)
	{
		this->name = rhs.name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << BOLD << "ScavTrap: destructor " << this->name << " called" << RESET << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_ep > 0 && this->_hp > 0)
	{
		this->_ep--;
		std::cout << YELLOW << "ScavTrap: " << this->name << " attacks " << target << "." << RESET << std::endl;
	}
	else
	std::cout << YELLOW << "ScavTrap: " << this->name << " has no energy or hit points left to attack!" << RESET << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hp <= 0)
		std::cout << RED << "ScavTrap: " << this->name << " has no hit points left to guard!" << RESET << std::endl;
	else
		std::cout << BOLD << "ScavTrap: " << this->name << " is now in Gate keeper mode." << RESET << std::endl;
}
