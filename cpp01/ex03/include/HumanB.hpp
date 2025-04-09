/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 16:01:41 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 16:40:56 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{
	private:
			std::string	name;
			Weapon		*weapon;
	public:
			HumanB(std::string name);
			~HumanB(void);
			void	attack(void);
			void	setWeapon(Weapon &weapon);
};

#endif
