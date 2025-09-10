/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:49:21 by bewong            #+#    #+#             */
/*   Updated: 2025/09/10 15:49:21 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(uint32_t n) : size_(n)
{
	array_ = new T[n]; // allocate the actual memory with T type and size n
}

template <typename T>
Array<T>::Array(const Array& other) : size_(other.size_), array_(nullptr)
{
	if (other.size_ > 0) // handle empty array
		{
			array_ = new T[other.size_];
			try
			{
				for (uint32_t i = 0; i < other.size_; i++)
					array_[i] = other.array_[i]; //copy elements, can throw exception
			}
			catch (...)
			{
				delete[] array_;
				throw ;
			}
		}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other) //prevent self assignment
	{
		T*	newArray = nullptr;
		if (other.size_ > 0) // handle empty array
		{
			newArray = new T[other.size_];
			try
			{
				for (uint32_t i = 0; i < other.size_; i++)
					newArray[i] = other.array_[i]; //copy elements, can throw exception
			}
			catch (...)
			{
				delete[] newArray;
				throw ;
			}
		}
		delete[] array_;
		array_ = newArray;
		size_ = other.size_;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] array_;
}


