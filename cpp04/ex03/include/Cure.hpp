/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:47:10 by bewong            #+#    #+#             */
/*   Updated: 2025/04/22 14:47:10 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
			Cure();
			Cure(const Cure& other);
			Cure(const std::string& type);
			Cure& operator=(const Cure& rhs);
			~Cure();

			AMateria*	clone() const override;
			void		use(ICharacter& target) override;
};

#endif
