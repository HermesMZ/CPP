#include <iostream>
#include "Fixed.hpp"
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );

	std::cout << "a:  " << a << std::endl;
	++a;
	std::cout << "++a:" << a << std::endl;
	a++;
	std::cout << "a++:" << a << std::endl;
	
	a = 0;
	std::cout << "a:  " << a << std::endl;
	--a;
	std::cout << "--a:" << a << std::endl;
	a--;
	std::cout << "a--:" << a << std::endl;

	std::cout << "a:  " << a << std::endl;
	std::cout << "b:  " << b << std::endl;
	std::cout << "c:  " << c << std::endl;

	std::cout << "max a b\n";
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}