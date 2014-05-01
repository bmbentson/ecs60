//Brian Bentson Matt Sheehan
#ifndef dequeH
#define dequeH
#define SIZEX 25;
 #include "dsexceptions.h"
        #include <iostream>       // For NULL
        using namespace std;
#include "mynew.h"

template <class T>
class ListNode
            {public:
		
                T element[66];
		int capacity ;
                ListNode *next;
	      ListNode *prev;

	    ListNode(  ListNode *n = NULL,ListNode *p=NULL )
	     { prev =p;
		next = n;
			capacity=0;
			
			
			 }
            };


template <class T>
class Deque //using a single linklist
{
public:
  Deque(); // Create a deque with an initial size of s
  void push(T &X); // Insert item on the front end of the deque.
  T pop(); // Remove the front item from the deque and return it.
  void inject(T &X); // Insert item X on the rear end of the deque.
  T eject(); // Remove the rear item from the deque and return it.
  T findKth(int pos); // Return item at the kth position from the front.
	~Deque(); // destructor
  private:
           
	
            ListNode<T> *tail;
	    ListNode<T> *head;



}; // class Deque

#include "deque.cpp"

#endif
