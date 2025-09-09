/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:40:02 by bewong            #+#    #+#             */
/*   Updated: 2025/09/09 14:25:07 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ctime>
#include <exception>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
// Requires RTTI (Run-Time Type Information)
// Only works with polymorphic types (classes with virtual functions)
// Slightly more expensive than other casts due to runtime type checking
// Returns nullptr for pointers (or throws for references) if the cast fails

Base* generate(void)
{
	int num = rand() % 3;

	if (num == 0)
		return (new A());

	else if (num == 1)
		return (new B());
	else
		return (new C());
}
// for pointer, if cast fails, return nullptr
void identify(Base* p)
{
	if (A* a = dynamic_cast<A*>(p))
		std::cout << "A ptr: " << a << std::endl;
	else if (B* b = dynamic_cast<B*>(p))
		std::cout << "B ptr: " << b << std::endl;
	else if (C* c = dynamic_cast<C*>(p))
		std::cout << "C ptr: " << c << std::endl;
}
// for reference, if cast fails, throw std::bad_cast
void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A ref: " << &a << std::endl;
	}
	catch (std::bad_cast& e)
	{}

	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "B ref: " << &b << std::endl;
	}
	catch (std::bad_cast& e)
	{}

	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "C ref: " << &c << std::endl;
	}
	catch (std::bad_cast& e)
	{}
}

void run(void)
{
	Base* base;

	base = generate();
	identify(base);
	identify(*base);
	delete (base);
}

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		try
		{
			std::cout << "\n=== Run Case " << i << " ===" << std::endl;
			run();
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	Base* base;
	std::cout << "\n=== Run Casting fail ===" << std::endl; // cant cast to siblings
	{
		Base* bp = new A(); //bp point to A object
		C* cp = dynamic_cast<C*>(bp); //try to cast A* to C*
		// checks at runtime if the obj being pointed to A, is actually a C obj
		if (cp == nullptr)
			std::cout << "Casting failed (expected)" << std::endl;
		else
			std::cout << "Casting succeeded (unexpected)" << std::endl;
		delete (bp);
	}

	std::cout << "\n=== Run Edge Case ===" << std::endl;
	base = NULL;
	identify(base);
	std::cout << "Skipping dereference of NULL pointer" << std::endl;
	return (0);
}
