#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

int main() 
{
    //파일에서 읽어올 줄
    string line;

    ifstream infile1("Prime Information.txt");
    
    if(!infile1.is_open())
    {
        cerr << "Can't open the infile1\n";
        return -1;
    }

    getline(infile1,line);
    string temp = line.substr(19);
    long int count = stoll(temp);                        //소수들 개수
    long int count_original = count;
    long int t = count + 25000;
    
    // 소수들 담아줄 배열
    long int *prime = new long int[t];

    getline(infile1,line);
    temp = line.substr(6);
    long int start = stoll(temp);                        //탐색 범위 시작점
    long int end = start + 50000;                       //탐색 범위 종료점

    infile1.close();

    cout << "start : " << start << ", end : " << end << '\n';
    cout << "count : " << count << '\n';
    cout << "t(count+22000) : " << t << '\n';
    
    
    
    //소수들 읽어오기
    ifstream infile2("Prime Numbers.txt");

    if(!infile2)
    {
        cerr << "Can't open infile2\n";
        delete [] prime;
        return -1;
    }
    
    for(long int i = 0; i < count; i++)
    {
        getline(infile2,line);
        long int t = stoi(line);
        prime[i] = t;
    }

    infile2.close();
    
    // 소수 찾기
    for (long int n = start; n < end; n++) 
    {
        long int flag = 1; // 소수임을 나타내는 플래그
        long int limit = sqrt(n); // 제곱근 계산
        for (long int j = 0; j < count && prime[j] <= limit; j++) 
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
    count--;
    
    // 파일에 소수 저장
    ofstream outfile1("Prime Numbers.txt", ios ::app); // Prime Numbers.txt 파일 열기
    if (!outfile1) 
    {
    cerr << "Can't open the ouutfile1\n";
    delete[] prime; // 동적 메모리 해제
    return -1;
    }
    
    cout << "Restoring Prime numbers to Prime Numbers.txt\n";
    cout << "Number Of Prime : " << count << "\n\n";
    cout << "start : " << 1 << " end : " << end << "\n\n";

    outfile1 << '\n';
    
    for (long int i = count_original; i < count; i++) 
    {
        outfile1 << prime[i];
        if (i != count - 1) 
        {
          outfile1 << '\n';
        }
    }
    
    outfile1.close(); // 파일 닫기
    
    ofstream outfile2("Prime Information.txt", ios ::out);
    if (!outfile2) 
    {
    cerr << "Can't open the outfile2\n";
    delete[] prime;
    return 1;
    }
    
    outfile2 << "Number of Primes : " << count << '\n';
    outfile2 << "end : " << end << '\n';
    outfile2.close();
    
    
    delete[] prime; // 동적 메모리 해제
    
    return 0;
}