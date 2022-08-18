#pragma once

#include <iostream>

class Fixed {
 private:
  int fixedPointNum;
  static const int fractionalBits = 8;

 public:
  Fixed(void);
  Fixed(const Fixed& fixed);
  ~Fixed();
  Fixed& operator=(const Fixed& op);
  int getRawBits(void) const;
  void setRawBits(int const raw);
};
