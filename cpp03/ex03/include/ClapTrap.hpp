/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:46:31 by bewong            #+#    #+#             */
/*   Updated: 2025/04/17 16:46:31 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"
# define CYAN	"\033[0;96m"
# define MAGENTA "\033[0;95m"

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
			std::string		name;
			unsigned int	_hp;
			unsigned int	_ep;
			unsigned int	_ad;
	public:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap& obj);
			ClapTrap& operator=(const ClapTrap& obj);
			~ClapTrap();

			void			attack(const std::string& target);
			void			takeDamage(unsigned int amount);
			void			beRepaired(unsigned int amount);
};

#endif
