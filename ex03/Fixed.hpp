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

	bool operator<( const Fixed& target );
	bool operator>( const Fixed& target );
	bool operator==( const Fixed& target );
	bool operator<=( const Fixed& target );
	bool operator>=( const Fixed& target );
	bool operator!=( const Fixed& target );

	Fixed& operator++( void );
	Fixed operator++( int );
	Fixed& operator--( void );
	Fixed operator--( int );

	static Fixed& min( Fixed& a, Fixed& b );
	static const Fixed& min( const Fixed& a, const Fixed& b );
	static Fixed& max( Fixed& a, Fixed& b );
	static const Fixed& max( const Fixed& a, const Fixed& b );

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );
