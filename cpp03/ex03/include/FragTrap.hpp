/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:02:54 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 11:02:54 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"
# define CYAN	"\033[0;96m"
# define MAGENTA "\033[0;95m"

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap : virtual public ClapTrap
{
	public:
			FragTrap();
			FragTrap(std::string name);
			FragTrap(const FragTrap& obj);
			FragTrap& operator=(const FragTrap& rhs);
			~FragTrap();

			void	attack(const std::string& target);
			void	highFivesGuys(void);
};

#endif
