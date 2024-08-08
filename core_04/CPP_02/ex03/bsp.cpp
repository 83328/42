/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:04:06 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/26 11:08:22 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

#include <cmath>

// Function to calculate the area of a triangle given three points
float area(Point const &p1, Point const &p2, Point const &p3)
{
	return std::abs((p1.getX().getRawBits() * (p2.getY().getRawBits() - p3.getY().getRawBits()) +
					 p2.getX().getRawBits() * (p3.getY().getRawBits() - p1.getY().getRawBits()) +
					 p3.getX().getRawBits() * (p1.getY().getRawBits() - p2.getY().getRawBits())) / 2.0);
}

// Function to check if a point is inside a triangle
bool bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
	// Calculate the area of the main triangle
	float areaABC = area(a, b, c);

	// Calculate the area of the sub-triangles
	float areaPAB = area(point, a, b);
	float areaPBC = area(point, b, c);
	float areaPCA = area(point, c, a);

	// Check if the sum of the sub-triangle areas is equal to the main triangle area
	return (areaABC == areaPAB + areaPBC + areaPCA);
}
