/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:14:42 by bewong            #+#    #+#             */
/*   Updated: 2025/09/24 19:14:42 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <algorithm>

class	PmergeMe
{
	public:
		PmergeMe() = default;
		PmergeMe(const PmergeMe& other) = default;
		PmergeMe& operator=(const PmergeMe& other) = default;
		~PmergeMe() = default;

		PmergeMe(PmergeMe&& other) noexcept = default;
		PmergeMe& operator=(PmergeMe&& other) noexcept = default;

		static int	mergeSort(std::vector<int>& vec);
		static int	mergeSort(std::list<int>& lst);
		int			jacobsthalNum(size_t n);

	private:
		
};

#endif // PMERGEME_HPP
