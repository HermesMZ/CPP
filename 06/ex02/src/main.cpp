/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 23:30:00 by zoum              #+#    #+#             */
/*   Updated: 2026/01/14 01:21:13 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.HPP"
#include "B.HPP"
#include "C.HPP"
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	std::cout << "=== Test 1: Generate and identify random instances ===" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base* ptr = generate();
		std::cout << "Instance " << i + 1 << " - Using pointer: ";
		identify(ptr);
		std::cout << "Instance " << i + 1 << " - Using reference: ";
		identify(*ptr);
		delete ptr;
		std::cout << std::endl;
	}

	std::cout << "=== Test 2: Known types ===" << std::endl;
	
	Base* a = new A();
	std::cout << "Type A - Using pointer: ";
	identify(a);
	std::cout << "Type A - Using reference: ";
	identify(*a);
	delete a;
	std::cout << std::endl;

	Base* b = new B();
	std::cout << "Type B - Using pointer: ";
	identify(b);
	std::cout << "Type B - Using reference: ";
	identify(*b);
	delete b;
	std::cout << std::endl;

	Base* c = new C();
	std::cout << "Type C - Using pointer: ";
	identify(c);
	std::cout << "Type C - Using reference: ";
	identify(*c);
	delete c;

	return 0;
}
