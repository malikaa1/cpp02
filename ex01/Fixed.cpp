#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const int v)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = v << this->fractional_bits;
}

Fixed::Fixed(const float v)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(v * (float)(1 << fractional_bits));
}

float Fixed::toFloat(void) const
{
    return (float)this->value / ((float)(1 << fractional_bits));
}

int Fixed::toInt(void) const
{
    return (this->value >> this->fractional_bits);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

Fixed::Fixed(const Fixed &a)
{
    std::cout << "Copy constructor called" << std::endl;
   *this = a;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = fixed.value;
    return *this;
}

std::ostream &operator<<(std::ostream &output, const Fixed &f)
{
    output << f.toFloat();
    return output;
}