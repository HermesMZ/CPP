/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 00:43:09 by zoum              #+#    #+#             */
/*   Updated: 2026/04/10 16:42:20 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <sstream>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		std::ostringstream oss;
		oss << "Value " << value << " not found in container";
		throw std::out_of_range(oss.str());
	}
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		std::ostringstream oss;
		oss << "Value " << value << " not found in container";
		throw std::out_of_range(oss.str());
	}
	return it;
}

#endif
