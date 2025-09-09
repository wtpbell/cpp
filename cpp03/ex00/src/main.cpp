/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:00:31 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 14:54:42 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << GREEN << "\n=== Creating Default ClapTrap ===\n" << RESET;
	std::cout << "a: ";
	ClapTrap a;
	a.attack("Nobody");
	a.takeDamage(5);
	a.beRepaired(3);
	std::cout << "\n";

	std::cout << GREEN << "\n=== Creating Named ClapTrap ===\n" << RESET;
	std::cout << "b: ";
	ClapTrap b("Idiot");
	b.attack("Dumbass");
	b.takeDamage(10);
	b.beRepaired(5);
	std::cout << "\n";

	std::cout << GREEN << "\n=== Copy Constructor & Assignment ===\n" << RESET;
	std::cout << "c: ";
	ClapTrap c(b);
	c.attack("Fragtrap");
	std::cout << "d: ";
	ClapTrap d("Dumbass");
	d = c;
	d.attack("Idiot");
	std::cout << "\n";

	std::cout << GREEN << "\n=== Attack Until Energy Runs Out ===\n" << RESET;
	for (int i = 0; i < 12; ++i) {
		std::cout << "[" << i+1 << "] ";
		a.attack("Target");
	}
	std::cout << "\n";

	std::cout << GREEN << "\n=== Overkill and Repair Edge Cases ===\n" << RESET;
	ClapTrap e("Fragtrap");
	e.takeDamage(1000);
	e.attack("Nobody");
	e.beRepaired(10);
	std::cout << "\n";

	std::cout << GREEN << "\n=== End of Main ===\n" << RESET;
	return 0;
}
