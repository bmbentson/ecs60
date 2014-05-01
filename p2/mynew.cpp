#define _USE_OLD_RW_STL
#include "mynew.h"
#include <cstdlib> //needed for malloc
#include <iostream>


using namespace std;

int maxRAM = 0;
int currentRAM = 0;


void* operator new(size_t size) throw (std::bad_alloc) //size is in bytes
{
	int* ptr = (int*) malloc(size);
  currentRAM += ptr[-1];
  if(currentRAM > maxRAM)
    maxRAM = currentRAM;

  return (void*) ptr;
}

void operator delete(void* to_delete) throw (std::bad_alloc)
{
  currentRAM -= ((int*) to_delete)[-1];
	free(to_delete);
}

void* operator new[] (size_t size) throw (std::bad_alloc) //size is in bytes
{
  int* ptr = (int*) malloc(size);
#ifdef SHOW_SIZE
  cout << "Requesting: " << size << " Getting: " << ptr[-1] << endl;
#endif
  currentRAM += ptr[-1];
  if(currentRAM > maxRAM)
    maxRAM = currentRAM;

  return (void*) ptr;
}

void operator delete[] (void* to_delete) throw (std::bad_alloc)
{
  currentRAM -= ((int*) to_delete)[-1];
	free(to_delete);
}


