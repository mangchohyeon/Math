#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <fstream> // 파일 입출력
#include <cmath>

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

    // 연산자 오버로딩 (fraction + fraction)
    fraction operator+(const fraction& other) const;
    fraction operator-(const fraction& other) const;
    fraction operator*(const fraction& other) const;
    fraction operator/(const fraction& other) const;

    // 연산자 오버로딩 (fraction + int, double)
    fraction operator+(int n) const;
    fraction operator-(int n) const;
    fraction operator*(int n) const;
    fraction operator/(int n) const;

    fraction operator+(double d) const;
    fraction operator-(double d) const;
    fraction operator*(double d) const;
    fraction operator/(double d) const;

    // 반대 순서 연산 지원 (int, double + fraction)
    friend fraction operator+(int n, const fraction& f);
    friend fraction operator-(int n, const fraction& f);
    friend fraction operator*(int n, const fraction& f);
    friend fraction operator/(int n, const fraction& f);

    friend fraction operator+(double d, const fraction& f);
    friend fraction operator-(double d, const fraction& f);
    friend fraction operator*(double d, const fraction& f);
    friend fraction operator/(double d, const fraction& f);

    // 대입 연산자
    fraction& operator=(const fraction& other);
    fraction& operator=(double d);
    fraction& operator=(int n);

    // 비교 연산자 오버로딩
    bool operator<(const fraction& other) const;
    bool operator>(const fraction& other) const;
    bool operator<=(const fraction& other) const;
    bool operator>=(const fraction& other) const;
    bool operator==(const fraction& other) const;
    bool operator!=(const fraction& other) const;

    // double, int 비교 지원
    bool operator<(double d) const;
    bool operator>(double d) const;
    bool operator<=(double d) const;
    bool operator>=(double d) const;
    bool operator==(double d) const;
    bool operator!=(double d) const;

    bool operator<(int n) const;
    bool operator>(int n) const;
    bool operator<=(int n) const;
    bool operator>=(int n) const;
    bool operator==(int n) const;
    bool operator!=(int n) const;

    // 출력 연산자 오버로딩
    friend std::ostream& operator<<(std::ostream& os, const fraction& f);
    friend std::ofstream& operator<<(std::ofstream& ofs, const fraction& f); // 파일 출력

    // 입력 연산자 오버로딩
    friend std::istream& operator>>(std::istream& is, fraction& f);
    friend std::ifstream& operator>>(std::ifstream& ifs, fraction& f); // 파일 입력
};

#endif // FRACTION_H