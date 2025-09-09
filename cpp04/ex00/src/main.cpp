/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:43:51 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 15:43:51 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << CYAN << "\n=== Animal Initialization ===\n" << RESET;
	const Animal* unknown = new Animal();
	const Animal* doggy = new Dog();
	const Animal* kitty = new Cat();
	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongCat* wrong_kitty = new WrongCat();

	std::cout << CYAN << "\n=== Animal types and sounds ===\n" << RESET;
	std::cout << BOLD << "unknown: " << *unknown << RESET << std::endl;
	unknown->makeSound();
	std::cout << std::endl;

	std::cout << BOLD << "doggy: " << *doggy << RESET << std::endl;
	doggy->makeSound();
	std::cout << std::endl;

	std::cout << BOLD << "kitty: " << *kitty << RESET << std::endl;
	kitty->makeSound();
	std::cout << std::endl;

	std::cout << BOLD << "wrong_animal: " << *wrong_animal << RESET << std::endl;
	wrong_animal->makeSound();
	std::cout << std::endl;

	std::cout << BOLD << "wrong_kitty: " << *wrong_kitty << RESET << std::endl;
	wrong_kitty->makeSound();
	std::cout << std::endl;

	std::cout << CYAN << "=== END ===" << std::endl << RESET;
	delete unknown;
	delete doggy;
	delete kitty;
	delete wrong_animal;
	delete wrong_kitty;

	return (0);
}
