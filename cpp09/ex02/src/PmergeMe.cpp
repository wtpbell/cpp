/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/25 11:49:52 by bewong        #+#    #+#                 */
/*   Updated: 2025/09/25 11:57:46 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>

int	PmergeMe::jacobsthalNum(size_t n)
{
	return ((std::pow(2, n) - std::pow(-1, n)) / 3);
}

