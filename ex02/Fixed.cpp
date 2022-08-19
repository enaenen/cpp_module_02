#include "Fixed.hpp"

Fixed::Fixed(void) : fixedPointNum() {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fpn) {
  std::cout << "Int constructor called" << std::endl;
  fixedPointNum = fpn << fractionalBits;
}
Fixed::Fixed(const float fpn) {
  std::cout << "Float constructor called" << std::endl;

  fixedPointNum = (int)roundf(fpn * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed& Fixed::operator=(const Fixed& op) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &op) this->setRawBits(op.getRawBits());
  return *this;
}
// << operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  return os << fixed.toFloat();
}
int Fixed::getRawBits(void) const { return this->fixedPointNum; }

void Fixed::setRawBits(int const raw) { this->fixedPointNum = raw; }

float Fixed::toFloat(void) const {
  float convertToFloat(static_cast<float>(fixedPointNum));
  return convertToFloat / (1 << fractionalBits);
}

int Fixed::toInt(void) const { return fixedPointNum >> fractionalBits; }