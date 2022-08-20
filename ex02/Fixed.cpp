#include "Fixed.hpp"

Fixed::Fixed( void ) : fixedPointNum() {}

Fixed::Fixed( const int fpn ) { fixedPointNum = fpn << fractionalBits; }
Fixed::Fixed( const float fpn ) {
	fixedPointNum = (int)roundf( fpn * ( 1 << fractionalBits ) );
}

Fixed::Fixed( const Fixed& fixed ) { *this = fixed; }

Fixed::~Fixed() {}

Fixed& Fixed::operator=( const Fixed& target ) {
	if ( this != &target )
		this->setRawBits( target.getRawBits() );
	return *this;
}

Fixed Fixed::operator+( const Fixed& target ) {
	float a = this->toFloat();
	float b = target.toFloat();
	Fixed ret( a + b );
	return ret;
}

Fixed Fixed::operator-( const Fixed& target ) {
	float a = this->toFloat();
	float b = target.toFloat();
	Fixed ret( a - b );
	return ret;
}
Fixed Fixed::operator*( const Fixed& target ) {
	float a = this->toFloat();
	float b = target.toFloat();
	Fixed ret( a * b );
	return ret;
}
Fixed Fixed::operator/( const Fixed& target ) {
	if ( target.fixedPointNum == 0 ) {
		std::cout << "denominator is Zero." << std::endl;
		return ( *this );
	}
	float a = this->toFloat();
	float b = this->toFloat();
	Fixed ret( a / b );
	return ret;
}

bool Fixed::operator<( const Fixed& target ) {
	return this->getRawBits() < target.getRawBits();
}
bool Fixed::operator>( const Fixed& target ) {
	return this->getRawBits() > target.getRawBits();
}
bool Fixed::operator==( const Fixed& target ) {
	return this->getRawBits() == target.getRawBits();
}
bool Fixed::operator<=( const Fixed& target ) {
	return this->getRawBits() <= target.getRawBits();
}
bool Fixed::operator>=( const Fixed& target ) {
	return this->getRawBits() >= target.getRawBits();
}
bool Fixed::operator!=( const Fixed& target ) {
	return this->getRawBits() != target.getRawBits();
}

Fixed& Fixed::operator++( void ) {
	this->fixedPointNum += 1;
	return *this;
}
Fixed Fixed::operator++( int ) {
	Fixed ret = *this;
	this->fixedPointNum += 1;
	return ret;
}
Fixed& Fixed::operator--( void ) {
	this->fixedPointNum -= 1;
	return *this;
}
Fixed Fixed::operator--( int ) {
	Fixed ret = *this;
	this->fixedPointNum -= 1;
	return ret;
}

int Fixed::getRawBits( void ) const { return this->fixedPointNum; }
void Fixed::setRawBits( int const raw ) { this->fixedPointNum = raw; }
float Fixed::toFloat( void ) const {
	float convertToFloat( fixedPointNum );
	return convertToFloat / ( 1 << fractionalBits );
}
int Fixed::toInt( void ) const { return fixedPointNum >> fractionalBits; }

Fixed& Fixed::min( Fixed& a, Fixed& b ) {
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	return b;
}
const Fixed& Fixed::min( const Fixed& a, const Fixed& b ) {
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	return b;
}
Fixed& Fixed::max( Fixed& a, Fixed& b ) {
	if ( a.getRawBits() < b.getRawBits() )
		return b;
	return a;
}
const Fixed& Fixed::max( const Fixed& a, const Fixed& b ) {
	if ( a.getRawBits() < b.getRawBits() )
		return b;
	return a;
}

// << operator
std::ostream& operator<<( std::ostream& os, const Fixed& fixed ) {
	return os << fixed.toFloat();
}
