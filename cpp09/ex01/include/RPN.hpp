/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:15:21 by bewong            #+#    #+#             */
/*   Updated: 2025/09/21 18:15:21 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	public:
		RPN(void) = default;
		RPN(const RPN& other) = default;
		RPN& operator=(const RPN& other) = default;
		~RPN(void) = default;

		RPN(RPN&& other) noexcept = default;
		RPN& operator=(RPN&& other) noexcept = default;

		int			calculate(const std::string& expression);

	private:
		std::stack<int>	stack_;
		int				calculateOperation(int left, int right, char op);
};

#endif // RPN_HPP
