/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsp.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/16 09:31:04 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/16 09:31:05 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float sign(Point p1, Point p2, Point p3)
{
	return ((p1.getX().toFloat() - p3.getX().toFloat()) * (p2.getY().toFloat() - p3.getY().toFloat()) - \
			(p2.getX().toFloat() - p3.getX().toFloat()) * (p1.getY().toFloat() - p3.getY().toFloat()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	pAB = sign(point, a, b);
	float	pAC = sign(point, a, c);
	float	pBC = sign(point, b, c);

	if (pAB == 0 || pAC == 0 || pBC == 0)
		return (false);
	return (pAB > 0 && pAC > 0 && pBC > 0) || (pAB < 0 && pAC < 0 && pBC < 0);
}


//Barycentric Coordinates Concept
Any point P inside a triangle ABC can be expressed as a weighted combination of the triangle's vertices:
