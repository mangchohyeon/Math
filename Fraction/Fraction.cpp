#include "Fraction.h"

// 약분 함수
void fraction::reduce()
{
    long long g = std::gcd(num, den);
    num /= g;
    den /= g;
    if (den < 0)
    {
        num = -num;
        den = -den;
    }
}

// 생성자
fraction::fraction(long long n, long long d) : num(n), den(d)
{
    reduce();
}

fraction::fraction(int n) : num(n), den(1)
{
}

fraction::fraction(double d)
{
    const long long precision = 1000000000; // 소수점 이하 자리수
    num = static_cast<long long>(d * precision);
    den = precision;
    reduce();
}

// 사칙연산 오버로딩
fraction fraction::operator+(const fraction& other) const
{
    return fraction(num * other.den + other.num * den, den * other.den);
}

fraction fraction::operator-(const fraction& other) const
{
    return fraction(num * other.den - other.num * den, den * other.den);
}

fraction fraction::operator*(const fraction& other) const
{
    return fraction(num * other.num, den * other.den);
}

fraction fraction::operator/(const fraction& other) const
{
    return fraction(num * other.den, den * other.num);
}

// % 연산자 오버로딩
fraction fraction::operator%(const fraction& other) const
{
    fraction div_result = *this / other;
    long long quotient = div_result.num / div_result.den;
    return *this - fraction(quotient) * other;
}

// int 및 double과의 연산 지원
fraction fraction::operator+(int value) const { return *this + fraction(value); }
fraction fraction::operator-(int value) const { return *this - fraction(value); }
fraction fraction::operator*(int value) const { return *this * fraction(value); }
fraction fraction::operator/(int value) const { return *this / fraction(value); }
fraction fraction::operator%(int value) const { return *this % fraction(value); }

fraction fraction::operator+(double value) const { return *this + fraction(value); }
fraction fraction::operator-(double value) const { return *this - fraction(value); }
fraction fraction::operator*(double value) const { return *this * fraction(value); }
fraction fraction::operator/(double value) const { return *this / fraction(value); }
fraction fraction::operator%(double value) const { return *this % fraction(value); }

// 비교 연산자 오버로딩
bool fraction::operator<(const fraction& other) const { return num * other.den < other.num * den; }
bool fraction::operator>(const fraction& other) const { return num * other.den > other.num * den; }
bool fraction::operator<=(const fraction& other) const { return !(*this > other); }
bool fraction::operator>=(const fraction& other) const { return !(*this < other); }
bool fraction::operator==(const fraction& other) const { return num == other.num && den == other.den; }
bool fraction::operator!=(const fraction& other) const { return !(*this == other); }

// 대입 연산자 오버로딩
fraction& fraction::operator=(const fraction& other)
{
    num = other.num;
    den = other.den;
    return *this;
}

fraction& fraction::operator=(int value)
{
    num = value;
    den = 1;
    return *this;
}

fraction& fraction::operator=(double value)
{
    *this = fraction(value);
    return *this;
}

// 입출력 연산자 오버로딩 (std::ostream을 사용하면 std::ofstream 등 모든 스트림에서 동작)
std::ostream& operator<<(std::ostream& os, const fraction& f)
{
    os << f.num << "/" << f.den;
    return os;
}

std::istream& operator>>(std::istream& is, fraction& f)
{
    char slash;
    is >> f.num >> slash >> f.den;
    f.reduce();
    return is;
}