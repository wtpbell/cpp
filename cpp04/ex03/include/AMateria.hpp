/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:00:01 by bewong            #+#    #+#             */
/*   Updated: 2025/04/22 12:00:01 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#define BOLD	"\033[1m"
#define BLUE	"\033[0;94m"
#define GREEN	"\033[0;92m"
#define YELLOW	"\033[0;93m"
#define RED		"\033[0;31m"
#define CYAN	"\033[0;96m"
#define MAGENTA	"\033[0;95m"
#define RESET	"\033[0m"
#define ORANGE	"\033[38;5;208m"

#include <string>
#include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
			std::string			_type;
	public:
			AMateria();
			AMateria(std::string const& type);
			AMateria(const AMateria& other);
			AMateria& operator=(const AMateria& rhs);
			virtual	~AMateria();

			std::string const&	getType() const;
			virtual AMateria*	clone() const = 0;
			virtual void		use(ICharacter& target);
};

#endif

