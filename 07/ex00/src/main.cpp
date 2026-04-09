/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 23:55:46 by zoum              #+#    #+#             */
/*   Updated: 2026/04/09 15:29:05 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main(void) {
	int a = 2;
	int b = 2;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "after swap: ";
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << (::min(a, b) == a ? "b" : "a") << std::endl;
	std::cout << "max(a, b) = " << (::max(a, b) == a ? "b" : "a") << std::endl;
	std::cout << "min(a, b) = " << (::min(a, b) == a ? "b" : "a") << std::endl;
	std::cout << "min(a, b) = " << (::min(a, b) == a ? "b" : "a") << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "after swap: ";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << (::min(c, d) == c ? "c" : "d") << std::endl;
	std::cout << "max(c, d) = " << (::max(c, d) == c ? "c" : "d") << std::endl;

	return 0;
}
