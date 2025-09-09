/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:47:14 by bewong            #+#    #+#             */
/*   Updated: 2025/04/22 14:47:14 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
			Ice();
			Ice(const Ice& other);
			Ice(const std::string& type);
			Ice& operator=(const Ice& rhs);
			~Ice();

			AMateria*	clone() const override;
			void		use(ICharacter& target) override;
};

#endif
