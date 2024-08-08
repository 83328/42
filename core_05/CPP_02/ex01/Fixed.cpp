/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:10:57 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/25 14:35:57 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = (value << this->_fractionalBits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_fractionalBits));
}


Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = fixed.getRawBits();
}

int Fixed::getRawBits(void) const
{
//    std::cout << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw)
{
//   std::cout << std::endl;
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
//    std::cout << std::endl;
	return (float)this->_value / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const
{
//	std::cout << std::endl;
	return this->_value >> this->_fractionalBits;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
