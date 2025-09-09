/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 10:23:34 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 14:45:40 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* new throws a std::bad_alloc exception if memeory allocation fails.
	It doesnt return NULL. */ 

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (nullptr);
	Zombie *horde = new Zombie[N];
	for(int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
