/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:14:24 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 12:14:24 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"
# define CYAN	"\033[0;96m"
# define MAGENTA "\033[0;95m"

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
			std::string	name;
			using FragTrap::_hp;
			using ScavTrap::_ep;
			using FragTrap::_ad;

	public:
			DiamondTrap();
			DiamondTrap(std::string name);
			DiamondTrap(const DiamondTrap& obj);
			DiamondTrap& operator=(const DiamondTrap& rhs);
			~DiamondTrap();

			using ScavTrap::attack;
			void	whoAmI(void);
};

#endif

