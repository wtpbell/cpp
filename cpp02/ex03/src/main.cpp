/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/16 09:31:08 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/18 12:38:26 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <cstring>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

//The condition for being inside is: x ≥ 0, y ≥ 0, and x + y ≤ 10. 
int	main(void)
{
	std::cout << "\n=== Pure Text Triangle Test ===" << std::endl;
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);
	Point testPoints[] = {
		Point(5.13f, 5.27f),   // outside
		Point(9.99f, 5.01f),   // outside
		Point(15.2f, 5.8f),    // outside
		Point(0.0f, 10.0f),   // on c
		Point(7.51f, 2.49f),   // on the edge
		Point(9.98f, 9.99f),   // outside
		Point(5.01f, 9.95f),   // outside
		Point(3.33f, 3.37f),   // inside
		Point(0.01f, 0.01f),   // inside
		Point(5.21f, 1.29f),   // inside
		Point((5.05f * 2.01f), (3.12f - (-12.01f))),   // outside
		Point((5.05f * 1.99f), (3.12f - (-11.99f))),   // outside
		Point(3.5f, 3.5f),   // inside
		Point(6.2f, 2.8f),   // inside
		Point(5.01f, 2.02f),   // inside
		Point(-4.21f, -3.29f),   // outside
		Point(0.51f, 5.29f),   // inside
		Point(1.09f, 1.11f),   // inside
		Point(-4.65f, 11.69f),   // outside
		Point(-16.47f, -2.88f),   // outside
		Point(11.44f, -7.19f),   // outside
		Point(8.19f, 7.02f),   // outside
		Point(-19.99f, -0.06f),   // outside
		Point(19.99f, -0.04f),   // outside
		Point(0.01f, 19.99f),   // outside
		Point(0.01f, 0.01f),   // inside
		Point(-19.99f, 0.01f),   // outside
		Point(19.99f, 0.01f),   // outside
		Point(0.01f, 19.99f),   // outside
		Point(),   // inside
	};
	const char* results[] = {"outside", "inside"};
	
 	for (size_t i = 0; i < sizeof(testPoints)/sizeof(testPoints[0]); ++i) {
		std::cout << "Point " << testPoints[i] << " is "
				  << (bsp(a, b, c, testPoints[i]) ? results[1] : results[0])
				  << " the triangle." << std::endl;
	}

	std::cout << "\n=== Pure Text Test For Tree ===" << std::endl;
	Point ta(0, 6);
	Point tb(6, 0);
	Point tc(12, 6);

	Point testPoints2[] = {
		Point(3, 3),
		Point(-6.99f, 3),
		Point(9, 3),
		Point(12, 3),
		Point(3, 18),
		Point(6, 6.005f),
		Point(0.3f, 6),
		Point(12, 6)
	};

	for (size_t i = 0; i < sizeof(testPoints2)/sizeof(testPoints2[0]); ++i)
	{
		std::cout << "Point " << testPoints2[i] << " is "
				  << (bsp(ta, tb, tc, testPoints2[i]) ? results[1] : results[0])
				  << " the triangle." << std::endl;
	}

	std::cout << "\n=== Graphic Test ===" << std::endl;
	const char* tree[] = {
		"      A      ",
		"     AAA     ",
		"    AAAAA    ",
		"   AAAAAAA   ",
		"  AAAAAAAAA  ",
		" AAAAAAAAAAA ",
		"     B B     ",
		"     B B     ",
		"    BBBBB    "
	};
	const int tree_height = sizeof(tree) / sizeof(tree[0]);
	const int tree_width = strlen(tree[0]);

	Point f(-1, 6);
	Point g(6, -1);
	Point h(12, 6);

	for (int y = 0; y < tree_height; ++y)
	{
		for (int x = 0; x < tree_width; ++x)
		{
			Point p(x, y);
			if (tree[y][x] == 'A')
				std::cout << (bsp(f, g, h, p) ? '#' : 'C');
			else if (tree[y][x] == ' ')
				std::cout << ".";
			else
				std::cout << tree[y][x];
		}
		std::cout << std::endl;
	}
}
