/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:42:17 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/25 17:02:31 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->_value = 0;
}

Fixed::Fixed(const int value)
{
    this->_value = (value << this->_fractionalBits);
}

Fixed::Fixed(const float value)
{
    this->_value = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
    this->_value = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    if(this != &fixed)
        this->_value = fixed.getRawBits();
    return (*this);
}

bool Fixed::operator>(const Fixed &fixed) const
{
    if(this -> getRawBits() > fixed.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator<(const Fixed &fixed) const
{
    if(this -> getRawBits() < fixed.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    if(this -> getRawBits() >= fixed.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    if(this -> getRawBits() <= fixed.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator==(const Fixed &fixed) const
{
    if(this -> getRawBits() == fixed.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    if(this -> getRawBits() != fixed.getRawBits())
        return true;
    else
        return false;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed result(this->toFloat() + fixed.toFloat());
    return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed result(this->toFloat() - fixed.toFloat());
    return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    Fixed result(this->toFloat() * fixed.toFloat());
    return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    Fixed result(this->toFloat() / fixed.toFloat());
    return result;
}

Fixed& Fixed::operator++(void)
{
    this->_value++;
//double check whether we do not have to increment this instead
    return (*this);
}

const Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_value++;
    return temp;
}

Fixed& Fixed::operator--(void)
{
    this->_value--;
    return (*this);
}

const Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_value--;
    return temp;
}

Fixed::~Fixed(void)
{
    this->_value = 0;
}

int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_value / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_value >> this->_fractionalBits;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if(a.getRawBits() < b.getRawBits())
        return a;
    else
        return b;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if(a.getRawBits() < b.getRawBits())
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if(a.getRawBits() > b.getRawBits())
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if(a.getRawBits() > b.getRawBits())
        return a;
    else
        return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
