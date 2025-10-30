/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:32:24 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/30 13:36:19 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const x, float const y) : x(x), y(y) {}

Point::Point(Point const &src) : x(src.x), y(src.y) {}

Point &Point::operator=(const Point &rhs) {
	Point tmp = Point(rhs);
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
	return this->x;
}

Fixed Point::getY() const {
	return this->y;
}

const Fixed &Point::min(const Fixed &a,  const Fixed &b, const Fixed &c)
{
	if (a < b && a < c)
		return a;
	if (b < a && b < c)
		return b;
	if (c < a && c < b)
		return c;
	return a;
}

const Fixed &Point::max(const Fixed &a,  const Fixed &b, const Fixed &c)
{
	if (a > b && a > c)
		return a;
	if (b > a && b > c)
		return b;
	if (c > a && c > b)
		return c;
	return a;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed minX = Point::min(a.getX(), b.getX(), c.getX());
	Fixed minY = Point::min(a.getY(), b.getY(), c.getY());
	Fixed maxX = Point::max(a.getX(), b.getX(), c.getX());
	Fixed maxY = Point::max(a.getY(), b.getY(), c.getY());
	// debug
	// std::cout << "X : " << minX << " / " << maxX << std::endl;
	// std::cout << "Y : " << minY << " / " << maxY << std::endl;
	if (point.getX() < minX || point.getX() > maxX
		|| point.getY() < minY || point.getY() > maxY)
		{
			// std::cout << "Point is outside the bounding box." << std::endl;
			return false;
		}
	else if (((c.getX() - point.getX()) * (a.getY() - point.getY()) - (c.getY() - point.getY()) * (a.getX() - point.getX()) > 0)
		== ((c.getX() - point.getX()) * (a.getY() - point.getY()) - (c.getY() - point.getY()) * (a.getX() - point.getX()) > 0)
		== ((a.getX() - point.getX()) * (b.getY() - point.getY()) - (a.getY() - point.getY()) * (b.getX() - point.getX()) > 0))
		return true;
	return false;
}
