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

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << GREEN << "\n=== Creating Default DiamondTrap ===\n" << RESET;
	std::cout << "a: ";
	DiamondTrap a;
	a.whoAmI();
	std::cout << "\n";

	std::cout << GREEN << "\n=== Creating Named DiamondTrap ===\n" << RESET;
	std::cout << "b: ";
	DiamondTrap b("Idiot");
	b.whoAmI();
	b.attack("Dumbass");
	std::cout << "\n";

	std::cout << GREEN << "\n=== Copying DiamondTrap (Copy Constructor) ===\n" << RESET;
	std::cout << "c: ";
	DiamondTrap c(b);
	c.whoAmI();
	c.attack("Baka");
	std::cout << "\n";

	std::cout << GREEN << "\n=== Assigning DiamondTrap (Copy Assignment) ===\n" << RESET;
	a = c;
	a.whoAmI();
	std::cout << "\n";

	std::cout << GREEN << "\n=== Injuring DiamondTrap and calling whoAmI() ===\n" << RESET;
	a.takeDamage(150);
	a.whoAmI();
	std::cout << "\n";

	std::cout << GREEN << "\n=== Testing: Attack until energy runs out ===\n" << RESET;
	std::cout << "d: ";
	DiamondTrap d("EnergyBot");
	for (int i = 0; i < 55; ++i) {
		std::cout << "[" << i+1 << "] ";
		d.attack("Target");
	}
	std::cout << "d: ";
	d.whoAmI();
	std::cout << "\n";

	std::cout << GREEN << "\n=== Testing: Repair after damage ===\n" << RESET;
	d.takeDamage(40);
	d.beRepaired(20);
	d.takeDamage(90);
	d.beRepaired(10);
	d.whoAmI();
	std::cout << "\n";

	std::cout << GREEN << "\n=== Testing: guardGate() and highFivesGuys() ===\n" << RESET;
	std::cout << "e: ";
	DiamondTrap e("Specialist");
	e.guardGate();
	e.highFivesGuys();
	e.takeDamage(200);
	e.guardGate();
	e.highFivesGuys();
	std::cout << "\n";

	std::cout << GREEN << "\n=== Testing: Copy/assignment after damage ===\n" << RESET;
	std::cout << "f: ";
	DiamondTrap f("Copycat");
	f.takeDamage(60);
	DiamondTrap g = f;
	DiamondTrap h("Another");
	h = f;
	g.whoAmI();
	h.whoAmI();
	std::cout << "\n";

	std::cout << GREEN << "\n=== Testing: Multiple DiamondTraps interaction ===\n" << RESET;
	std::cout << "x: ";
	DiamondTrap x("SmartAssOne");
	std::cout << "y: ";
	DiamondTrap y("SmartAssTwo");
	x.attack("SmartAssTwo");
	y.takeDamage(30);
	y.attack("SmartAssOne");
	x.takeDamage(40);
	x.whoAmI();
	y.whoAmI();
	std::cout << "\n";

	std::cout << GREEN << "\n=== End of Main ===\n" << RESET;

	return(0);

}
