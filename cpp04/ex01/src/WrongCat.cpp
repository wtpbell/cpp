/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:10:08 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 17:10:08 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << ORANGE << "WrongCat: default constructor called." << RESET << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	std::cout << ORANGE << "WrongCat: copy constructor called." << RESET << std::endl;
	*this = src;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << ORANGE << "WrongCat: copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << ORANGE << "WrongCat: destructor called." << RESET << std::endl;
}

void	WrongCat::makeSound(void) const
{	
	std::cout << ORANGE << "Meow, Meoooooooooooooooooooow~~~~" << RESET << std::endl;
}
