#ifndef assignment_H
#define assignment_H



class assignment{
public:

short grade;
char name[80];

assignment( const char n[80] = '\0', short max=-1){
strcpy(name,n);
grade = max;

}



char* getname(){
return name;
}


 short getgrade() const {
return grade;
}

void setgrade(short value=0){
grade = value;

}

const assignment operator=(const assignment &rhs) const{
assignment lhs(rhs.name, rhs.grade);

return lhs;
}

};

#endif
