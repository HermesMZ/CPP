/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 23:54:57 by zoum              #+#    #+#             */
/*   Updated: 2026/01/13 23:54:58 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const & min(T const & a, T const & b)
{
	return (a < b) ? a : b;
}

template <typename T>
T const & max(T const & a, T const & b)
{
	return (a > b) ? a : b;
}

#endif
