/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:37 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 16:54:37 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("undefined")
{
	std::cout << MAGENTA << "WrongAnimal: default constructor called." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << MAGENTA << "WrongAnimal: copy constructor called." << RESET << std::endl;
	*this = src;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << MAGENTA << "WrongAnimal: copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << MAGENTA << "WrongAnimal: destructor called." << RESET << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << MAGENTA << "WrongAnimal: this " << this->type << " animal makes weird sound!" << RESET << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

std::ostream& operator<<(std::ostream& os, const WrongAnimal& animal)
{
	os << BOLD << "(type: " << animal.getType() << ")";
	return (os);
}
