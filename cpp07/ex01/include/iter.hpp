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

// template <typename T, typename F>
// void iter(T *array, size_t len, F func)
// {
// 	if (!array || !func)
// 		return ;
// 	for (size_t i = 0; i < len; i++)
// 		func(array[i]);
// } 
// template <typename T, typename F>
// void iter(const T *array, size_t len, F func)
// {
// 	if (!array || !func)
// 		return ;
// 	for (size_t i = 0; i < len; i++)
// 		func(array[i]);
// } 

template <typename T, typename F>
void	iter(T *array, size_t len, F func)
{
	if (!array || !func)
		return ;
	for (size_t i = 0; i < len; i++)
	{
		if constexpr (std::is_const_v<std::remove_pointer_t<T>>)
			func(array[i]);
		else
			func(array[i]);
	}
}
#endif
