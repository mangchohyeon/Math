#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <fstream>
#include <numeric> // std::gcd 사용

class fraction
{
private:
    long long num, den; // 분자, 분모

    // 약분하는 함수
    void reduce();

public:
    // 생성자
    fraction(long long n = 0, long long d = 1);
    fraction(int n);
    fraction(double d);

    // 사칙연산 오버로딩
    fraction operator+(const fraction& other) const;
    fraction operator-(const fraction& other) const;
    fraction operator*(const fraction& other) const;
    fraction operator/(const fraction& other) const;
    fraction operator%(const fraction& other) const;

    // int 및 double과 연산 지원
    fraction operator+(int value) const;
    fraction operator-(int value) const;
    fraction operator*(int value) const;
    fraction operator/(int value) const;
    fraction operator%(int value) const;

    fraction operator+(double value) const;
    fraction operator-(double value) const;
    fraction operator*(double value) const;
    fraction operator/(double value) const;
    fraction operator%(double value) const;

    // 비교 연산자 오버로딩
    bool operator<(const fraction& other) const;
    bool operator>(const fraction& other) const;
    bool operator<=(const fraction& other) const;
    bool operator>=(const fraction& other) const;
    bool operator==(const fraction& other) const;
    bool operator!=(const fraction& other) const;

    bool operator<(int value) const;
    bool operator>(int value) const;
    bool operator<=(int value) const;
    bool operator>=(int value) const;
    bool operator==(int value) const;
    bool operator!=(int value) const;

    bool operator<(double value) const;
    bool operator>(double value) const;
    bool operator<=(double value) const;
    bool operator>=(double value) const;
    bool operator==(double value) const;
    bool operator!=(double value) const;

    // 대입 연산자 오버로딩
    fraction& operator=(const fraction& other);
    fraction& operator=(int value);
    fraction& operator=(double value);

    // 입출력 연산자 오버로딩
    friend std::ostream& operator<<(std::ostream& os, const fraction& f);
    friend std::istream& operator>>(std::istream& is, fraction& f);
};

#endif // FRACTION_H