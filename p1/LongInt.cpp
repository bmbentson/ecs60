//Brian Bentson
#include "LongInt.h"
#include <iostream>
#include <cstdlib>
#include "StackLi.h"
using namespace std;

LongInt::LongInt()
{
   carry =0;
   
   stck.makeEmpty();
   tmp.makeEmpty(); 
} // LongInt()




const LongInt LongInt::operator+(LongInt &rhs)
{
  int temp;
  while(! ((rhs.stck).isEmpty()) && ! (stck.isEmpty())){
    temp= ((rhs.stck).topAndPop() + stck.topAndPop()) +carry;
    tmp.push(temp%10);
    carry= temp/10;

  }

  if(!((rhs.stck).isEmpty()))
    tmp.push((rhs.stck).topAndPop());

  if(!stck.isEmpty())
    tmp.push(stck.topAndPop());

  while(!tmp.isEmpty()){
    stck.push(tmp.topAndPop());
  }

  return *this;
}

 LongInt  LongInt::operator=(LongInt const &rhs) 
{
  
    stck= rhs.stck;
 return *this;
}

  ostream&  operator<<(ostream &out,  LongInt &rhs){
    while(!(rhs.stck).isEmpty()){
      (rhs.tmp).push ( (rhs.stck).topAndPop());
  }

    while(! (rhs.tmp).isEmpty()){
      out << (rhs.tmp).topAndPop();
          
  }
 return out;
} 


 istream&  operator>>(istream &in,  LongInt &rhs){
   char c=0;
   in.get(c);
        if(isdigit(c))
	  (rhs.stck).push(c-48);
    while(c != '\n'){
       in.get(c);
           if(isdigit(c)){
	     (rhs.stck).push(c-48);
             }

    }

    return in;
}



