/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:07:36 by bewong            #+#    #+#             */
/*   Updated: 2025/04/22 14:07:36 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
			std::string	_name;
			AMateria	*inventory[4];
	public:
			Character();
			Character(std::string const& name);
			Character(const Character& other);
			Character& operator=(const Character& rhs);
			virtual	~Character();

			std::string const	&getName() const;
			void				equip(AMateria* m);
			void				unequip(int idx);
			void				use(int idx, ICharacter& target);
			AMateria*			getMateria(int idx) const;
};

#endif
