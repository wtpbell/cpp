/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:44:20 by bewong            #+#    #+#             */
/*   Updated: 2025/09/12 11:44:20 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <sstream>

#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define BOLD "\033[1m"
#define UNDER "\033[4m"
#define RESET "\033[0m"
#define RED "\033[0;91m"
#define CYAN "\033[0;96m"
#define MAGENTA "\033[0;95m"
#define ORANGE "\033[38;5;208m"

// std::ostringstream represents an in-memory string stream
//  << written into an internal std::string buffer not printed
//  then i can past it to throw by .str()

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	auto it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		std::ostringstream oss;
		oss << "Value " << value << " not found";
		throw std::runtime_error(oss.str());
	}
	return (it);
}
#endif  // EASYFIND_HPP
