/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:03:01 by bewong            #+#    #+#             */
/*   Updated: 2025/04/22 15:03:01 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("")
{
	std::cout << YELLOW << "AMateria: default constructor called." << RESET << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type)
{
	std::cout << YELLOW << "AMateria: default constructor with type " << this->_type << " called." << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << YELLOW << "AMateria: copy constructor called." << RESET << std::endl;
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	std::cout << YELLOW << "AMateria: copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << YELLOW << "AMateria: destructor called." << RESET << std::endl;
}

std::string const& AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << YELLOW << "* " << this->_type << " used on " << target.getName() << " *" << RESET << std::endl;
}
