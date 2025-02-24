#include "arthimetic.h"

// 기본 생성자: a와 d를 0으로 초기화합니다.
arthimetic::arthimetic() : a(0), d(0) {}

// 초기값 생성자: 첫 번째 항(ft)과 공차(dif)를 설정합니다.
arthimetic::arthimetic(long long ft, long long dif) : a(ft), d(dif) {}

// n번째 항을 반환합니다. (등차수열의 일반항 공식)
long long arthimetic::get_an(long long n) const {
    return a + (n - 1) * d;
}

// 1번째 항부터 n번째 항까지의 합을 반환합니다.
// 공식: S(n) = n/2 * (2*a + (n-1)*d)
long long arthimetic::get_sum(int n) const {
    return (long long)n * (2 * a + (n - 1) * d) / 2;
}

// n1번째 항부터 n2번째 항까지의 합을 반환합니다.
// n1이 1이면 단순히 get_sum(n2)를 반환하고, 그 외는 차이를 구합니다.
long long arthimetic::get_sum(int n1, int n2) const {
    if(n1 > n2) return 0; // 잘못된 입력에 대해 0을 반환합니다.
    if(n1 == 1) return get_sum(n2);
    return get_sum(n2) - get_sum(n1 - 1);
}

// operator+ : 두 등차수열의 각 항을 더합니다.
// 결과 등차수열의 첫 항은 (a1 + a2), 공차는 (d1 + d2)가 됩니다.
arthimetic arthimetic::operator+(const arthimetic& b) const {
    return arthimetic(this->a + b.a, this->d + b.d);
}

// operator- : 두 등차수열의 각 항을 뺍니다.
// 결과 등차수열의 첫 항은 (a1 - a2), 공차는 (d1 - d2)가 됩니다.
arthimetic arthimetic::operator-(const arthimetic& b) const {
    return arthimetic(this->a - b.a, this->d - b.d);
}

// operator* : 두 등차수열의 각 항을 곱합니다.
// 결과: (a1 * a2, d1 * d2)
// (주의: 일반적으로 등차수열의 곱셈은 정의가 애매할 수 있으므로, 단순히 대응 원소끼리 연산합니다.)
arthimetic arthimetic::operator*(const arthimetic& b) const {
    return arthimetic(this->a * b.a, this->d * b.d);
}

// operator/ : 두 등차수열의 각 항을 나눕니다.
// 단, 나누는 등차수열 b의 a 또는 d가 0일 경우에는 0으로 처리합니다.
arthimetic arthimetic::operator/(const arthimetic& b) const {
    long long newA = (b.a != 0) ? (this->a / b.a) : 0;
    long long newD = (b.d != 0) ? (this->d / b.d) : 0;
    return arthimetic(newA, newD);
}

// operator= : 대입 연산자. 자기 자신과 동일하지 않을 경우에만 대입합니다.
arthimetic& arthimetic::operator=(const arthimetic& b) {
    if(this != &b) {
        this->a = b.a;
        this->d = b.d;
    }
    return *this;
}

// operator== : 두 등차수열이 동일한지를 a와 d를 기준으로 판단합니다.
bool arthimetic::operator==(const arthimetic& b) const {
    return (this->a == b.a) && (this->d == b.d);
}

// operator!= : 두 등차수열이 다름을 반환합니다.
bool arthimetic::operator!=(const arthimetic& b) const {
    return !(*this == b);
}

// operator< : 먼저 a값을 비교하고, 같으면 d값을 비교합니다.
bool arthimetic::operator<(const arthimetic& b) const {
    if(this->a != b.a)
        return this->a < b.a;
    return this->d < b.d;
}

bool arthimetic::operator>(const arthimetic& b) const {
    return b < *this;
}

bool arthimetic::operator<=(const arthimetic& b) const {
    return !(*this > b);
}

bool arthimetic::operator>=(const arthimetic& b) const {
    return !(*this < b);
}