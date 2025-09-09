/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/16 09:30:54 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/16 09:30:55 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	std::cout << GREEN << "=== Increment/Decrement Test ===" << RESET << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a            : " << a << std::endl;
	std::cout << "++a          : " << ++a << std::endl;
	std::cout << "a after ++a  : " << a << std::endl;
	std::cout << "a++          : " << a++ << std::endl;
	std::cout << "a after a++  : " << a << std::endl;
	std::cout << "--a          : " << --a << std::endl;
	std::cout << "a after --a  : " << a << std::endl;
	std::cout << "a--          : " << a-- << std::endl;
	std::cout << "a after a--  : " << a << std::endl;
	std::cout << "b            : " << b << std::endl;
	std::cout << "Max(a, b)    : " << Fixed::max( a, b ) << std::endl;
	std::cout << "Min(a, b)    : " << Fixed::min( a, b ) << std::endl;

	std::cout << GREEN << "\n=== Arithmetic Operators Test ===" << RESET << std::endl;
	Fixed x(10.5f);
	Fixed y(0.25f);
	std::cout << "x            : " << x << std::endl;
	std::cout << "y            : " << y << std::endl;
	std::cout << "x + y        : " << x + y << std::endl;
	std::cout << "x - y        : " << x - y << std::endl;
	std::cout << "x * y        : " << x * y << std::endl;
	std::cout << "x / y        : " << x / y << std::endl;

	std::cout << GREEN << "\n=== Comparison Operators Test ===" << RESET << std::endl;
	std::cout << "x > y        : " << (x > y) << std::endl;
	std::cout << "x < y        : " << (x < y) << std::endl;
	std::cout << "x >= y       : " << (x >= y) << std::endl;
	std::cout << "x <= y       : " << (x <= y) << std::endl;
	std::cout << "x == y       : " << (x == y) << std::endl;
	std::cout << "x != y       : " << (x != y) << std::endl;

	std::cout << GREEN << "\n=== Max/Min Test ===" << RESET << std::endl;
	Fixed e(5.5f);
	Fixed f(10.5f);
	const Fixed g(4);
	const Fixed h(10.5f);
	
	Fixed& bigger = Fixed::max(e, f);
	Fixed& smaller = Fixed::min(e, f);
	const Fixed& constBigger = Fixed::max(g, h);
	const Fixed& constSmaller = Fixed::min(g, h);

	std::cout << "e                               : " << e << std::endl;
	std::cout << "f                               : " << f << std::endl;
	std::cout << "Non const bigger                : " << bigger << std::endl;
	std::cout << "Non const smaller               : " << smaller << std::endl;
	bigger = Fixed(100.0f);
	smaller = Fixed(2.0f);
	std::cout << "After reset bigger to 100.0f    : " << bigger << std::endl;
	std::cout << "After reset smaller to 2.0f     : " << smaller << std::endl;
	std::cout << "g                               : " << g << std::endl;
	std::cout << "h                               : " << h << std::endl;
	std::cout << "Const bigger                    : " << constBigger << std::endl;
	std::cout << "Const smaller                   : " << constSmaller << std::endl;
	// constBigger = Fixed(100.0f);
	// constSmaller = Fixed(2.0f);

	std::cout << GREEN << "\n=== Edged Cases Test ===" << RESET << std::endl;
	Fixed zero(0);
	Fixed one(1);
	std::cout << "1 / 0        : " << (one / zero) << std::endl;
	Fixed large(1234.5678f);
	Fixed small(0.0039f); // the smallest number (1 / (1 << 8))
	std::cout << "Large number  : " << large << std::endl;
	std::cout << "Small number  : " << small << std::endl;
	std::cout << "Large * Small : " << large * small << std::endl;

	return 0;
}
