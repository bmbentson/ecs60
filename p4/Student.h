#ifndef Student_H
#define Student_H
#include "assignment.h"



class Student
{
public:
int id;
assignment assgrades[25];

Student(int num=0){id=num;}



bool operator< (const Student &rhs)const { 
	return id<rhs.id;
}
void addgrade(assignment &grade){

int i =0;
while(i<25 && assgrades[i].getgrade() != 0)
i++;


assgrades[i] = grade;
}


void setgrade(assignment &grade){
int i=0;

while(i<25 && (strcmp(assgrades[i].getname(),grade.getname()) !=0) ) 
i++;

assgrades[i] = grade;

}


 assignment getgrade(assignment &grade){
int i=0;

while(i<25 && (strcmp(assgrades[i].getname(),grade.getname()) !=0) ) 
i++;

return assgrades[i];

}


};


#endif
