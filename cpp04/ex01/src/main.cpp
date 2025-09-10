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

	std::cout << BOLD << "kitty: " << *kitty<< RESET << std::endl;
	kitty->makeSound();
	std::cout << std::endl;

	std::cout << BOLD << "wrong_animal: " << *wrong_animal << RESET << std::endl;
	wrong_animal->makeSound();
	std::cout << std::endl;

	std::cout << BOLD << "wrong_kitty: " << *wrong_kitty << RESET << std::endl;
	wrong_kitty->makeSound();
	std::cout << std::endl;
	
	std::cout << CYAN << "\n=== END ===\n" << RESET;
	delete unknown;
	delete doggy;
	delete kitty;
	delete wrong_animal;
	delete wrong_kitty;

	std::cout << CYAN << "\n===Cat brain initialization ===\n" << RESET;
	Cat* helloKitty = new Cat();
	std::cout << BOLD << "helloKitty: " << *helloKitty << RESET << std::endl;
	helloKitty->makeSound();
	helloKitty->setIdea(0, "I'm hungry.......");
	helloKitty->setIdea(23, "Give me all the food!!!");
	std::cout << "helloKitty: ";
	helloKitty->printIdea();
	std::cout << std::endl;

	Cat* lazyKitty = new Cat();
	std::cout << BOLD << "lazyKitty: " << *lazyKitty << RESET << std::endl;
	lazyKitty->makeSound();
	lazyKitty->setIdea(0, "I dont wanna move....");
	lazyKitty->setIdea(23, "Feed me, feed me, feed me.....");
	std::cout << "lazyKitty: ";
	lazyKitty->printIdea();
	std::cout << std::endl;

	std::cout << CYAN << "\n=== END ===\n" << RESET;
	delete helloKitty;
	delete lazyKitty;

	std::cout << CYAN << "\n===Dog brain initialization ===\n" << RESET;
	Dog* snoppy = new Dog();
	std::cout << BOLD << "snoppy: " << *snoppy << RESET << std::endl;
	snoppy->makeSound();
	snoppy->setIdea(1, "Where is the ball?");
	snoppy->setIdea(02, "I know you are hiding it.");
	snoppy->setIdea(10, "Don't underestimate my nose, i gonna find it.");
	snoppy->setIdea(100, "Aha, i found it, you bastards.");
	snoppy->setIdea(101, "You bastards, i found it.");
	std::cout << "Snoppy: ";
	snoppy->printIdea();
	std::cout << std::endl;

	Dog* goffy = new Dog(*snoppy);
	std::cout << BOLD << "goffy: " << *goffy << RESET << std::endl;
	goffy->makeSound();
	goffy->setIdea(1, "I'm so sleepy.....ZZZZZZZZ.");
	goffy->setIdea(9, "Really?! Don't say I didn't warn you.");
	goffy->setIdea(2, "Leave me alone, otherwise I gonna bite your ass.");
	goffy->setIdea(70, "Now you satisfied? You let me take off your pants.");
	goffy->setIdea(100, "You bastards, you better leave right now.");
	std::cout << "Goffy: ";
	goffy->printIdea();
	std::cout << "Snoppy: ";
	snoppy->printIdea();

	std::cout << CYAN << "\n=== END ===\n" << RESET;
	delete snoppy;
	delete goffy;

	return (0);
}

