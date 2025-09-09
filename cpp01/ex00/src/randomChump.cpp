/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/09 09:31:25 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/09 10:14:27 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//ClassName objectName(constructorArguments);
void	randomChump(std::string name)
{
	Zombie zom(name);
	zom.announce();
}
