/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:32:24 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/29 19:31:12 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_integer = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &other) : _integer(other._integer)
{
}

Fixed::Fixed(const int value)
{
    _integer = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->_integer = roundf(value * (1 << _fractionalBits));
}


Fixed & Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_integer = other._integer;
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return this->_integer;
}

void Fixed::setRawBits( int const raw )
{
	this->_integer = raw;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(this->_integer) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
	return this->_integer >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}