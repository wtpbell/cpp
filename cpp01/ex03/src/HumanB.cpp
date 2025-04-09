/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 19:02:55 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 19:25:41 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(nullptr)
{
	std::cout << name << " didn't get weapon."
				<< std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << RED << BOLD << this->name
				<< " is being removed." << RESET << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	std::cout << this->weapon->getType()
				<< " is being taken." << std::endl;
}

void	HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name << " attacks with their "
				<< this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with their bare hands."
					<< std::endl;
}
