#include "factorization.h"
using namespace std;

vector<vector<int>> factorization(int N)
{
    vector<vector<int>> res;
    for (int i = 2; i * i <= N; i++)
    {
        int count = 0;
        while (N % i == 0)
        {
            count++;
            N /= i;
        }
        if (count > 0)
        {
            res.push_back({i, count});
        }
    }
    if (N > 1)
    {
        res.push_back({N, 1});
    }

    return res;
}