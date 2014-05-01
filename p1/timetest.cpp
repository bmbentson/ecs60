       #include "QueueAr.h"
       #include "LinkedList.h"
       #include "StackAr.h"
       #include "StackLi.h"
       #include "vector.h"
       #include "SkipList.h"
       #include "CPUTimer.h"
       #include "dsexceptions.h"
       #include "CursorList2.h"
           #include <fstream>

#include <cstdlib>
      vector<CursorNode <int> > cursorSpace;





int getChoice(){
  int b=0;
cout << "\n";
cout << "ADT Menu" << endl;
cout << "0. Quit" << endl << "1. LinkedList"<< endl << "2. Cursor List" << endl << "3. StackAr "<< endl<< "4. StackLi" << endl << "5. QueueAr" << endl << "6. SkipList" << endl;
cout << "Your choice >> ";
 cin >> b;


 return b;


}



void RunList( const char   fil[]){
  List<int> lst;
  ListItr<int>  *itr;
  *itr =  lst.zeroth();

int temp;
  char next;
 ifstream fin;
  fin.open(fil);
  fin.get(next);
if(next  == 'i'){
  fin>>temp;
  lst.insert(temp, *itr);
  (*itr).advance();
 }
  while(! fin.eof()){
    fin.get(next);
    if(next  == 'i'){
      fin>>temp;
      // *itr =lst.find(temp);
      lst.insert(temp, *itr);




    }


    if(next == 'd'){
      fin>>temp;
	lst.remove(temp);
    }

  }

  }

 

void  RunCursorList(const char   fil[]){
  CursorListItr<int> *itr;

  CursorList<int> lst(cursorSpace);
 itr =  new CursorListItr<int>(lst);
  int temp;
  char next;
 ifstream fin;
  fin.open(fil);
  fin.get(next);
if(next  == 'i'){
  fin>>temp;
  lst.insert(temp, *itr);
  (*itr).advance();
 }
  while(! fin.eof()){
    fin.get(next);
    if(next  == 'i'){
      fin>>temp;
      // *itr =lst.find(temp);
      lst.insert(temp, *itr);




    }


    if(next == 'd'){
      fin>>temp;
	lst.remove(temp);
    }

  }

 }


 void RunStackAr(const char   fil[]){
   StackAr<int> stck(1000001);
 char next;
 ifstream fin;
 int temp;
  fin.open(fil);
  while(! fin.eof()){
    fin.get(next);
    if(next  == 'i'){
      fin>> temp;
      stck.push(temp);
	      }

 if(next  == 'd'){
   fin>>temp;
   stck.pop();
	      }


    
  }


 }


 void RunStackLi(const char   fil[]){

 StackLi<int> stck;
 char next;
 ifstream fin;
 int temp;
  fin.open(fil);
  while(! fin.eof()){
    fin.get(next);
    if(next  == 'i'){
      fin>> temp;
      stck.push(temp);
	      }

 if(next  == 'd'){
   fin>>temp;
   stck.pop();
	      }


    
  }



 }


 void RunQueueAr(const char   fil[]){
   Queue<int> stck(1000001);
 char next;
 ifstream fin;
 int temp;
  fin.open(fil);
  while(! fin.eof()){
    fin.get(next);
    if(next  == 'i'){
      fin>> temp;
      stck.enqueue(temp);
	      }

 if(next  == 'd'){
   fin>>temp;
   stck.dequeue();
	      }


    
  }

 }

void RunSkipList(const char   fil[]){


 
  SkipList<int> lst(1000001);
  SkipListNode<int>  *itr;

    int temp;
  char next;
 ifstream fin;
  fin.open(fil);
  fin.get(next);
if(next  == 'i'){
  fin>>temp;
  lst.insert(temp);
 
 }
  while(! fin.eof()){
    fin.get(next);
    if(next  == 'i'){
      fin>>temp;
      // *itr =lst.find(temp);
      lst.insert(temp);




    }


    if(next == 'd'){
      fin>>temp;
	lst.deleteNode(temp);
    }

  }

  }



int main()
{



 
CPUTimer ct;

 ifstream fin;


  char filename[10];
  int choice = 1;
  cout << "Filename >> ";
  cin >> filename;


 


do

{


     choice = getChoice();

     ct.reset();

     switch (choice)

     {

       case 1: RunList(filename); break;

       case 2: RunCursorList(filename); break;

       case 3: RunStackAr(filename); break;

       case 4: RunStackLi(filename); break;

       case 5: RunQueueAr(filename); break;

       case 6: RunSkipList(filename); break;

     }

 

     cout << "CPU time: " << ct.cur_CPUTime() << endl;

} while(choice > 0);


 return 0;
}










