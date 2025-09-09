/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:32:40 by bewong            #+#    #+#             */
/*   Updated: 2025/04/22 15:32:40 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default_name")
{
	std::cout << GREEN << "Character: default constructor called." << RESET << std::endl;
	for (unsigned int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
}

Character::Character(std::string const& name) : _name(name)
{
	std::cout << GREEN << "Character: default constructor with name " << this->_name << " called." << RESET << std::endl;
	for (unsigned int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
}

Character::Character(const Character& other) : _name(other._name)
{
	std::cout << GREEN << "Character: copy constructor called." << RESET << std::endl;
	for (unsigned int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = nullptr;
	}
}

Character&	Character::operator=(const Character& rhs)
{
	std::cout << GREEN << "Character: copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (unsigned int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
			{
				delete this->inventory[i];
				this->inventory[i] = nullptr;
			}
		}
		for (unsigned int i = 0; i < 4; i++)
		{
			if (rhs.inventory[i])
				this->inventory[i] = rhs.inventory[i]->clone();
			else
				this->inventory[i] = nullptr;
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << GREEN << "Character: destructor called" << RESET << std::endl;
	for (unsigned int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = nullptr;
		}
	}
}

std::string const& Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
	{
		std::cout << GREEN << "Unequipped " << this->inventory[idx]->getType() << " from " << this->_name << "'s inventory at index " << idx << RESET << std::endl;
		this->inventory[idx] = nullptr;
	}
	else if (idx < 0 || idx > 3)
		std::cout << RED << "Cannot unequip materia, invalid index " << idx << RESET << std::endl;
	else
		std::cout << RED << "Cannot unequip materia, inventory slot " << idx << " is empty" << RESET << std::endl;
	
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
	{
		std::cout << GREEN << "Used " << this->inventory[idx]->getType() << " from " << this->_name << "'s inventory at index " << idx << RESET << std::endl;
		this->inventory[idx]->use(target);
	}
	else if (idx < 0 || idx > 3)
		std::cout << RED << "Cannot use materia, invalid index " << idx << RESET << std::endl;
	else
		std::cout << RED << "Cannot use materia, inventory slot " << idx << " is empty" << RESET << std::endl;
}

AMateria*	Character::getMateria(int idx) const
{
	if (idx >= 0 && idx < 4)
		return (this->inventory[idx]);
	return (nullptr);
}
