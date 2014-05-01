// Brian Bentson Matt Sheehan
#include "BinaryTree.h"
#include <iostream>
using namespace std;

class Charh// characterholder class
{
  char letter;
  int count;
  
public:
  Charh(char N = '\0', int C = 0):letter(N), count(C){}
  char Getletter(){return letter;}
  int Getcount() {return count;}
  
  bool operator< (const Charh &rhs)const  { return count < rhs.count;}
  friend ostream& operator<< (ostream &out, Charh &rhs){out<<rhs.letter<<' '<<rhs.count; return out;}


};



int main(){




}

