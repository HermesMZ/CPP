#include <iostream>
#include "Fixed.hpp"
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	

	a = 11;
	std::cout << "incrémentations - décrémentations" << std::endl;
	std::cout << "avant a: " << a << " ++a: " << ++a  << " apres : " << a << std::endl;
	std::cout << "avant a: " << a << " a++: " << a++  << " apres : " << a << std::endl;
	std::cout << "avant a: " << a << " a--: " << a--  << " apres : " << a << std::endl;
	std::cout << "avant a: " << a << " --a: " << --a  << " apres : " << a << std::endl;

	std::cout << "\narithmétique" << std::endl;
	std::cout << "avant a: " << a << " a + 10 : " << a + 10  << " apres : " << a << std::endl;
	std::cout << "avant a: " << a << " a - 10 : " << a - 10  << " apres : " << a << std::endl;
	std::cout << "avant a: " << a << " a * 10 : " << a * 10  << " apres : " << a << std::endl;
	std::cout << "avant a: " << a << " a / 10 : " << a / 10  << " apres : " << a << std::endl;

	Fixed const d(a);
	std::cout << "\ncomparaisons" << std::endl;
	std::cout << "a : " << a << " b: " << b << " d: " << d << std::endl;
	std::cout << "a > b " << ( a > b ) << std::endl;
	std::cout << "a < b " << ( a < b ) << std::endl;
	std::cout << "a <= d " << ( a <= d ) << std::endl;
	std::cout << "a <= b " << ( a <= b ) << std::endl;
	std::cout << "a >= d " << ( a >= d ) << std::endl;
	std::cout << "a >= b " << ( a >= b ) << std::endl;
	std::cout << "a == b " << ( a == b ) << std::endl;
	std::cout << "a == d " << ( a == d ) << std::endl;
	std::cout << "a != b " << ( a != b ) << std::endl;
	std::cout << "a != d " << ( a != d ) << std::endl;

	std::cout << "\nmin - max" << std::endl;
	std::cout << "avant a: " << a << "b: " << b << std::endl;
	std::cout << "max a b\n";
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "min a b\n";
	std::cout << Fixed::min( a, b ) << std::endl;

	// Tests additionnels
	std::cout << "\ntests additionnels" << std::endl;
	
	// Test toInt, toFloat, getRawBits
	Fixed f(3.75f);
	std::cout << "f(3.75) raw: " << f.getRawBits() << " toInt: " << f.toInt() << " toFloat: " << f.toFloat() << std::endl;
	
	// Test setRawBits
	Fixed g;
	g.setRawBits(f.getRawBits());
	std::cout << "g (apres setRawBits de f) = " << g << std::endl;
	
	// Test assignation et auto-assignation
	Fixed h;
	h = a;
	// h = h; // auto-assignation commentee (warning compilateur)
	std::cout << "h apres assignation/auto-assignation: " << h << std::endl;
	
	// Test min/max const
	const Fixed cx(4), cy(2);
	std::cout << "min const(4,2): " << Fixed::min(cx, cy) << ", max const(4,2): " << Fixed::max(cx, cy) << std::endl;
	
	// Test operations avec floats
	std::cout << "5.05 * 2.5 = " << (Fixed(5.05f) * Fixed(2.5f)) << std::endl;
	
	// Test nombres negatifs
	std::cout << "-3.5 + 1 = " << (Fixed(-3.5f) + Fixed(1)) << std::endl;
	
	// Test precision
	Fixed p(5.05f);
	std::cout << "5.05 stocke comme: " << p.toFloat() << " (raw: " << p.getRawBits() << ")" << std::endl;
	
	// Test grands nombres (overflow potentiel)
	Fixed big(1000000);
	std::cout << "1000000 * 1000000 = " << (big * big) << std::endl;

	// division par 0 - test des deux syntaxes
	std::cout << "a / 0 (int) = " << (a / 0) << std::endl;
	std::cout << "a / Fixed(0) = " << (a / Fixed(0)) << std::endl;

	return 0;
}