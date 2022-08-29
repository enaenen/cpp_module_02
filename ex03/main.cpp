#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) {
	Point p1( 0, 5 );
	Point p2( 5, 2 );
	Point p3( 0.01, 10.01 );
	Point p4( 4.99, 4.99 );
	Point p5( 5, 5 );
	Point a( 0, 0 );
	Point b( 0, 10 );
	Point c( 10, 0 );

	std::cout << "Triangle : "
			  << "a (" << a << ")"
			  << ", b (" << b << ")"
			  << ", c (" << c << ")" << std::endl
			  << std::endl;
	std::cout << "point1 (" << p1 << ")" << std::endl;
	std::cout << bsp( a, b, c, p1 ) << std::endl;

	std::cout << "point2 (" << p2 << ")" << std::endl;
	std::cout << bsp( a, b, c, p2 ) << std::endl;

	std::cout << "point3 (" << p3 << ")" << std::endl;
	std::cout << bsp( a, b, c, p3 ) << std::endl;

	std::cout << "point4 (" << p4 << ")" << std::endl;
	std::cout << bsp( a, b, c, p4 ) << std::endl;

	std::cout << "point5 (" << p5 << ")" << std::endl;
	std::cout << bsp( a, b, c, p5 ) << std::endl;
	return 0;
}