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
#include <exception>

template <typename T>
Array<T>::Array(uint32_t n) : size_(n)
{
	array_ = new T[n]; // allocate the actual memory with T type and size n
}

template <typename T>
Array<T>::Array(const Array& other)
: size_(other.size_), array_(other.size_ > 0 ? new T[other.size_] : nullptr)
{
	try
	{
		for (uint32_t i = 0; i < size_; i++)
			array_[i] = other.array_[i];
	}
	catch (...)
	{
		delete[] array_;
		throw;
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
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
//move constructor
template <typename T>
Array<T>::Array(Array&& other) noexcept
: size_(std::exchange(other.size_, 0)),  array_(std::exchange(other.array_, nullptr)) {}

template <typename T>
Array<T>&	Array<T>::operator=(Array&& other) noexcept
{
	if (this != &other)
	{
		delete[] array_;
		size_  = std::exchange(other.size_, 0);
		array_ = std::exchange(other.array_, nullptr);
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](uint32_t index)
{
	if (index >= size_)
		throw std::out_of_range("Array index out of range");
	return (array_[index]);
}

template <typename T>
const T&	Array<T>::operator[](uint32_t index) const
{
	if (index >= size_)
		throw std::out_of_range("Array index out of range");
	return (array_[index]);
}

template <typename T>
uint32_t	Array<T>::size(void) const
{
	return (size_);
}
