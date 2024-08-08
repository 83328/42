/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:03:43 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/26 11:29:49 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor that initializes x and y to 0
Point::Point() : x(0), y(0)
{
	
}

// Constructor that takes two constant floating-point numbers
Point::Point(float const x, float const y) : x(x), y(y)
{
	
}

// Copy constructor
Point::Point(Point const &other) : x(other.x), y(other.y)
{
	
}

// Copy assignment operator overload
Point &Point::operator=(Point const &other)
{
	// Since x and y are const, we cannot assign to them
	// Instead, we return *this to allow chained assignment
	if (this != &other)
	{
		// No actual assignment needed as x and y are const
	}
	return *this;
}

// Destructor
Point::~Point()
{
	
}

// Getter for x
Fixed Point::getX() const
{
	return x;
}

// Getter for y
Fixed Point::getY() const
{
	return y;
}
