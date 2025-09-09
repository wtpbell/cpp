/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bewong <bewong@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:31:04 by bewong            #+#    #+#             */
/*   Updated: 2025/04/17 16:24:48 by bewong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


// Barycentric coordinate test using float arithmetic
//P = αA + βB + γC, where α + β + γ = 1 and α, β, γ >= 0 && <=1
// if all three are between 0 and 1, P is inside or on the edged of the triangle
//https://en.wikipedia.org/wiki/Barycentric_coordinate_system#Conversion_between_barycentric_and_Cartesian_coordinates
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float px = point.getX().toFloat();
	float py = point.getY().toFloat();
	float x1 = a.getX().toFloat();
	float y1 = a.getY().toFloat();
	float x2 = b.getX().toFloat();
	float y2 = b.getY().toFloat();
	float x3 = c.getX().toFloat();
	float y3 = c.getY().toFloat();

	float denom = (y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3);
	if (denom == 0) //degenerate (the pts lie on the straight line)
		return (false);
	float weightA = ((y2 - y3)*(px - x3) + (x3 - x2)*(py - y3)) / denom;
	float weightB  = ((y3 - y1)*(px - x3) + (x1 - x3)*(py - y3)) / denom; 
	float weightC = 1.0f - weightA - weightB;

	// const float EPS = 1e-1; //small number to account for floating point precision because of rounding errors
	// return (weightA >= -EPS && weightB >= -EPS && weightC >= -EPS && weightA <= 1+EPS && weightB <= 1+EPS && weightC <= 1+EPS);
	return (weightA >= 0 && weightB >= 0 && weightC >= 0 &&
			weightA <= 1 && weightB <= 1 && weightC <= 1);
}

