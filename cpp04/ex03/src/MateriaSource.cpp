/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:50:53 by bewong            #+#    #+#             */
/*   Updated: 2025/04/22 16:50:53 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << MAGENTA << "MateriaSource: default constructor called." << RESET << std::endl;
	for (unsigned int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << MAGENTA << "MateriaSource: copy constructor called" << RESET << std::endl;
	for (unsigned int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = nullptr;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	std::cout << MAGENTA << "MateriaSource: copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
	{
		for (unsigned int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
			{
				delete inventory[i];
				inventory[i] = nullptr;
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

MateriaSource::~MateriaSource()
{
	std::cout << MAGENTA << "MateriaSource: destructor called" << RESET << std::endl;
	for (unsigned int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = nullptr;
		}
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m->clone();
			delete m;
			return ;
		}
	}
	delete m; 
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		if (this->inventory[i] && this->inventory[i]->getType() == type)
			return (this->inventory[i]->clone());
	}
	std::cout << RED << "Materia can't be created, " << type << " is invalid!" << RESET << std::endl;
	return (0);
}
