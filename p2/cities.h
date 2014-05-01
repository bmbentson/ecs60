// Author: Sean Davis
#ifndef citiesH
#define citiesH

#include <iostream>
using namespace std;

class Cities
{
public:
  Cities();
  void ShowArea(const char *name, int range);
  void ShowLocation(int latitude, char LatDirection, int longitude,
    char LongDirection);
  void ShowName(const char *name);
  friend istream& operator>> (istream &in, Cities &rhs);
};

#endif
