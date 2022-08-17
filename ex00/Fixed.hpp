#pragma once

#include <iostream>

class Fixed {
 private:
  int number;
  const int cNumber = 8;

 public:
  Fixed(void);
  ~Fixed();
  Fixed(const Fixed& fixed);
  void setRawBits(int const raw);
  int getRawBits(void) const;
};
