/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:30:32 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 18:30:32 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#define BOLD	"\033[1m"
#define BLUE	"\033[0;94m"
#define GREEN	"\033[0;92m"
#define YELLOW	"\033[0;93m"
#define RED		"\033[0;91m"
#define CYAN	"\033[0;96m"
#define MAGENTA	"\033[0;95m"
#define RESET	"\033[0m"
#define ORANGE	"\033[38;5;208m"

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string	ideas[100];

	public:
			Brain();
			Brain(const Brain& src);
			Brain& operator=(const Brain& rhs);
			~Brain();

			void	setIdea(unsigned int index, const std::string& idea);
			void	printIdea(void) const;
};

#endif
