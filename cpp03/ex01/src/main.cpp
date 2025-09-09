/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:00:31 by bewong            #+#    #+#             */
/*   Updated: 2025/04/17 18:00:31 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << GREEN << "\n=== Creating Default ClapTrap and ScavTrap ===\n" << RESET;
	std::cout << "a: ";
	ClapTrap a;
	std::cout << "b: ";
	ScavTrap b("Baka");
	a.attack("Nobody");
	b.attack("Nobody");
	std::cout << "\n";

	std::cout << GREEN << "\n=== Creating Named and Copy ScavTrap ===\n" << RESET;
	std::cout << "c: ";
	ScavTrap c(b);
	std::cout << "d: ";
	ScavTrap d("Copycat");
	c.attack("Someone");
	d = c;
	d.attack("Another");
	std::cout << "\n";

	std::cout << GREEN << "\n=== Attack Until Energy Runs Out (ScavTrap) ===\n" << RESET;
	for (int i = 0; i < 55; ++i) {
		std::cout << "[" << i+1 << "] ";
		b.attack("Target");
	}
	std::cout << "\n";

	std::cout << GREEN << "\n=== Overkill and Repair Edge Cases ===\n" << RESET;
	c.takeDamage(1000);
	c.attack("Nobody");
	c.beRepaired(10);
	std::cout << "\n";

	std::cout << GREEN << "\n=== guardGate() Test ===\n" << RESET;
	b.guardGate();
	c.guardGate();
	std::cout << "\n";

	std::cout << GREEN << "\n=== End of Main ===\n" << RESET;
	return 0;
}

