#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
		int					_value;
		static const int    _fractionalBits = 8;

	public:
		//Constructor
		Fixed(void);
		//Copy constructor
		Fixed(const Fixed &_fixed);
		//Copy assignment operator
		Fixed &operator=(const Fixed &_fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		//Destructor
		~Fixed(void);
};

#endif