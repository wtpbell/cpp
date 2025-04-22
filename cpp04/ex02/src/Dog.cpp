/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:46:34 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 15:46:34 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << GREEN << "Dog: default constructor called." << RESET << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << GREEN << "Dog: copy constructor called." << RESET << std::endl;
	this->brain = new Brain(*src.brain);
	this->type = src.type;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	std::cout << GREEN << "Dogl: copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << GREEN << "Dog: destructor called." << RESET << std::endl;
	if (this->brain)
		delete this->brain;
}

void	Dog::makeSound(void) const
{
	std::cout << GREEN << "Woof~ Woooooooof~" << RESET << std::endl;
}

void	Dog::setIdea(unsigned int index, const std::string& idea)
{
	this->brain->setIdea(index, idea);
}


void	Dog::printIdea(void) const
{
	this->brain->printIdea();
}
