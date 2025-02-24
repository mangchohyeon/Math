#ifndef ARTHIMETIC_H
#define ARTHIMETIC_H

#include <iostream>
using namespace std;

class arthimetic {
public:
    long long a;  // 첫 번째 항
    long long d;  // 공차

    // 생성자
    arthimetic();                         // 기본 생성자 (a와 d를 0으로 초기화)
    arthimetic(long long ft, long long dif); // 초기값 생성자

    // 멤버 함수
    // n번째 항을 반환: a + (n-1)*d
    long long get_an(long long n) const;

    // 1번째 항부터 n번째 항까지의 합을 반환:
    // S(n) = n/2 * (2*a + (n-1)*d)
    long long get_sum(int n) const;

    // n1번째 항부터 n2번째 항까지의 합을 반환:
    // S(n1, n2) = S(n2) - S(n1-1)
    long long get_sum(int n1, int n2) const;

    // 연산자 오버로딩 (각 연산은 두 등차수열의 대응하는 a와 d에 대해 연산)
    arthimetic operator+(const arthimetic& b) const;
    arthimetic operator-(const arthimetic& b) const;
    arthimetic operator*(const arthimetic& b) const;
    arthimetic operator/(const arthimetic& b) const; // b의 a와 d가 0이 아닌지 확인하여 처리

    // 대입 연산자
    arthimetic& operator=(const arthimetic& b);

    // 비교 연산자 (lexicographical order: 먼저 a를, 같으면 d를 비교)
    bool operator==(const arthimetic& b) const;
    bool operator!=(const arthimetic& b) const;
    bool operator<(const arthimetic& b) const;
    bool operator>(const arthimetic& b) const;
    bool operator<=(const arthimetic& b) const;
    bool operator>=(const arthimetic& b) const;
};

#endif // ARTHIMETIC_H