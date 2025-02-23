#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

int main() 
{
  clock_t time_start,time_finish;

  time_start = clock();
  // 소수들 담아줄 배열
  int *prime = new int[25000];
  int count = 1, start = 3, end = 50000;
  prime[0] = 2; // 첫 번째 소수는 2

  // 소수 찾기
  for (int n = start; n < end; n++) 
  {
    int flag = 1; // 소수임을 나타내는 플래그
    int limit = sqrt(n); // 제곱근 계산
    for (int j = 0; j < count && prime[j] <= limit; j++) 
    {
      if (n % prime[j] == 0) // 소수가 아님
      {
        flag = 0;
        break;
      }
    }

    if (flag) // 소수라면 prime에 추가
    {
      prime[count] = n;
      count++;
    }
  }

  // 파일에 소수 저장
  ofstream outfile1("Prime Numbers.txt", ios ::out); // Prime Numbers.txt 파일 열기
  if (!outfile1) 
  {
    cerr << "Prime Numbers.txt를 열 수 없습니다.\n";
    delete[] prime; // 동적 메모리 해제
    return 1;
  }

  cout << "Restoring Prime numbers to Prime Numbers.txt\n";
  cout << "Number Of Prime : " << count << "\n\n";
  cout << "start : " << 1 << " end : " << end << "\n\n";

  for (int i = 0; i < count; i++) 
  {
    outfile1 << prime[i];
    if (i != count - 1) {
      outfile1 << '\n';
    }
  }

  outfile1.close(); // 파일 닫기

  ofstream outfile2("Prime Information.txt", ios ::out);
  if (!outfile2) 
  {
    cerr << "Prime Information.txt를 열 수 없습니다.\n";
    delete[] prime;
    return 1;
  }

  outfile2 << "Number of Primes : " << count << '\n';
  outfile2 << "end : " << end << '\n';
  outfile2.close();

  time_finish = clock();
  double duration = ((double)(time_finish - time_start))/ 1000;
  cout << "time : " << duration << '\n';
  

  delete[] prime; // 동적 메모리 해제

  return 0;
}