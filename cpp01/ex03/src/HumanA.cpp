/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 18:52:58 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 19:24:44 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon  &weapon) : name(name), weapon(weapon)
{
	std::cout << name << " gets the weapon "
				<< weapon.getType() << "."
				<< std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << RED << BOLD << this->name
				<< " is being removed!" << RESET << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their "
				<< this->weapon.getType() << std::endl;
}
