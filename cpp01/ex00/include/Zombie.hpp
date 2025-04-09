/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 09:31:14 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 10:44:50 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	private:
			std::string	name;
	public:
			Zombie(std::string name);
			~Zombie(void);
			void	announce(void);
};
Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
