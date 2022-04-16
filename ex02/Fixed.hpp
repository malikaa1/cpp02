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
    void operator=(const Fixed &fixed);
    float toFloat(void) const;
    int toInt(void) const;
    friend std::ostream &operator<<(std::ostream &output, const Fixed &f);

    friend bool operator<(const Fixed &a, const Fixed &b);
    friend bool operator<=(const Fixed &a, const Fixed &b);
    friend bool operator>(const Fixed &a, const Fixed &b);
    friend bool operator>=(const Fixed &a, const Fixed &b);
    friend bool operator==(const Fixed &a, const Fixed &b);
    friend bool operator!=(const Fixed &a, const Fixed &b);

    friend Fixed operator+(const Fixed &a, const Fixed &b);
    friend Fixed operator-(const Fixed &a, const Fixed &b);
    friend Fixed operator*(const Fixed &a, const Fixed &b);
    friend Fixed operator/(const Fixed &a, const Fixed &b);

    Fixed operator++(void);           //++a
    Fixed operator++(int);        // a++
    Fixed operator--(int); // a--
    Fixed operator--(void);    //--a

    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);



private:
    int value;
    static const int fractional_bits = 8;
};
#endif