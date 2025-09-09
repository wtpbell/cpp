/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:30:40 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 18:30:40 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << BLUE << "Brian: default constructor called." << RESET << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << BLUE << "Brain: copy constructor called." << RESET << std::endl;
	*this = src;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	std::cout << BLUE << "Brain: copy assignment operator called." << RESET << std::endl;
	if (this != &rhs)
	{
		for (unsigned int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << BLUE << "Brain: destructor called." << RESET << std::endl;
}

void	Brain::setIdea(unsigned int index, const std::string& idea)
{
	if (index >= 100)
		std::cerr << BOLD << RED << "My brain can only save maximum ideas of 100." << RESET << std::endl;
	else
		this->ideas[index] = idea;
}

void	Brain::printIdea(void) const
{
	std::cout << BOLD "Ideas: " << std::endl;
	for (unsigned int i = 0; i < 100; i++)
	{
		if (!this->ideas[i].empty())
			std::cout << "[ " << i << " ]: " << this->ideas[i] << RESET << std::endl;
	}
}
