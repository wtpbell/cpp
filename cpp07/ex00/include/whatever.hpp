/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:32:51 by bewong            #+#    #+#             */
/*   Updated: 2025/09/09 17:32:51 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#	define WHATEVER_HPP

#include <iostream>
#include <type_traits>

# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"
# define CYAN	"\033[0;96m"
# define MAGENTA "\033[0;95m"
#define ORANGE	"\033[38;5;208m"

//static_assert is a compile-time assertion that checks conditions at compile time.
template <typename T>
void	swap(T &a, T&b)
{
	static_assert(std::is_copy_constructible<T>::value, 
		"Type T must be copy constructible for swap"); // we make copy to tmp
	static_assert(std::is_move_assignable<T>::value,
		"Type T must be move assignable for swap"); // we do assignment
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T&	min(const T &a, const T &b)
{
	return ((a < b) ? a : b);
}

template <typename T>
const T&	max(const T &a, const T &b)
{
	return ((a > b) ? a : b);
}
#endif
