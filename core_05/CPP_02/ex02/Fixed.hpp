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

		//Destructor
		~Fixed(void);

		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;

		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;

		Fixed &operator++(void);
		const Fixed operator++(int);
		Fixed &operator--(void);
		const Fixed operator--(int);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif