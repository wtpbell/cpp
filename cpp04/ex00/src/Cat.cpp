/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:46:10 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 15:46:10 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << YELLOW << "Cat: default constructor called." << RESET << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << YELLOW << "Cat: copy constructor called." << RESET << std::endl;
	*this = src;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	std::cout << YELLOW << "Cat: copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << YELLOW << "Cat: destructor called." << RESET << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << YELLOW << "Meow, Meoooooooooooooooooooow~~~~" << RESET << std::endl;
}
