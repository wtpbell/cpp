/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:55:12 by bewong            #+#    #+#             */
/*   Updated: 2025/04/22 18:55:12 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << BLUE << "Ice: default constructor called." << RESET << std::endl;
	this->_type = "ice";
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << BLUE << "Ice: copy constructor called." << RESET << std::endl;
	this->_type = other._type;
}

Ice::Ice(const std::string& type)
{
	std::cout << BLUE << "Ice: default constructor with type " << type << " called." << RESET << std::endl;
	this->_type = type;
}

Ice&	Ice::operator=(const Ice& rhs)
{
	std::cout << BLUE << "Ice: copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << BLUE << "Ice: destructor called." << RESET << std::endl;
}

AMateria* Ice::clone() const
{
	std::cout << BLUE << "Ice: Cloning materia." << RESET << std::endl;
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
