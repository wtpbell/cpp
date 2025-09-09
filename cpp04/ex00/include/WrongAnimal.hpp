/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:54:26 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 15:54:26 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#define BOLD	"\033[1m"
#define BLUE	"\033[0;94m"
#define GREEN	"\033[0;92m"
#define YELLOW	"\033[0;93m"
#define RED		"\03[0;91m"
#define CYAN	"\033[0;96m"
#define MAGENTA	"\033[0;95m"
#define RESET	"\033[0m"
#define ORANGE	"\033[38;5;208m"

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal &operator=(const WrongAnimal &rhs);
		~WrongAnimal();

		void		makeSound(void) const;
		std::string	getType(void) const;
};

std::ostream& operator<<(std::ostream& os, const WrongAnimal& animal);

#endif
