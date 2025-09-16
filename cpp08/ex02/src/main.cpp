/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:41:32 by bewong            #+#    #+#             */
/*   Updated: 2025/09/16 09:41:32 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <any>
#include <vector>
#include <list>
#include <stack>
#include <iostream>

#include <deque>
#include <array>
#include <typeinfo>


// https://eel.is/c++draft/expr.prim#nt:requires-expression
// https://mariusbancila.ro/blog/2022/06/20/requires-expressions-and-requires-clauses-in-cpp20/
// requires expressions is a compile time expression of type bool, provide constraints on template arguments
// requires-clause,  specify a constraint on a template argument or function argument
// first requires is requires-clause, second requires is template parameter

// for std::vector, std::deque, std::list
// template <typename Container, typename T>
// requires requires (Container c, T value) { c.emplace_back(value); }
// void	addBack(Container& container, T&& value) //T&& forwading reference
// {
// 	// If value was passed as an rvalue, std::forward will cast it to an rvalue reference (T&&)
// 	// If value was passed as an lvalue, std::forward will preserve it as an lvalue reference
// 	container.emplace_back(std::forward<T>(value)); //forward and reserve the value to the container;
// }

// // for std::stack, std::queue
// template <typename Container, typename T>
// requires requires (Container c, T value) { c.push(value); }
// void	addBack(Container& container, T&& value)
// {
// 	container.push(std::forward<T>(value));
// }
// // for std::deque, std::forward_list, std::list
// template <typename Container, typename T>
// requires requires (Container c, T value) { c.emplace_front(value); }
// void	addFront(Container& container, T&& value)
// {
// 	container.emplace_front(std::forward<T>(value));
// }

// // for std::stack, std::queue
// template <typename Container>
// requires requires (Container c) { c.pop(); }
// void	popBack(Container& container)
// {
// 	if(!container.empty())
// 		container.pop();
// }

// // for std::vector, std::deque, std::list
// template <typename Container>
// requires requires (Container c) { c.pop_back(); }
// void	popBack(Container& container)
// {
// 	if(!container.empty())
// 		container.pop_back();
// }

// // for std::deque, std::forward_list, std::list
// template <typename Container>
// requires requires (Container c) { c.pop_front();}
// void	popFront(Container& container)
// {
// 		container.pop_front();
// }
// template <typename Container>
// requires requires (Container c) { c.size();}
// size_t	size(Container& container)
// {
// 		return (container.size());
// }

template <typename Container, typename T>
void	addToContainer(Container& container, T&& value)
{
	if constexpr (requires { container.emplace_back(std::forward<T>(value)); })
		container.emplace_back(std::forward<T>(value));
	else if constexpr (requires { container.push(std::forward<T>(value)); })
		container.push(std::forward<T>(value));
	else
		throw std::runtime_error("Container type not supported");
}

template <typename Container>
void	popFromContainer(Container& container)
{
	if (container.empty())
		return ;
	if constexpr (requires { container.pop(); })
		container.pop();
	else if constexpr (requires { container.pop_back(); })
		container.pop_back();
	else
		throw std::runtime_error("Container type not supported");
}

template <typename Container>
void	printContainerDetail(const Container& container, const std::string& containerType)
{
	std::cout << containerType << " elements: ";
	for (const auto& val : container)
		std::cout << val << " ";
	std::cout << "\n" << containerType << " size: " << container.size() << std::endl;
}

void	printContainerInfo(const std::vector<std::any>& container)
{
	for (const auto& ele : container)
	{
		try
		{
			if (ele.type() == typeid(std::list<int>))
			{
				const auto& list = std::any_cast<const std::list<int>&>(ele);
				printContainerDetail(list, "list");
			}
			else if (ele.type() == typeid(MutantStack<int>))
			{
				const auto& mutantStack = std::any_cast<const MutantStack<int>&>(ele);
				printContainerDetail(mutantStack, "mutantStack");
			}
			else if (ele.type() == typeid(std::deque<int>))
			{
				const auto& deque = std::any_cast<const std::deque<int>&>(ele);
				printContainerDetail(deque, "deque");
			}
			else if (ele.type() == typeid(std::vector<std::string>))
			{
				const auto& vec = std::any_cast<const std::vector<std::string>&>(ele);
				printContainerDetail(vec, "vector<string>");
			}
			else if (ele.type() == typeid(std::vector<int>))
			{
				const auto& vec = std::any_cast<const std::vector<int>&>(ele);
				printContainerDetail(vec, "vector<int>");
			}
			else if (ele.type() == typeid(std::array<int, 5>))
			{
				const auto& array = std::any_cast<const std::array<int, 5>&>(ele);
				printContainerDetail(array, "array");
			}
			else if (ele.type() == typeid(std::array<std::string, 5>))
			{
				const auto& arr = std::any_cast<const std::array<std::string, 5>&>(ele);
				printContainerDetail(arr, "array");
			}
			else
			{
				std::cerr << "Unsupported container type: " << ele.type().name() << std::endl;
			}
		}
		catch (const std::bad_any_cast& e)
		{
			std::cerr << "Type error: " << e.what() << std::endl;
		}
	}
}

void	testMutantStack(void)
{
	std::cout << CYAN << "\n============= Testing MutantStack =============" << RESET << std::endl;

	std::cout << ORANGE << "\n=== Testing MutantStack Basic ===" << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "After pop(), size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "mstack element: " << *it << std::endl;
		++it;
	}

	std::cout << ORANGE << "\n=== Testing MutantStack copy constructor ===" << RESET << std::endl;
	MutantStack<int> s(mstack);
	MutantStack<int>::iterator start = s.begin();
	MutantStack<int>::iterator end = s.end();
	while (start != end)
	{
		std::cout << "s element: " << *start << std::endl;
		++start;
	}

	std::cout << ORANGE << "\n=== Testing MutantStack copy assignment operator ===" << RESET << std::endl;
	MutantStack<int> s2;
	s2 = mstack;
	MutantStack<int>::iterator start2 = s2.begin();
	MutantStack<int>::iterator end2 = s2.end();
	while (start2 != end2)
	{
		std::cout << "s2 element: " << *start2 << std::endl;
		++start2;
	}

	std::cout << ORANGE << "\n=== Testing MutantStack reverse iterator ===" << RESET << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << "mstack element: " << *rit << std::endl;
		++rit;
	}

	std::cout << ORANGE << "\n=== Testing MutantStack const reverse iterator ===" << RESET << std::endl;
	MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.rend();
	while (crit != crite)
	{
		std::cout << "mstack element: " << *crit << std::endl;
		++crit;
	}

	std::cout << ORANGE << "\n=== Testing MutantStack move constructor ===" << RESET << std::endl;
	MutantStack<int> s3(std::move(mstack));
	MutantStack<int>::iterator start3 = s3.begin();
	MutantStack<int>::iterator end3 = s3.end();
	while (start3 != end3)
	{
		std::cout << "s3 element: " << *start3 << std::endl;
		++start3;
	}
	std::cout << "After move constructor, size: " << mstack.size() << std::endl;
}

void	testContainerWrapper(void)
{
	std::cout << CYAN << "\n============= Testing Container Wrapper =============" << RESET << std::endl;
	
	std::vector<std::any> vec;
	{
		MutantStack<int> mstack;
		for (int i = 0; i < 5; i++)
			addToContainer(mstack, i);
		vec.push_back(mstack);
	}

	{
		std::array<std::string, 5> arr;
		for (size_t i = 0; i < arr.size(); i++)
			arr[i] = "hello" + std::to_string(i);
		vec.push_back(arr);
	}

	{
		std::deque<int> deque;
		for (int i = 0; i < 5; i++)
			addToContainer(deque, i * 3);
		popFromContainer(deque);
		vec.push_back(deque);
	}

	{
		std::list<int> list;
		for (int i = 0; i < 5; i++)
			addToContainer(list, i * 4);
		vec.push_back(list);
	}

	{
		std::vector<int> v;
		for (int i = 0; i < 5; i++)
			addToContainer(v, i * 2);
		vec.push_back(v);
	}

	{
		std::vector<std::string> st;
		for (int i = 0; i < 5; i++)
			addToContainer(st, "bye" + std::to_string(i));
		vec.push_back(st);
	}

	printContainerInfo(vec);
}

int	main(void)
{
	testMutantStack();
	testContainerWrapper();
	return 0;
}
