// Brian Bentson Matt Sheehan
#ifndef city_H
#define city_H
#include "string.h"

#include <iostream>
using namespace std;

class City
{
public:
	City();
  City(const char n[80], const int horiz, const int verti, const char h, const char v );
	
   bool operator< (const City &rhs) const;
 const City operator= (const City &rhs) const;
int longa;
int lat;
char lo;
char la;
char name[80];
	
	 

};

#endif
