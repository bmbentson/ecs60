//Brian Bentson Matt Sheehan
#include "deque.h";




template <class T>
Deque < T >::Deque()
{
  tail = NULL;
  head= NULL;//head
  
    
    head = new ListNode(head,tail);
    
  
}; // Deque()


template <class T>
void Deque <T>::push(T & X)
{
  ListNode *oldhead = *head;


	if((head->capacity ==SIZEX){
	
		
		
	head = new ListNode( NULL, head );
	oldhead->next = *head;
		head->element[SIZEX -1] = X;
			(head->capacity)++;
	 }
	else{
	for(int i=SIZEX-1; i>-1;i --){
	if(head->element[i]== NULL){
		head->element[i] = X;
		(head->capacity)++;
		break;
		}

	}
  
	}  
	
} // push()


template <class T>
T Deque <T>::pop()
{
 T temp; 
 if( isEmpty( ) )
                throw new Underflow( );
				int i=SIZEX-1;
			while(head->element[i] != NULL)
				i--;

				
					if(i ==SIZEX -2){
						ListNode *oldhead = head;
						temp = head->element[i+1];
						head = head->prev;
            					head->next= NULL;
	   					 
           					 delete oldhead;
							(head->capacity)--;

						}


				else{

					temp = head->element[i+1];
					head->element[i+1] =NULL;
						(head->capacity)--;
				}	

return temp;
} // pop()


template <class T>
void Deque <T>::inject(T &X)
{
ListNode *oldtail = *tail;


	if(tail->capacity == SIZEX-1 ){
	
		
	tail = new ListNode(tail, NULL );
	oldtail->prev = *tail;
		tail->element[0] = X;
			(tail->capacity)++;

	 }
	else{
	for(int i=0; i<SIZEX;i++){
	if(tail->element[i]== NULL){
		tail->element[i] = X;
			(tail->capacity)++;
		break;
		}

	}
  
	}


}

template <class T>
T Deque <T>::eject()
{
 T temp; 
 if( isEmpty( ) )
                throw new Underflow( );
				int i=0;
			while(tail->element[i] != NULL)
				i++;

				
					if(i == 1){
						ListNode *oldtail = tail;
						temp = tail->element[i-1];
						
						tail = tail->next;
            					tail->prev= NULL;
	   					 
           					 delete oldtail;
						(tail->capacity)--;

						}


				else{

					temp = tail->element[i-1];
					tail->element[i-1] =NULL;
						(tail->capacity)--;
	
				
            
				}	

return temp;
}// eject()

template <class T>
T Deque <T>::findKth(int pos)
{
  int count = pos;

  ListNode *item;
	T ele;
int i=SIZEX;
	while(head->element[i] != NULL)
		i--;
 i= SIZEX-i;

	if(pos> i){
		count = count -i;
			item= head->next;
		for(j= count/SIZEX;j>0 ;j--;)
			item= item->next;
			
		ele = item->element[(count%SIZEX)-1];
			 

	}

	else{
	ele= head->element[SIZEX-i+pos];
	}


return ele;
} // findKth()

 Deque < T >::~Deque(){
Delete head;
};
