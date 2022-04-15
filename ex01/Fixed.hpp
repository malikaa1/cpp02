#ifndef FIXES_HPP
#define FIXES_HPP

#include <iostream>
class Fixed
{
public:
    Fixed(void);
    Fixed(const Fixed &a);
    Fixed(const int v);
    Fixed(const float v);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    void operator=(const Fixed& fixed);
    float toFloat( void ) const;
    int toInt( void ) const;
    friend std::ostream &operator<<(std::ostream &output, const Fixed &f);

    

private:
    int value;
    static const int fractional_bits = 8;

};
#endif