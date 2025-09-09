/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/08 16:02:08 by bewong        #+#    #+#                 */
/*   Updated: 2025/09/08 16:27:56 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

struct Data
{
	std::string name;
	int age;
};

class Serializer
{
public:
	Serializer() = delete;
	Serializer(const Serializer&) = delete;
	Serializer& operator=(const Serializer&) = delete;
	~Serializer() = delete;
	Serializer(const Serializer&&) noexcept = delete;
	Serializer& operator=(const Serializer&&) noexcept = delete;

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
};

#endif
