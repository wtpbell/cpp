/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 16:01:07 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 16:41:00 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA
{
	private:
			std::string	name;
			Weapon		&weapon;
	public:
			HumanA(std::string name, Weapon &weapon);
			~HumanA(void);
			void	attack(void);
};

#endif
