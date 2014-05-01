// Author: Sean Davis
#ifndef cityH
#define cityH
#include "strings.h"

#include <iostream>
using namespace std;

class City
{
public:
  City(char n[80], int horiz, int verti, char h, char v );

   bool operator< (City &rhs);
int long;
int lat;
char lo[4];
char la[4];
char name[80];
	
	 

};

#endif
