#include "Fixed.hpp"

int main(void)
{
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  Fixed const c(Fixed(10.10f) / Fixed(2));
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

  std::cout << c << std::endl;
	std::cout <<c - b<< std::endl;
	std::cout <<c + b<< std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (c > b) << std::endl;
	std::cout << (c >= b) << std::endl;
	std::cout << (c == b) << std::endl;
	std::cout << (c != b) << std::endl;
	std::cout << Fixed::min(c , b) << std::endl;
  return 0;
}