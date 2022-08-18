#include "Fixed.hpp"

Fixed::Fixed(void) : fixedPointNum() {
  std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
Fixed::Fixed(const Fixed& fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}
Fixed& Fixed::operator=(const Fixed& op) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &op) this->setRawBits(op.getRawBits());
  return *this;
}
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->fixedPointNum;
}
void Fixed::setRawBits(int const raw) { this->fixedPointNum = raw; }