/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 10:35:28 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 14:41:16 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		numZombie;

	numZombie = 7;
	horde = zombieHorde(numZombie, "Roamers");
	if (!horde)
	{
		std::cerr << "Failed to create horde!" << std::endl;
		return (1);
	}
	for (int i = 0; i < numZombie; i++)
		horde[i].announce();
	delete[] horde;
	horde = nullptr;
	return (0);
}
