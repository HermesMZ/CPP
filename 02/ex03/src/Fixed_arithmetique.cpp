/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_arithmetique.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:30:03 by mzimeris          #+#    #+#             */
/*   Updated: 2026/04/09 15:25:45 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_integer + other._integer);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_integer - other._integer);
	return result;
}
	
Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((this->_integer * other._integer) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other._integer == 0)
	{
		std::cerr << "Division by zero error" << std::endl;
		return Fixed();
	}
	Fixed result;
	result.setRawBits((this->_integer << _fractionalBits) / other._integer);
	return result;
}
