// Brian Bentson Matt Sheehan
#ifndef citiesH
#define citiesH
#include "city.h"
#include "math.h"
#include "string.h"
#include "BinarySearchTree.h"

#include <iostream>
using namespace std;

class Cities
{
BinarySearchTree<City> database;
public:
  Cities():database(temp){}
  void ShowArea(const char *name, int range);
  void ShowLocation(int latitude, char LatDirection, int longitude,
    char LongDirection);
  void ShowName(const char *name);
  friend istream& operator>> (istream &in, Cities &rhs);
};

#endif
