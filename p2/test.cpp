#include "mynew.h"
#include <iostream>
using namespace std;

extern int currentRAM;

int main()
{
  int *ar[1000];
  for(int i = 0; i < 1000; i++)
    ar[i] = new int;

  cout << currentRAM << endl;

  for(int i = 0; i < 1000; i++)
    delete ar[i];
  
  cout << currentRAM << endl;

  return 0;
} 
