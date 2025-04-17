/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:31:01 by bewong            #+#    #+#             */
/*   Updated: 2025/04/17 10:42:23 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
	private:
			const Fixed	x;
			const Fixed	y;

	public:
			Point();
			Point(const float x, const float y);
			Point(const Point& other);
			~Point();

			Point& operator=(Point& rhs);
			Fixed	getX(void) const;
			Fixed	getY(void) const;
};

std::iostream& operator<<(std::iostream& os, const Point& obj);

#endif
