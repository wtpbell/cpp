/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:59:59 by bewong            #+#    #+#             */
/*   Updated: 2025/09/12 15:59:59 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

// .reserve ensure the vector has at least capacity for N elements
// if the capacity is already greater or equal to N, it does nothing
// otherwise std::vector will re-allocate memory for N elements
Span::Span(uint32_t N)
{
	storage_.reserve(N);
}

size_t	Span::size(void) const
{
	return (storage_.size());
}

size_t	Span::capacity(void) const
{
	return (storage_.capacity());
}

int	Span::shortestSpan(void) const
{
	if (storage_.size() < 2)
		throw std::runtime_error("Not enough elements in container");
	std::vector<int> sorted = storage_;
	std::sort(sorted.begin(), sorted.end(), std::less<int>());

	int min = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
		min = std::min(min, sorted[i] - sorted[i - 1]);
	return (min);
}

//std::minmax_element return std::pair<iterator, iterator>
// min_it = result.first(min); max_it = result.second(max); structured binding 
// auto [a, b] can destructure pairs
int Span::longestSpan(void) const
{
	if (storage_.size() < 2)
		throw std::runtime_error("Not enough elements in container");
	auto [min_it, max_it] = std::minmax_element(storage_.begin(), storage_.end());
	return (*max_it - *min_it);
}

// push_back ~ emplace_back
// push_back create a temporary object, copy / move it into the container
// emplace_back construct the object directly in the container, more efficient
void	Span::addNumber(int n)
{
	if (storage_.size() >= storage_.capacity())
		throw std::runtime_error("Container is full");
	storage_.emplace_back(n);
}

int Span::operator[](size_t index) const
{
	if (index >= storage_.size())
		throw std::runtime_error("Index out of bounds");
	return (storage_[index]);
}
