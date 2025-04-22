/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:15:52 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 15:15:52 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
			Brain* brain;
	public:
			Dog();
			Dog(const Dog &src);
			Dog &operator=(const Dog &rhs);
			~Dog();
	
			void	makeSound(void) const override;
			void	setIdea(unsigned int index, const std::string& idea);
			void	printIdea(void) const;
};

#endif
