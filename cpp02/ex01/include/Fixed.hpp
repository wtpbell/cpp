/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/14 17:08:12 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/15 17:26:32 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
			int					_fixedPoint;
			static const int	_fractionalBits = 8;

	public:
			Fixed();
			Fixed(const int value);
			Fixed(const float value);
			Fixed(const Fixed& other);
			Fixed& operator=(const Fixed& other);
			~Fixed();

			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;
		};
		
	std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
