// Brian Bentson Matt Sheehan
#include "cities.h"
#include "city.h"
#include "string.h"

#include "stdlib.h"







void Cities::ShowArea(const char *name, int range)
{


int p1, p2;
char p3,p4;
 char tempname[80];
strcpy(tempname,name);
City origin(tempname,0,0,'N','E');
origin =database.find(origin);
int h;

BinarySearchTree<City> db2 = database;



while(!db2.isEmpty()){

 p2 = (db2.findMin().longa);
p3= (db2.findMin().la);

strcpy(tempname,(db2.findMin().name));
City temp(tempname,(db2.findMin().lat), p2, p3,(db2.findMin().lo));
db2.remove(db2.findMin());



if(origin.lo == temp.lo && origin.la == temp.la)
	 h=sqrt((origin.lat - temp.lat)*(origin.lat - temp.lat) + (origin.longa - temp.longa)*(origin.longa - temp.longa));

if(origin.lo != temp.lo && origin.la == temp.la)
	 h=sqrt((origin.lat - temp.lat)*(origin.lat - temp.lat) + (origin.longa + temp.longa)*(origin.longa + temp.longa));

if(origin.lo == temp.lo && origin.la != temp.la)
	 h=sqrt((origin.lat + temp.lat)*(origin.lat + temp.lat) + (origin.longa - temp.longa)*(origin.longa - temp.longa));

if(origin.lo != temp.lo && origin.la != temp.la)
	 h=sqrt((origin.lat + temp.lat)*(origin.lat + temp.lat) + (origin.longa + temp.longa)*(origin.longa + temp.longa));

		



if(67*h <= range){
puts(temp.name);
printf(" %d %c %d %c \n",temp.lat, temp.la, temp.longa, temp.lo);
}

}






printf("\n");




} // ShowArea()


void Cities::ShowLocation(int latitude, char LatDirection, int longitude,
    char LongDirection)
{
char tempname[80];
City temp;
int check;
BinarySearchTree<City> db2 = database;

while(!db2.isEmpty()){
 if((db2.findMin()).lat == latitude)
	if((db2.findMin()).la == LatDirection)
		if((db2.findMin()).longa == longitude)
			if((db2.findMin()).lo == LongDirection){
					check =1;
						 						strcpy(tempname,(db2.findMin().name));

					City a(tempname, latitude, longitude, LatDirection, LongDirection);
						temp = a;}


db2.remove(db2.findMin());
}


if(check ==1){
	puts(tempname);
printf(" %d %c %d %c",temp.lat, temp.la, temp.longa, temp.lo);
}

else
printf("A City was not found at that location. \n");


printf("\n");

} // ShowLocation()


void Cities::ShowName(const char *name)
{

 char tempname[80];
strcpy(tempname,name);


City temp(tempname,0,0,'N','E');
temp =database.find(temp);

if(temp.name == NULL){
puts(name);
printf(" was not found in the database. \n");
}

else{
puts(temp.name);
printf(" %d %c %d %c",temp.lat, temp.la, temp.longa, temp.lo);

}


printf("\n");

} // ShowName()


istream& operator>> (istream &in, Cities &rhs)
{
 char buffer[80],name[80],country[80], direct1, direct2, dummy,  *ptr;
int log, lat;
in.getline(buffer,80);


while(!in.eof()){
in.getline(buffer,80);
ptr= strtok(buffer,",");
strcpy(name,ptr);
ptr = strtok(NULL,",");
strcpy(country,ptr);
ptr = strtok(NULL,",");
     lat= atoi(ptr);
   ptr = strtok(NULL,",");
     direct1= ptr[0];
   ptr = strtok(NULL,",");
     log= atoi(ptr);
    ptr = strtok(NULL,",");
     direct2= ptr[0];
   
    
   



strcat(name,", ");
strcat(name,country);

City temp(name,lat,log, direct1,direct2);

rhs.database.insert(temp);

}
  return in;
}  // operator>>
