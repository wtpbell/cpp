/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:15:48 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 15:15:48 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#define BOLD	"\033[1m"
#define BLUE	"\033[0;94m"
#define GREEN	"\033[0;92m"
#define YELLOW	"\033[0;93m"
#define RED		"\03[0;91m"
#define CYAN	"\033[0;96m"
#define MAGENTA	"\033[0;95m"
#define RESET	"\033[0m"
#define ORANGE	"\033[38;5;208m"

#include <string>
#include <iostream>

class Animal
{
	protected:
				std::string	type;

	public:
				Animal();
				Animal(const Animal& src);
				Animal& operator=(const Animal& rhs);
				virtual ~Animal();

				virtual void	makeSound(void) const;
				std::string 	getType(void) const;
};

std::ostream& operator<<(std::ostream& os, const Animal& animal);

#endif
