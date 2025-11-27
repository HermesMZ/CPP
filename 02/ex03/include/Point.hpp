/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:32:39 by mzimeris          #+#    #+#             */
/*   Updated: 2025/10/30 13:19:27 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
		// plus tout ce qui peut m'intéresser
	public:
		Point();
		Point(float const x, float const y);
		Point(Point const &src);
		Point &operator=(const Point &src);
		~Point();
		Fixed getX() const;
		Fixed getY() const;
		// triangle
		static const Fixed &min(const Fixed &a, const Fixed &b, const Fixed &c);
		static const Fixed &max(const Fixed &a, const Fixed &b, const Fixed &c);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif /* POINT_HPP */