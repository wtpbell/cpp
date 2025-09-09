/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:47:27 by bewong            #+#    #+#             */
/*   Updated: 2025/09/09 19:47:27 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <type_traits>

template <typename T, typename F>
void iter(T *array, size_t len, F func)
{
	static_assert(std::is_pointer<T>::value, "Type T must be a pointer for iter");
	for (size_t i = 0; i < len; i++)
		func(array[i]);
} 
template <typename T, typename F>
void iter(const T *array, size_t len, F func)
{
	static_assert(std::is_pointer<T>::value, "Type T must be a pointer for iter");
	for (size_t i = 0; i < len; i++)
		func(array[i]);
} 
#endif
