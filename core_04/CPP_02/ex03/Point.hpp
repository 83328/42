#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;

public:
	// Default constructor that initializes x and y to 0
	Point();

	// Constructor that takes two constant floating-point numbers
	Point(float const x, float const y);

	// Copy constructor
	Point(Point const &other);

	// Copy assignment operator overload
	Point &operator=(Point const &other);

	// Destructor
	~Point();

	// Getter for x
	Fixed getX() const;

	// Getter for y
	Fixed getY() const;
};

#endif