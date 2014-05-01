#ifndef course_H
#define course_H

#include "BinarySearchTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assignment.h"
#include "Student.h"












      
        class Course
        {
	
	
		
          public:
	BinarySearchTree<Student> roster;
	assignment maxgrades[25];
	
	int crn;
	
            Course(int c=0 ):roster(Student ()){crn =c;}
            
       void addStudent(const char SID[12]){
char copySID[12];
strcpy(copySID,SID);
char *ptr;
char str[20];
int ssid;
ptr= strtok(copySID,"-");
strcpy(str,ptr);
ptr = strtok(NULL,"-");
strcat(str,ptr);
ptr = strtok(NULL,"-");
     strcat(str,ptr);
   

ssid= atoi(str);
    
   Student temp(ssid);

roster.insert(temp);



} // addStudent()





	void updatestudent(const char SID[12], assignment &a){

char copySID[12];
strcpy(copySID,SID);
char *ptr;
char str[20];
int ssid;
ptr= strtok(copySID,"-");
strcpy(str,  ptr);
ptr = strtok(NULL,"-");
strcat(str,ptr);
ptr = strtok(NULL,"-");
     strcat(str,ptr);
   

ssid= atoi(str);
    
   Student temp(ssid);





temp = (roster.find(temp));
roster.remove(temp);

temp.setgrade(a);
roster.insert(temp);

}



	void removeStudent(const char SID[12]){


char copySID[12];
strcpy(copySID,SID);
char *ptr;
char str[20];
int ssid;
ptr= strtok(copySID,"-");
strcpy(str, ptr);
ptr = strtok(NULL,"-");
strcat(str,ptr);
ptr = strtok(NULL,"-");
     strcat(str,ptr);
   

ssid= atoi(str);
Student temp(ssid);





roster.remove(temp); 


}//remove student




	Student findStudent(const char SID[12]){


char copySID[12];
strcpy(copySID,SID);
char *ptr;
char str[20];
int ssid;
ptr= strtok(copySID,"-");
strcpy(str, ptr);
ptr = strtok(NULL,"-");
strcat(str,ptr);
ptr = strtok(NULL,"-");
     strcat(str,ptr);
   
   

ssid= atoi(str);
Student temp(ssid);





 return roster.find(temp); 


}








	void addAssignment(assignment &ass){


int i =0;
while(i<25 && (maxgrades[i]).getgrade()  !=0)
i++;


maxgrades[i] = ass;

}
	int getcrn(){return crn;}
	bool operator!=( const Course &rhs){	return crn != rhs.crn;}


	

	
		
            
        
           };




#endif







