#pragma once

#include <iostream>

class Fixed {
   private:
	int fixedPointNum;
	static const int fractionalBits = 8;

   public:
	Fixed( void );
	Fixed( const int fpn );
	Fixed( const float fpn );
	Fixed( const Fixed& fixed );
	~Fixed();

	Fixed& operator=( const Fixed& op );
	Fixed operator+( const Fixed& op );
	Fixed operator-( const Fixed& op );
	Fixed operator*( const Fixed& op );
	Fixed operator/( const Fixed& op );

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );
