#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
    this->value = 0;
}

Fixed::Fixed(const int v)
{
    this->value = v << this->fractional_bits;
}

Fixed::Fixed(const float v)
{
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
    return;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

Fixed::Fixed(const Fixed &a)
{
    this->value = a.value;
}

void Fixed::operator=(const Fixed &fixed)
{
    this->value = fixed.value;
}

std::ostream &operator<<(std::ostream &output, const Fixed &f)
{
    output << f.toFloat();
    return output;
}

bool operator<(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() < b.getRawBits());
}

bool operator<=(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() <= b.getRawBits());
}
bool operator>(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() > b.getRawBits());
}

bool operator>=(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() >= b.getRawBits());
}
bool operator==(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() == b.getRawBits());
}

bool operator!=(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() != b.getRawBits());
}

Fixed operator+(const Fixed &a, const Fixed &b)
{
    Fixed result;
    result.setRawBits((a.getRawBits() + b.getRawBits()) >> b.fractional_bits);
    return result;
}

Fixed operator-(const Fixed &a, const Fixed &b)
{
    Fixed result;
    result.setRawBits((a.getRawBits() - b.getRawBits()) >> b.fractional_bits);
    return result;
}

Fixed operator*(const Fixed &a, const Fixed &b)
{
    Fixed result;
    result.setRawBits((a.getRawBits() * b.getRawBits()) >> b.fractional_bits);
    return result;
}

Fixed operator/(const Fixed &a, const Fixed &b)
{
    Fixed result;

    if (b.getRawBits() == 0)
        return result;

    result.setRawBits((a.getRawBits() / b.getRawBits()) >> b.fractional_bits);
    return result;
}

Fixed Fixed::operator++(int) // a++
{
    Fixed a(*this);
    ++(*this);
    return a;
}

Fixed Fixed::operator++() //++a
{
    this->value++;
    return *this;
}

Fixed Fixed::operator--(int) // a--
{
    Fixed a(*this);
    --(*this);
    return a;
}

Fixed Fixed::operator--() //--a
{
    this->value--;
    return *this;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.toFloat() < b.toFloat())
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.toFloat() > b.toFloat())
        return a;
    return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.toFloat() < b.toFloat())
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.toFloat() > b.toFloat())
        return a;
    return b;
}
