/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 09:31:19 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 09:57:10 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zom;

	zom = newZombie("Walkers");
	zom->announce();
	randomChump("Lurkers");
	delete zom;
	return (0);
}
