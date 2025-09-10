/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/16 09:31:11 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/18 12:35:27 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(): x(0), y(0)
{

}

Point::Point(const float x, const float y): x(x), y(y)
{

}

Point::Point(const Point& other): x(other.x), y(other.y)
{
}

Point::~Point()
{

}

Point&	Point::operator=(Point& rhs)
{
	return (rhs);
}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}

std::ostream&	operator<<(std::ostream& os, const Point& obj)
{
	os << "(" << obj.getX() << ", " << obj.getY() << ")";
	return (os);
}
