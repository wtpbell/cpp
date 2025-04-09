/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 10:21:07 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 14:48:05 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	private:
			std::string	name;
	public:
			Zombie(void);
			Zombie(std::string name);
			~Zombie(void);
			void	announce(void);
			void	setName(std::string name);
};
Zombie*	zombieHorde(int N, std::string name);

#endif
