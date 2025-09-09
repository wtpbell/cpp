/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:31:14 by bewong            #+#    #+#             */
/*   Updated: 2025/04/17 19:31:14 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"
# define CYAN	"\033[0;96m"
# define MAGENTA "\033[0;95m"

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
			ScavTrap();
			ScavTrap(std::string name);
			ScavTrap(const ScavTrap& obj);
			ScavTrap& operator=(const ScavTrap& rhs);
			~ScavTrap();
			void	attack(const std::string& target);
			void	guardGate(void);
};

#endif
