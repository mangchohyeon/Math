#ifndef GEOMETRIC_H
#define GEOMETRIC_H

#include <iostream>
using namespace std;

class geometric {
public:
    long long a; // 첫 번째 항
    long long r; // 공비

    // 생성자
    geometric();                          // 기본 생성자 (a와 r을 0으로 초기화)
    geometric(long long first, long long ratio); // 초기값 생성자

    // 멤버 함수
    // n번째 항을 반환: a * r^(n-1)
    long long get_an(long long n) const;

    // 1번째 항부터 n번째 항까지의 합을 반환합니다.
    // r == 1인 경우: a * n, 그렇지 않으면 a*(r^n - 1)/(r - 1)
    long long get_sum(int n) const;

    // n1번째 항부터 n2번째 항까지의 합을 반환합니다.
    long long get_sum(int n1, int n2) const;

    // 연산자 오버로딩 (각 연산은 두 등비수열의 대응하는 a와 r에 대해 연산)
    geometric operator+(const geometric& b) const;
    geometric operator-(const geometric& b) const;
    geometric operator*(const geometric& b) const;
    geometric operator/(const geometric& b) const; // b의 a와 r이 0이 아닌지 확인하여 처리

    // 대입 연산자
    geometric& operator=(const geometric& b);

    // 비교 연산자 (lexicographical order: a를 우선, 그 다음 r을 비교)
    bool operator==(const geometric& b) const;
    bool operator!=(const geometric& b) const;
    bool operator<(const geometric& b) const;
    bool operator>(const geometric& b) const;
    bool operator<=(const geometric& b) const;
    bool operator>=(const geometric& b) const;
};

#endif // GEOMETRIC_H