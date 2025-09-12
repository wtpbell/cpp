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

# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"
# define CYAN	"\033[0;96m"
# define MAGENTA "\033[0;95m"
#define ORANGE	"\033[38;5;208m"

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

