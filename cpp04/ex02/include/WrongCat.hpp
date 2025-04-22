/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:54:35 by bewong            #+#    #+#             */
/*   Updated: 2025/04/21 15:54:35 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
			WrongCat();
			WrongCat(const WrongCat &src);
			WrongCat &operator=(const WrongCat &rhs);
			~WrongCat();

			void	makeSound(void) const;
};

#endif
