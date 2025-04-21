/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:15:50 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 15:15:50 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
			Brain*	brain;
	public:
			Cat();
			Cat(const Cat& src);
			Cat& operator=(const Cat& rhs);
			~Cat();

			void		makeSound(void) const override;
			void	setIdea(unsigned int index, const std::string& idea);
			void	printIdea(void) const;
};

#endif
