/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/16 09:30:56 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/16 09:30:57 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BOLD	"\033[1m"
# define UNDER	"\033[4m"
# define RESET	"\033[0m"
# define RED	"\033[0;91m"
# define CYAN	"\033[0;96m"
# define MAGENTA "\033[0;95m"

class	Fixed
{
	private:
			int					_fixedPoint;
			static const int	_fractionalBits = 8;

	public:
			Fixed();
			Fixed(const int value);
			Fixed(const float value);
			Fixed(const Fixed& other);
			~Fixed();

			Fixed& operator=(const Fixed& rhs);
			
			bool	operator>(const Fixed& rhs) const;
			bool	operator<(const Fixed& rhs) const;
			bool	operator>=(const Fixed& rhs) const;
			bool	operator<=(const Fixed& rhs) const;
			bool	operator==(const Fixed& rhs) const;
			bool	operator!=(const Fixed& rhs) const;

			Fixed	operator+(const Fixed& rhs) const;
			Fixed	operator-(const Fixed& rhs) const;
			Fixed	operator*(const Fixed& rhs) const;
			Fixed	operator/(const Fixed& rhs) const;

			Fixed&	operator++(void);
			Fixed	operator++(int);
			Fixed&	operator--(void);
			Fixed	operator--(int);

			static Fixed&	min(Fixed& a, Fixed& b);
			static const	Fixed&	min(const Fixed& a, const Fixed& b);
			static Fixed&	max(Fixed& a, Fixed& b);
			static const	Fixed&	max(const Fixed& a, const Fixed& b);

			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;

};
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
