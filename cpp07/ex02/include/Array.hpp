/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:28:39 by bewong            #+#    #+#             */
/*   Updated: 2025/09/10 14:28:39 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <utility>
#include <cstdint>

template <typename T>
class	Array
{
	public:
		Array(void) = default;
		Array(uint32_t n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array(void);

		Array(Array&& other) noexcept;
		Array& operator=(Array&& other) noexcept;
		
		//overloading [] operator to access elements in array, useful for checking bounds
		// must return by reference in function as array element can be put on left side (lvalue)
		T&			operator[](uint32_t index);
		const T&	operator[](uint32_t index) const;
		uint32_t	size(void) const;

	private:
		uint32_t	size_ = 0;
		T*			array_ = nullptr;

};

#include "Array.tpp"

#endif //ARRAY_HPP

