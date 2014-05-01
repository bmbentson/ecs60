//Brian Bentson
#ifndef LONGINT_H
	#define LONGINT_H
	

#include <iostream>
#include "StackLi.h"
#include "dsexceptions.h"
#include "LinkedList.h"
#include <cstdlib>


class LongInt
{

  
public:
	LongInt();
	int carry;
  StackLi<int> stck;
  StackLi<int> tmp;
  

	
	const LongInt operator+(LongInt &rhs);
         LongInt operator=(LongInt const &rhs) ;
        friend ostream& operator<<(ostream &os,       LongInt &rhs);
        friend istream& operator>>(istream &is,       LongInt &rhs);
	
}; // class LongInt

#endif
