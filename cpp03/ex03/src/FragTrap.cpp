/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:13:13 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 11:13:13 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap(): ClapTrap("default_clap_name")
{
	std::cout << BOLD << "FragTrap: default constructor called" << RESET << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << BOLD << "FragTrap: parameterized constructor " << name << " called" << RESET << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

FragTrap::FragTrap(const FragTrap& obj): ClapTrap(obj)
{
	std::cout << BOLD << "FragTrap: copy constructor " << obj.name << " called" << RESET << std::endl;
	*this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << BOLD << "FragTrap: assignment operator " << rhs.name << " called" << RESET << std::endl;
	if(this != &rhs)
	{
		this->name = rhs.name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << BOLD << "FragTrap: destructor " << this->name << " called" << RESET << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_ep > 0 && this->_hp > 0)
	{
		this->_ep--;
		std::cout << YELLOW << "FragTrap: " << this->name << " attacks " << target << "." << RESET << std::endl;
	}
	else
	std::cout << YELLOW << "FragTrap: " << this->name << " has no energy or hit points left to attack!" << RESET << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hp <= 0)
		std::cout << RED << "FragTrap: " << this->name << " is too injured to high five the guys!" << RESET << std::endl;
	else
		std::cout << BOLD << "FragTrap: " << this->name << " high fives the guys!" << RESET << std::endl;
}
