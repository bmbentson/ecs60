// Author: Sean Davis
#include "city.h"

City::City( n, horiz, verti, h, v)
{
name =n;
long = verti;
lat = horiz;
lo = v;
la = h;
}  // City()



bool City::operator< (City &rhs)
{
 return  (this->name).compare(rhs->name);
}  // key
