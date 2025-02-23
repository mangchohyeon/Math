#include "Fraction.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  fraction *a = new fraction[105];
  a[0] = -14;
  ofstream outfile("2023 9모.txt");
  if(!outfile)
  {
    cout << "Can't open the txt file\n";
    delete []a;
    return -1;
  }
  
  for(int n = 1; n < 100; n++)
  {
    if(a[n-1] < 5 || a[n-1] > 5)
    {
      a[n] = a[n-1] + 3;
    }
    else if(a[n-1] >= 5 || a[n-1] <= 5)
    {
      a[n] = -1/2*a[n-1];
    }
    outfile << a[n];
  }

  cout << "Storing is ended completely!\n";  

  return 0;
}