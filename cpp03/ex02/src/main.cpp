/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:00:31 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 14:52:18 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << GREEN << "\n=== Creating Default ClapTrap, ScavTrap, FragTrap ===\n" << RESET;
	std::cout << "a: ";
	ClapTrap a;
	std::cout << "b: ";
	ScavTrap b("Baka");
	std::cout << "c: ";
	FragTrap c("Fragtrap");
	a.attack("Nobody");
	b.attack("Nobody");
	c.attack("Nobody");
	std::cout << "\n";

	std::cout << GREEN << "\n=== Creating Named and Copy FragTrap ===\n" << RESET;
	std::cout << "d: ";
	FragTrap d(c);
	std::cout << "e: ";
	FragTrap e("Copycat");
	d.attack("Someone");
	e = d;
	e.attack("Another");
	std::cout << "\n";

	std::cout << GREEN << "\n=== Attack Until Energy Runs Out (FragTrap) ===\n" << RESET;
	for (int n = 0; n < 105; ++n) {
		std::cout << "[" << n+1 << "] ";
		c.attack("Target");
	}
	std::cout << "\n";

	std::cout << GREEN << "\n=== Overkill and Repair Edge Cases ===\n" << RESET;
	d.takeDamage(1000);
	d.attack("Nobody");
	d.beRepaired(10);
	std::cout << "\n";

	std::cout << GREEN << "\n=== guardGate() and highFivesGuys() Test ===\n" << RESET;
	b.guardGate();
	c.highFivesGuys();
	d.highFivesGuys();
	std::cout << "\n";

	std::cout << GREEN << "\n=== End of Main ===\n" << RESET;
	return 0;
}
