#ifndef FIXES_HPP
#define FIXES_HPP

#include <iostream>
class Fixed
{
public:
    Fixed(void);
    Fixed(Fixed &a);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed &operator=(const Fixed& fixed);

private:
    int value;
    static const int fractional_bits = 8;
};
#endif