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
	ClapTrap a;
	ClapTrap b("Idiot");
	ClapTrap c(b);
	ClapTrap d("Dumbass");
	ClapTrap e("Fragtrap");
	ScavTrap g("Baka");
	ScavTrap h(g);

	a.attack("Idiot");
	b.attack("Dumbass");
	c.attack("Fragtrap");
	d.attack("Idiot");
	e.attack("Dumbass");
	g.attack("Random enemy");
	h.attack("Random enemy");

	a.takeDamage(13);
	b.takeDamage(10);
	c.takeDamage(1000);
	d.takeDamage(4);
	e.takeDamage(0);
	a.takeDamage(13);
	g.takeDamage(2);
	h.takeDamage(13);
	

	a.beRepaired(2);
	b.beRepaired(9);
	c.beRepaired(2);
	d.beRepaired(14);
	e.beRepaired(2);
	g.beRepaired(0);
	h.beRepaired(3);

	g.guardGate();
	h.guardGate();
}
