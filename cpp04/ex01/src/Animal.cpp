/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:15:21 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 16:15:21 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("undefined")
{
	std::cout << BOLD << "Animal: default constructor called." << RESET << std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout << BOLD << "Animal: copy constructor called." << RESET << std::endl;
	*this = src;
}

Animal&	Animal::operator=(const Animal& rhs)
{
	std::cout << BOLD << "Animal: copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << BOLD << "Animal: destructor called." << RESET << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << BLUE << "Animal: default sound." << RESET << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

std::ostream& operator<<(std::ostream& os, const Animal& animal)
{
	os << BOLD << "(type: " << animal.getType() << ")";
	return (os);
}
