/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_comparaisons.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:17:47 by mzimeris          #+#    #+#             */
/*   Updated: 2026/04/09 15:25:45 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool Fixed::operator>(const Fixed &other) const {
	return this->_integer > other._integer;	
}
bool Fixed::operator<(const Fixed &other) const {
	return this->_integer < other._integer;
}
bool Fixed::operator<=(const Fixed &other) const {
	return this->_integer <= other._integer;
}
bool Fixed::operator>=(const Fixed &other) const {
	return this->_integer >= other._integer;
}
bool Fixed::operator==(const Fixed &other) const {
	return this->_integer == other._integer;
}
bool Fixed::operator!=(const Fixed &other) const {
	return this->_integer != other._integer;
}
