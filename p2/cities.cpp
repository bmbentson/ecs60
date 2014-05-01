// Author: Sean Davis
#include "cities.h"

Cities::Cities()
{

BinarySearchTree<City> database;
}  // Cities()



void Cities::ShowArea(const char *name, int range)
{
} // ShowArea()


void Cities::ShowLocation(int latitude, char LatDirection, int longitude,
    char LongDirection)
{
int check;
BinarySearchTree<City> db2 = database;

while(!db2.isEmpty()){
 if((db2.findMin()).lat == latitude)
	if((db2.findMin()).La == latDirection)
		if((db2.findMin()).long == longitude)
			if((db2.findMin()).lo == LongDirection){
					check =1;
					City temp((db2.findMin().name), latitude, longitude, LatDirection, LongDirection);}


db2.remove(db2.findMin());
}


if(check ==1){
	puts(temp.name);
printf(' %d %c %d %c",temp.lat, temp.la, temp.log, temp.long);
}

else
printf("City not found \n");



} // ShowLocation()


void Cities::ShowName(const char *name)
{

City temp(name,0,0,N,E);
temp =database.find(temp);

if(temp == NULL){
puts(name);
printf(" city not found. \n");
}

else{
puts(temp.name);
printf(' %d %c %d %c",temp.lat, temp.la, temp.log, temp.long);

}
} // ShowName()


istream& operator>> (istream &in, Cities &rhs)
{
 char buffer[80],name[80],country[80], direct1, direct2, dummy ;
int log, lat;
While(!in.eof()){
getline(in, name, ',');
 getline(in, country, ',');
    in >> lat;
    in >> dummy;
    in >> direct1;
    in >> dummy;
    in >> log;
    in >> dummy;
    in >> direct2;
    in >> dummy;

name= name.append(", ");
name = name.append(country);

City temp(name,lat,log, direct1,direct2);

database.inser(temp);

}
  return in;
}  // operator>>
