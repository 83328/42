#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int    _fractionalBits = 8;

	public:
		//Constructor
		Fixed(void);

		//Constructor with int
		Fixed(const int value);

		//Constructor with float
		Fixed(const float value);

		//Copy constructor
		Fixed(const Fixed &fixed);

		//Copy assignment operator
		Fixed &operator=(const Fixed &fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;

		int toInt(void) const;
		
		//Destructor
		~Fixed(void);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif