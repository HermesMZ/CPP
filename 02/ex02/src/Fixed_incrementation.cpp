/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_incrementation.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:40:39 by mzimeris          #+#    #+#             */
/*   Updated: 2026/04/09 15:25:45 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed &Fixed::operator++() {
	this->_integer++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed &Fixed::operator--() {
	this->_integer--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--(*this);
	return temp;
}
