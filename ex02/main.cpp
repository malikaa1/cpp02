#include "Fixed.hpp"

int main(void)
{
  Fixed a;
  Fixed d(12);
  Fixed const b(Fixed(5.05f) * Fixed(2));
  Fixed const c(Fixed(22.1f) / Fixed(4));
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a , d) << std::endl;
  std::cout << d << std::endl;
	std::cout <<a - d<< std::endl;
	std::cout <<a + d<< std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (c > b) << std::endl;
	std::cout << (c >= b) << std::endl;
	std::cout << (c == b) << std::endl;
	std::cout << (c != b) << std::endl;
  return 0;
}