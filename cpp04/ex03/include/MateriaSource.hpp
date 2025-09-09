/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:33:30 by bewong            #+#    #+#             */
/*   Updated: 2025/04/22 14:33:30 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
			AMateria	*inventory[4];

	public:
			MateriaSource();
			MateriaSource(const MateriaSource& other);
			MateriaSource& operator=(const MateriaSource& rhs);
			~MateriaSource();

			void		learnMateria(AMateria* m);
			AMateria	*createMateria(std::string const& type);
};

#endif
