/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 15:54:45 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 16:54:05 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"
# define CYAN	"\033[0;96m"
# define MAGENTA "\033[0;95m"
#include <iostream>

class Weapon
{
	private:
			std::string	type;
	public:
			Weapon(std::string type);
			~Weapon(void);
			const std::string	&getType(void);
			void				setType(std::string type);
};

#endif
