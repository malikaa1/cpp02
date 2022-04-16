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
    Fixed &operator=(const Fixed &fixed);
    float toFloat(void) const;
    int toInt(void) const;

    bool operator>(Fixed const &inst) const;
    bool operator<(Fixed const &inst) const;
    bool operator==(Fixed const &inst) const;
    bool operator>=(Fixed const &inst) const;
    bool operator<=(Fixed const &inst) const;
    bool operator!=(Fixed const &inst) const;

    Fixed operator/(Fixed const &inst) const;
    Fixed operator-(Fixed const &inst) const;
    Fixed operator+(Fixed const &inst) const;
    Fixed operator*(Fixed const &inst) const;
    Fixed operator++(void); //++a
    Fixed operator++(int);  // a++
    Fixed operator--(int);  // a--
    Fixed operator--(void); //--a

    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);

private:
    int value;
    static const int fractional_bits = 8;
};
std::ostream &operator<<(std::ostream &output, const Fixed &f);

#endif