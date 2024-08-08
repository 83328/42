/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:03:19 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/26 15:52:06 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
	
}

Fixed::Fixed(const int value)
{
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed()
{

}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		_fixedPointValue = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}