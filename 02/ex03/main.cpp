#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

int main( void ) {
	std::cout << "=== Tests BSP (Binary Space Partitioning) ===" << std::endl;
	
	// Triangle de test avec des coordonnées floats
	Point a(0.0f, 0.0f);
	Point b(5.5f, 0.0f);
	Point c(2.75f, 4.0f);
	
	std::cout << "\nTriangle: A(0, 0), B(5.5, 0), C(2.75, 4)" << std::endl;
	
	// Test 1: Point à l'intérieur du triangle
	std::cout << "\n--- Test 1: Point à l'intérieur ---" << std::endl;
	Point p1(2.5f, 1.5f);
	std::cout << "Point P1(2.5, 1.5): ";
	if (bsp(a, b, c, p1))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE the triangle" << std::endl;
	
	// Test 2: Point à l'extérieur du triangle
	std::cout << "\n--- Test 2: Point à l'extérieur ---" << std::endl;
	Point p2(10.0f, 10.0f);
	std::cout << "Point P2(10, 10): ";
	if (bsp(a, b, c, p2))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE the triangle" << std::endl;
	
	// Test 3: Point sur un sommet (doit retourner false)
	std::cout << "\n--- Test 3: Point sur un sommet ---" << std::endl;
	Point p3(0.0f, 0.0f); // Sommet A
	std::cout << "Point P3(0, 0) - sommet A: ";
	if (bsp(a, b, c, p3))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE/ON EDGE the triangle" << std::endl;
	
	Point p4(5.5f, 0.0f); // Sommet B
	std::cout << "Point P4(5.5, 0) - sommet B: ";
	if (bsp(a, b, c, p4))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE/ON EDGE the triangle" << std::endl;
	
	// Test 4: Point sur une arête (doit retourner false)
	std::cout << "\n--- Test 4: Point sur une arête ---" << std::endl;
	Point p5(2.75f, 0.0f); // Milieu de l'arête AB
	std::cout << "Point P5(2.75, 0) - milieu arête AB: ";
	if (bsp(a, b, c, p5))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE/ON EDGE the triangle" << std::endl;
	
	Point p6(1.375f, 2.0f); // Sur l'arête AC
	std::cout << "Point P6(1.375, 2) - sur arête AC: ";
	if (bsp(a, b, c, p6))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE/ON EDGE the triangle" << std::endl;
	
	// Test 5: Points avec des coordonnées négatives
	std::cout << "\n--- Test 5: Coordonnées négatives ---" << std::endl;
	Point p7(-1.0f, -1.0f);
	std::cout << "Point P7(-1, -1): ";
	if (bsp(a, b, c, p7))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE the triangle" << std::endl;
	
	// Test 6: Point très proche du centre
	std::cout << "\n--- Test 6: Point proche du centre ---" << std::endl;
	Point p8(2.75f, 1.33f); // Proche du centre du triangle
	std::cout << "Point P8(2.75, 1.33): ";
	if (bsp(a, b, c, p8))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE the triangle" << std::endl;
	
	// ========================================
	// TRIANGLE 2: Coordonnées mixtes (négatives et positives)
	// ========================================
	std::cout << "\n\n=== TRIANGLE MIXTE (négatif/positif) ===" << std::endl;
	Point a2(-2.0f, -1.0f);
	Point b2(3.0f, -1.0f);
	Point c2(0.5f, 3.0f);
	
	std::cout << "Triangle: A(-2, -1), B(3, -1), C(0.5, 3)" << std::endl;
	
	// Test à l'intérieur
	Point p9(0.5f, 1.0f);
	std::cout << "Point P9(0.5, 1) - intérieur: ";
	if (bsp(a2, b2, c2, p9))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE the triangle" << std::endl;
	
	// Test sur sommet négatif
	Point p10(-2.0f, -1.0f);
	std::cout << "Point P10(-2, -1) - sommet A: ";
	if (bsp(a2, b2, c2, p10))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE/ON EDGE the triangle" << std::endl;
	
	// Test sur arête
	Point p11(0.5f, -1.0f);
	std::cout << "Point P11(0.5, -1) - milieu arête AB: ";
	if (bsp(a2, b2, c2, p11))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE/ON EDGE the triangle" << std::endl;
	
	// Test extérieur
	Point p12(-5.0f, 5.0f);
	std::cout << "Point P12(-5, 5) - extérieur: ";
	if (bsp(a2, b2, c2, p12))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE the triangle" << std::endl;
	
	// ========================================
	// TRIANGLE 3: Que des coordonnées négatives
	// ========================================
	std::cout << "\n\n=== TRIANGLE NÉGATIF ===" << std::endl;
	Point a3(-5.0f, -5.0f);
	Point b3(-1.0f, -5.0f);
	Point c3(-3.0f, -2.0f);
	
	std::cout << "Triangle: A(-5, -5), B(-1, -5), C(-3, -2)" << std::endl;
	
	// Test à l'intérieur
	Point p13(-3.0f, -4.0f);
	std::cout << "Point P13(-3, -4) - intérieur: ";
	if (bsp(a3, b3, c3, p13))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE the triangle" << std::endl;
	
	// Test sur sommet
	Point p14(-5.0f, -5.0f);
	std::cout << "Point P14(-5, -5) - sommet A: ";
	if (bsp(a3, b3, c3, p14))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE/ON EDGE the triangle" << std::endl;
	
	// Test sur arête
	Point p15(-3.0f, -5.0f);
	std::cout << "Point P15(-3, -5) - milieu arête AB: ";
	if (bsp(a3, b3, c3, p15))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE/ON EDGE the triangle" << std::endl;
	
	// Test extérieur (coordonnées plus négatives)
	Point p16(-10.0f, -10.0f);
	std::cout << "Point P16(-10, -10) - extérieur: ";
	if (bsp(a3, b3, c3, p16))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE the triangle" << std::endl;
	
	// Test extérieur (coordonnées moins négatives)
	Point p17(-1.0f, -1.0f);
	std::cout << "Point P17(-1, -1) - extérieur: ";
	if (bsp(a3, b3, c3, p17))
		std::cout << "INSIDE the triangle" << std::endl;
	else
		std::cout << "OUTSIDE the triangle" << std::endl;
	
	return 0;
}