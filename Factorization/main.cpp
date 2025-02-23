#include "factorization.h"
using namespace std;

int main()
{
  int N;
  cout << "소인수분해하고 싶은 정수를 입력하세요 : ";
  cin >> N;

  cout << N << " = ";
  vector<vector<int>> res = factorization(N);
  for(int i = 0; i < res.size(); i++)
  {
    cout << res[i][0];
    if(res[i][1] != 1)
    {
      cout << '^' << res[i][i];
    }

    if(i != (res.size() - 1))
    {
      cout << " x ";
    }
    else
    {
      cout << '\n';
    }
  }

  
}