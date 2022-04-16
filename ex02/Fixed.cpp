#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
    this->value = 0;
}

Fixed::Fixed(const Fixed &a)
{
    *this = a;
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

Fixed &Fixed::operator=(const Fixed &fixed)
{
    this->value = fixed.value;
    return *this;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

std::ostream &operator<<(std::ostream &output, const Fixed &f)
{
    output << f.toFloat();
    return output;
}

bool Fixed::operator>(const Fixed &inst) const
{
    return (this->value > inst.value);
}

bool Fixed::operator<(const Fixed &inst) const
{
    return (inst.value > this->value);
}

bool Fixed::operator>=(const Fixed &inst) const
{
    return (this->value >= inst.value);
}

bool Fixed::operator<=(const Fixed &inst) const
{
    return (this->value <= inst.value);
}

bool Fixed::operator==(const Fixed &inst) const
{
    return (inst.value == this->value);
}

bool Fixed::operator!=(const Fixed &inst) const
{
    return (inst.value != this->value);
}

Fixed Fixed::operator*(Fixed const &inst) const
{
    Fixed res(this->toFloat() * inst.toFloat());
    return (res);
}
Fixed Fixed::operator+(Fixed const &inst) const
{
    Fixed res(this->toFloat() + inst.toFloat());
    return (res);
}
Fixed Fixed::operator-(Fixed const &inst) const
{
    Fixed res(this->toFloat() - inst.toFloat());
    return (res);
}

Fixed Fixed::operator/(Fixed const &inst) const
{
    if (inst.toFloat() != 0)
    {
        Fixed res(this->toFloat() / inst.toFloat());
        return (res);
    }
    else
    {
        std::cout << "sorry you cannot make a division with 0 " << std::endl;
        return 0;
    }
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
