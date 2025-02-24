#include "geometric.h"
#include <cmath>  // pow 함수를 사용하기 위함

// 기본 생성자: a와 r을 0으로 초기화합니다.
// (공비는 보통 1로 설정할 수도 있으나 여기서는 0으로 초기화합니다.)
geometric::geometric() : a(0), r(0) {}

// 초기값 생성자: 첫 번째 항(first)과 공비(ratio)를 설정합니다.
geometric::geometric(long long first, long long ratio) : a(first), r(ratio) {}

// n번째 항을 반환합니다. 공식: a * r^(n-1)
// pow 함수는 double을 반환하므로, long long으로 캐스팅합니다.
long long geometric::get_an(long long n) const {
    return a * static_cast<long long>(pow(r, n - 1));
}

// 1번째 항부터 n번째 항까지의 합을 반환합니다.
// 공비 r이 1이면 S(n)= a*n, 그렇지 않으면 S(n)= a*(r^n - 1)/(r - 1)
long long geometric::get_sum(int n) const {
    if(r == 1) {
        return a * n;
    } else {
        return a * (static_cast<long long>(pow(r, n)) - 1) / (r - 1);
    }
}

// n1번째 항부터 n2번째 항까지의 합을 반환합니다.
long long geometric::get_sum(int n1, int n2) const {
    if(n1 > n2) return 0;
    if(n1 == 1) return get_sum(n2);
    return get_sum(n2) - get_sum(n1 - 1);
}

// operator+ : 두 등비수열의 각 항을 더합니다.
// 결과 등비수열의 첫 항은 (a1 + a2), 공비는 (r1 + r2)가 됩니다.
geometric geometric::operator+(const geometric& b) const {
    return geometric(this->a + b.a, this->r + b.r);
}

// operator- : 두 등비수열의 각 항을 뺍니다.
// 결과 등비수열의 첫 항은 (a1 - a2), 공비는 (r1 - r2)가 됩니다.
geometric geometric::operator-(const geometric& b) const {
    return geometric(this->a - b.a, this->r - b.r);
}

// operator* : 두 등비수열의 각 항을 곱합니다.
// 결과: (a1 * b.a, r1 * b.r)
geometric geometric::operator*(const geometric& b) const {
    return geometric(this->a * b.a, this->r * b.r);
}

// operator/ : 두 등비수열의 각 항을 나눕니다.
// 단, 나누는 등비수열 b의 a 또는 r이 0일 경우 0으로 처리합니다.
geometric geometric::operator/(const geometric& b) const {
    long long newA = (b.a != 0) ? (this->a / b.a) : 0;
    long long newR = (b.r != 0) ? (this->r / b.r) : 0;
    return geometric(newA, newR);
}

// operator= : 대입 연산자. 자기 자신과 동일하지 않을 경우에만 대입합니다.
geometric& geometric::operator=(const geometric& b) {
    if(this != &b) {
        this->a = b.a;
        this->r = b.r;
    }
    return *this;
}

// operator== : 두 등비수열이 동일한지를 a와 r를 기준으로 판단합니다.
bool geometric::operator==(const geometric& b) const {
    return (this->a == b.a) && (this->r == b.r);
}

bool geometric::operator!=(const geometric& b) const {
    return !(*this == b);
}

// 비교 연산자: 먼저 a를 비교하고, 같으면 r을 비교합니다.
bool geometric::operator<(const geometric& b) const {
    if(this->a != b.a)
        return this->a < b.a;
    return this->r < b.r;
}

bool geometric::operator>(const geometric& b) const {
    return b < *this;
}

bool geometric::operator<=(const geometric& b) const {
    return !(*this > b);
}

bool geometric::operator>=(const geometric& b) const {
    return !(*this < b);
}