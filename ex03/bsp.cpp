#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	Point p1 = const_cast<Point &>( a ) - b;
	Point p2 = const_cast<Point &>( b ) - c;
	Point p3 = const_cast<Point &>( c ) - a;
	Fixed r1 = crossProd( p1, const_cast<Point &>( point ) - b );
	Fixed r2 = crossProd( p2, const_cast<Point &>( point ) - c );
	Fixed r3 = crossProd( p3, const_cast<Point &>( point ) - a );

	if ( ( r1 > 0 && r2 > 0 && r3 > 0 ) || ( r1 < 0 && r2 < 0 && r3 < 0 ) )
		return true;
	return false;
}
