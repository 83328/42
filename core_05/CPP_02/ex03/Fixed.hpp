#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed(); // Default constructor
	Fixed(const int value); // Constructor that takes an int
	Fixed(const float value); // Constructor that takes a float
	Fixed(const Fixed &other); // Copy constructor
	~Fixed(); // Destructor

	Fixed &operator=(const Fixed &other); // Assignment operator

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;
};

#endif