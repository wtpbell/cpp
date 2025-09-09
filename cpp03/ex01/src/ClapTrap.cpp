/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:04:42 by bewong            #+#    #+#             */
/*   Updated: 2025/04/17 17:04:42 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), _hp(10), _ep(10), _ad(0)
{
	std::cout << BOLD << "ClapTrap: default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << BOLD << "ClapTrap: parameterized constructor " << name << " called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	*this = obj;
	std::cout << BOLD << "ClapTrap: copy constructor " << obj.name << " called" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << BOLD << "ClapTrap: assignment operator " << rhs.name << " called" << RESET << std::endl;
	if(this != &rhs)
	{
		this->name = rhs.name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BOLD << "ClapTrap: destructor " << this->name << " called" << RESET << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_ep > 0 && this->_hp > 0)
	{
		this->_ep--;
		std::cout << YELLOW << "ClapTrap " << this->name << " attacks " << target << "." << RESET << std::endl;
	}
	else
		std::cout << YELLOW << "ClapTrap " << this->name << " has no energy or hit points left to attack!" << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp == 0)
	{
		std::cout << MAGENTA << "ClapTrap " << this->name << " has already been defeated!" << RESET << std::endl;
		return ;
	}
	if (amount >= this->_hp)
	{
		this->_hp = 0;
		std::cout << MAGENTA << "ClapTrap " << this->name << " takes " << amount << " points of damage and is defeated!" << RESET << std::endl;
		return ;
	}
	else
	{
		this->_hp -= amount;
		std::cout << MAGENTA << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << RESET << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_ep > 0 && this->_hp > 0)
	{
		this->_ep--;
		this->_hp += amount;
		std::cout << GREEN << "ClapTrap " << this->name << " repairs itself, regaining " << amount << " points of health!" << RESET << std::endl;
	}
	else
	{
		std::cout << GREEN << "ClapTrap " << this->name << " has no energy or hit points left to repair!" << RESET << std::endl;
		return ;
	}
}
