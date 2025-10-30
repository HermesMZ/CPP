/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_comparaisons.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:17:47 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/29 16:27:51 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool Fixed::operator>(const Fixed &other) const
{
	return this->_integer > other._integer;	
}
bool Fixed::operator<(const Fixed &other) const
{
	return this->_integer < other._integer;
}
bool Fixed::operator<=(const Fixed &other) const
{
	return this->_integer <= other._integer;
}
bool Fixed::operator>=(const Fixed &other) const
{
	return this->_integer >= other._integer;
}
bool Fixed::operator==(const Fixed &other) const
{
	return this->_integer == other._integer;
}
bool Fixed::operator!=(const Fixed &other) const
{
	return this->_integer != other._integer;
}
