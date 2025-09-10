/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/15 17:24:19 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/18 11:35:58 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	std::cout << CYAN << "\n=== Subject Basic Tests ===" << RESET << std::endl;
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << "a               : " << a << std::endl;
	std::cout << "++a             : " << ++a << std::endl;
	std::cout << "a after ++a     : " << a << std::endl;
	std::cout << "a++             : " << a++ << std::endl;
	std::cout << "a after a++     : " << a << std::endl;
	std::cout << "b               : " << b << std::endl;
	std::cout << "Max(a, b)       : " << Fixed::max( a, b ) << std::endl;

	std::cout << CYAN << "\n=== Comparison Operators Tests ===" << RESET << std::endl;
	
	Fixed const c(Fixed(28.005f));
	Fixed const d( Fixed( 28.005f ));
	
	std::cout << "c > d           : " << (c > d) << std::endl;
	std::cout << "c < d           : " << (c < d) << std::endl;
	std::cout << "c >= d          : " << (c >= d) << std::endl;
	std::cout << "c <= d          : " << (c <= d) << std::endl;
	std::cout << "c == d          : " << (c == d) << std::endl;
	std::cout << "c != d          : " << (c != d) << std::endl;
	
	std::cout << CYAN << "\n=== Arithmetic Operators Tests ===" << RESET << std::endl;
	
	Fixed e(Fixed(8.255f));
	Fixed const f( Fixed( 12.004f ) * Fixed( 5 ) );
	
	std::cout << "e + f           : " << (e + f) << std::endl;
	std::cout << "e - f           : " << (e - f) << std::endl;
	std::cout << "e * f           : " << (e * f) << std::endl;
	std::cout << "e / f           : " << (e / f) << std::endl;
	std::cout << "e / f + f - e   : " << (e / f + f - e) << std::endl;
	std::cout << "e / f           : " << (e / f) << std::endl;
	std::cout << "e               : " << e << std::endl;
	std::cout << "f               : " << f << std::endl;
	
	std::cout << CYAN << "\n=== Max / Min Tests ===" << RESET << std::endl;
	
	Fixed g(Fixed(8.255f));;
	Fixed const h( Fixed( 12.004f ) * Fixed( 0.5f ) );
	
	std::cout << "Max(f, g)       : " << Fixed::max( f, g ) << std::endl;
	std::cout << "Max(f, g)       : " << Fixed::min( f, g ) << std::endl;
	
	std::cout << std::endl;
	
	return (0);
}
