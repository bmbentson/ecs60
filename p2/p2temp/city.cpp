// Brian Bentson Matt Sheehan
#include "city.h"

City::City()
{
strcpy(name,"");
longa = NULL;
lat = NULL;
lo = NULL;
la = NULL;
}  // City()

City::City( const char *n, const int horiz,const  int verti, const char h, const char v)
{
strcpy(name,n);
longa = verti;
lat = horiz;
lo = v;
la = h;
}  // City()



 bool City::operator< (const City &rhs) const
{
 return  strcmp(name,rhs.name);
}  // key

const City City::operator= ( const City  &rhs) const{

return City(rhs.name, rhs.longa, rhs.lat, rhs.lo, rhs.la);
//strcpy(name, rhs.name); 
//longa = rhs.longa;
//lat = rhs.lat;
//lo = rhs.lo;
//la = rhs.la;



}





