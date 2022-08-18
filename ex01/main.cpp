#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(10);
  Fixed const c(42.42f);
  Fixed const d(b);

  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;

  return 0;
}