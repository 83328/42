/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:02:58 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/26 11:29:55 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include "Point.hpp"
#include <iostream>

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point);

int main()
{
	Point a(0.0, 0.0);
	Point b(0.0, 1.0);
	Point c(1.0, 0.0);
	Point point(0.3, 0.3);

	std::cout << "Point a: (" << a.getX().toFloat() << ", " << a.getY().toFloat() << ")" << std::endl;
	std::cout << "Point b: (" << b.getX().toFloat() << ", " << b.getY().toFloat() << ")" << std::endl;
	std::cout << "Point c: (" << c.getX().toFloat() << ", " << c.getY().toFloat() << ")" << std::endl;

	bool inside = bsp(a, b, c, point);

	if (inside)
	{
		std::cout << "The point is inside the triangle." << std::endl;
	}
	else
	{
		std::cout << "The point is outside the triangle." << std::endl;
	}
	return 0;
}
