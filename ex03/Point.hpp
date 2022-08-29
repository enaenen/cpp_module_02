#pragma once

#include <iostream>
#include "Fixed.hpp"

class Point {
   private:
	const Fixed x;
	const Fixed y;

   public:
	Point( void );
	Point( const float a, const float b );
	Point( const Point &ref );
	Point &operator=( const Point &ref );
	Point operator-( const Point &ref );
	~Point( void );

	Fixed getX( void ) const;
	Fixed getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );
