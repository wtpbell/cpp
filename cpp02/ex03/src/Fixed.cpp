/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/16 09:31:06 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/16 09:31:07 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	this->setRawBits(0);
}

Fixed::Fixed(const int value)
{
	this->setRawBits(value << this->_fractionalBits);
}

Fixed::Fixed(const float value)
{
	this->setRawBits(roundf(value * (1 << this->_fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	if (*this != rhs)
		this->setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{

}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	if (rhs.getRawBits() == 0)
	{
		std::cerr << RED << "Error: Division by zero" << RESET << std::endl;
		return Fixed(0);
	}
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

//prefix increment
Fixed&	Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

//postfix increment return value before increment
Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

//prefix decrement
Fixed&	Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

//postfix decrement return value before decrement
Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPoint / (1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPoint >> this->_fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
