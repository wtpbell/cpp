/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:21:09 by bewong            #+#    #+#             */
/*   Updated: 2025/04/22 18:21:09 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	std::cout << ORANGE << "Cure: default constructor called." << RESET << std::endl;
	this->_type = "cure";
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << ORANGE << "Cure: copy constructor called." << RESET << std::endl;
	this->_type = other._type;
}

Cure::Cure(const std::string& type)
{
	std::cout << ORANGE << "Cure: default constructor with type " << type << " called." << RESET << std::endl;
	this->_type = type;
}

Cure&	Cure::operator=(const Cure& rhs)
{
	std::cout << ORANGE << "Cure: copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << ORANGE << "Cure: destructor called." << RESET << std::endl;
}

AMateria* Cure::clone() const
{
	std::cout << ORANGE << "Cure: Cloning materia." << RESET << std::endl;
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << ORANGE << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
