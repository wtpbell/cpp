/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:09:19 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 13:09:19 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), name("default")
{
	std::cout << BOLD << "DiamondTrap: default constructor called" << RESET << std::endl;
	_hp = 100;
	_ep = 50;
	_ad = 30;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	std::cout << BOLD << "DiamondTrap: parameterized constructor '" << name << "' called" << RESET << std::endl;
	_hp = 100;
	_ep = 50;
	_ad = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
	: ClapTrap(obj), ScavTrap(obj), FragTrap(obj), name(obj.name)
{
	std::cout << BOLD << "DiamondTrap: copy constructor called" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << BOLD << "DiamondTrap: assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		this->name = rhs.name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BOLD << "DiamondTrap: destructor called" << RESET << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	if (this->_hp <= 0)
		std::cout << RED << "DiamondTrap: " << this->name << " is too injured to tell whoAmI!" << RESET << std::endl;
	else
		std::cout << CYAN << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << RESET << std::endl;
}

