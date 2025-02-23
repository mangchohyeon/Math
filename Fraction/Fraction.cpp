#include "Fraction.h"

// 최대공약수를 이용한 약분 함수
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 약분하는 함수
void fraction::reduce()
{
    if (den < 0) // 분모가 음수일 경우, 부호를 조정
    {
        num = -num;
        den = -den;
    }
    long long g = gcd(abs(num), abs(den));
    num /= g;
    den /= g;
}

// 기본 생성자
fraction::fraction(long long n, long long d) : num(n), den(d)
{
    reduce();
}

// int 생성자
fraction::fraction(int n) : num(n), den(1)
{
}

// double을 fraction으로 변환하는 생성자
fraction::fraction(double d)
{
    const long long precision = 1'000'000'000LL; // 정밀도를 위해 10^9 사용
    num = round(d * precision);
    den = precision;
    reduce();
}

// fraction과 int, double 간의 연산 지원
fraction fraction::operator+(int n) const { return *this + fraction(n); }
fraction fraction::operator-(int n) const { return *this - fraction(n); }
fraction fraction::operator*(int n) const { return *this * fraction(n); }
fraction fraction::operator/(int n) const { return *this / fraction(n); }

fraction fraction::operator+(double d) const { return *this + fraction(d); }
fraction fraction::operator-(double d) const { return *this - fraction(d); }
fraction fraction::operator*(double d) const { return *this * fraction(d); }
fraction fraction::operator/(double d) const { return *this / fraction(d); }

// 반대 순서 연산 지원
fraction operator+(int n, const fraction& f) { return fraction(n) + f; }
fraction operator-(int n, const fraction& f) { return fraction(n) - f; }
fraction operator*(int n, const fraction& f) { return fraction(n) * f; }
fraction operator/(int n, const fraction& f) { return fraction(n) / f; }

fraction operator+(double d, const fraction& f) { return fraction(d) + f; }
fraction operator-(double d, const fraction& f) { return fraction(d) - f; }
fraction operator*(double d, const fraction& f) { return fraction(d) * f; }
fraction operator/(double d, const fraction& f) { return fraction(d) / f; }

// 대입 연산자 오버로딩
fraction& fraction::operator=(const fraction& other)
{
    num = other.num;
    den = other.den;
    return *this;
}

fraction& fraction::operator=(double d)
{
    *this = fraction(d); // double → fraction 변환 후 대입
    return *this;
}

fraction& fraction::operator=(int n)
{
    num = n;
    den = 1;
    return *this;
}

// 출력 연산자 오버로딩 
std::ostream& operator<<(std::ostream& os, const fraction& f)
{
    os << f.num << "/" << f.den;
    return os;
}

// 입력 연산자 오버로딩 (콘솔)
std::istream& operator>>(std::istream& is, fraction& f)
{
    char slash;
    is >> f.num >> slash >> f.den;
    f.reduce();
    return is;
}

// 입력 연산자 오버로딩 (파일)
std::ifstream& operator>>(std::ifstream& ifs, fraction& f)
{
    char slash;
    ifs >> f.num >> slash >> f.den;
    f.reduce();
    return ifs;
}