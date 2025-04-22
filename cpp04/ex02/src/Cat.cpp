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
	this->brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << YELLOW << "Cat: copy constructor called." << RESET << std::endl;
	this->brain = new Brain(*src.brain);
	this->type = src.type;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	std::cout << YELLOW << "Cat: copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << YELLOW << "Cat: destructor called." << RESET << std::endl;
	if (this->brain)
		delete this->brain;
}

void	Cat::makeSound(void) const
{
	std::cout << YELLOW << "Meow, Meoooooooooooooooooooow~~~~" << RESET << std::endl;
}

void	Cat::setIdea(unsigned int index, const std::string& idea)
{
	this->brain->setIdea(index, idea);
}


void	Cat::printIdea(void) const
{
	this->brain->printIdea();
}
