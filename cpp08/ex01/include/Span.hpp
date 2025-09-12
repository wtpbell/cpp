/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:59:32 by bewong            #+#    #+#             */
/*   Updated: 2025/09/12 14:59:32 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"
# define CYAN	"\033[0;96m"
# define MAGENTA "\033[0;95m"
# define ORANGE	"\033[38;5;208m"

class Span
{
	public:
		Span(void) = default;
		Span(const Span& other) = default;
		Span& operator=(const Span& other) = default;
		~Span(void) = default;

		Span(uint32_t N);

		Span(Span&& other) noexcept = default;
		Span& operator=(Span&& other) noexcept = default;

		size_t		size(void) const;
		size_t		capacity(void) const;
		int			shortestSpan(void) const;
		int			longestSpan(void) const;
		void		addNumber(int n);
		template <typename Iterator>
		void		addNumber(Iterator begin, Iterator end);
		
	private:
		std::vector<int> storage_;
};

#endif // SPAN_HPP
