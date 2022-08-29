#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

Point::Point( void ) : x( 0 ), y( 0 ){};
Point::Point( const float a, const float b ) : x( a ), y( b ){};
Point::Point( const Point &ref ) { *this = ref; }
Point &Point::operator=( const Point &ref ) {
	if ( this != &ref ) {
		const_cast<Fixed &>( x ) = ( ref.getX() );
		const_cast<Fixed &>( y ) = ( ref.getY() );
	}
	return *this;
}
Point::~Point( void ) {}

Point Point::operator-( const Point &ref ) {
	Point ret;

	const_cast<Fixed &>( ret.x ) = this->getX() - ref.getX();
	const_cast<Fixed &>( ret.y ) = this->getY() - ref.getY();
	return ret;
}
Fixed Point::getX( void ) const { return ( this->x ); }
Fixed Point::getY( void ) const { return ( this->y ); }
