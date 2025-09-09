/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:58:33 by bewong            #+#    #+#             */
/*   Updated: 2025/04/22 22:39:53 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main(void)
{
	AMateria* groundMaterias[16];
	int groundCount = 0;

	std::cout << CYAN << "\n===== Test 1: Learn, Equip, Use =====\n" << RESET;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << CYAN << "\n===== Test 2: Inventory Full, Unequip, Unknown =====\n" << RESET;
	// Fill inventory
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	// Try to equip when full
	tmp = src->createMateria("ice");
	bool inventoryFull = true;
	for (int i = 0; i < 4; ++i)
		if (((Character*)me)->getMateria(i) == nullptr)
			inventoryFull = false;
	if (!inventoryFull)
		me->equip(tmp);
	else if (tmp && groundCount < 16)
		groundMaterias[groundCount++] = tmp;
	// Unequip slot 2 and store
	AMateria* unequipped = ((Character*)me)->getMateria(2);
	me->unequip(2);
	if (unequipped && groundCount < 16)
		groundMaterias[groundCount++] = unequipped;
	// Refill slot 2
	tmp = src->createMateria("cure");
	me->equip(tmp);
	// Try invalid unequip
	me->unequip(10);
	// Try unknown materia
	tmp = src->createMateria("fire");
	if (tmp && groundCount < 16)
		groundMaterias[groundCount++] = tmp;

	std::cout << CYAN << "\n===== Test 3: Deep Copy & Assignment =====\n" << RESET;
	Character* clone = new Character(*(Character*)me);
	clone->use(0, *bob);
	AMateria* cloneUnequipped = clone->getMateria(0);
	clone->unequip(0);
	if (cloneUnequipped && groundCount < 16)
		groundMaterias[groundCount++] = cloneUnequipped;
	me->use(0, *bob);
	std::cout << "Clone uses slot 0 on bob (should be empty): ";
	clone->use(0, *bob);

	std::cout << CYAN << "\n===== Test 4: Assignment Operator =====\n" << RESET;
	Character assigned;
	assigned = *(Character*)me;
	std::cout << "Assigned uses slot 1 on bob: ";
	assigned.use(1, *bob);

	std::cout << CYAN << "\n===== Test 5: MateriaSource Copy =====\n" << RESET;
	MateriaSource* src2 = new MateriaSource(*(MateriaSource*)src);
	tmp = src2->createMateria("ice");
	std::cout << "src2 creates and equips 'ice' for assigned: ";
	bool inventoryFull_3 = true;
	for (int i = 0; i < 4; ++i)
	{
		if (assigned.getMateria(i) == nullptr)
		{
			inventoryFull_3 = false;
			break ;
		}
	}
	if (!inventoryFull_3 && tmp)
		assigned.equip(tmp);
	else if (tmp && groundCount < 16)
		groundMaterias[groundCount++] = tmp;

	assigned.use(3, *bob);
	delete src2;

	std::cout << CYAN << "\n===== Test 6: Memory Cleanup =====\n" << RESET;
	for (int i = 0; i < groundCount; ++i)
		delete groundMaterias[i];

	delete clone;
	delete bob;
	delete me;
	delete src;

	std::cout << CYAN << "\nAll tests completed. Check for memory leaks!\n" << RESET;
	return 0;
}

