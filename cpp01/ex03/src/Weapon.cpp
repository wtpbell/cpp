/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 16:43:55 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 19:23:49 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << GREEN << BOLD << "Weapon created with type: " << type << RESET << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << RED << BOLD << "The Weapon " << this->type << " is being destoryed!" << RESET << std::endl;
}

const std::string	&Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	std::cout << "Current weapon: "
				<< this->type << " is changed in: "
				<< type << std::endl;
	this->type = type;
}
