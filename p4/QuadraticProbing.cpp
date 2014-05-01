        #include "QuadraticProbing.h"
	#include "course.h"

        
      
        /**
         * Construct the hash table.
         */
        template <class HashedObj>
        QuadraticHashTable<HashedObj>::QuadraticHashTable( )
         
        {
          
        }

        /**
         * Insert item x into the hash table. If the item is
         * already present, then do nothing.
         */
        template <class HashedObj>
        void QuadraticHashTable<HashedObj>::insert( HashedObj & x )
        {
           
            int currentPos = findPos( x );
           
            array[ currentPos ] = x;

             
            
                
        }

        

        /**
         * Method that performs quadratic probing resolution.
         * Return the position where the search for x terminates.
         */
        template <class HashedObj>
        int QuadraticHashTable<HashedObj>::findPos(  HashedObj & x ) 
        {
/* 1*/      int collisionNum = 0;
/* 2*/      int currentPos = hash( x, 2003 );

		if(!((array[currentPos]) !=0))
			return currentPos;

		else{
/* 3*/      while(   (array[ currentPos ]) != 0 )
            {
			collisionNum++;
/* 4*/          currentPos= currentPos + (collisionNum)*(collisionNum); 
            }
/* 7*/      return currentPos;
		}
        }


      
        /**
         * Find item x in the hash table.
         * Return the matching item, or ITEM_NOT_FOUND, if not found.
         */
        template <class HashedObj>
       HashedObj & QuadraticHashTable<HashedObj>::find( HashedObj & x ) 
        {
           
 		int collisionNum = 0;
/* 2*/      int currentPos = hash( x, 2003 );

		if(array[currentPos] != x){
			

/* 3*/     	 while(  array[ currentPos ] != x )
            		{
			collisionNum++;
/* 4*/          currentPos= currentPos + (collisionNum)*(collisionNum); 
            		}
/* 7*/     
		}

			
            return  array[currentPos]; 
        }

       


      

	         template <class HashedObj>
        int QuadraticHashTable<HashedObj>::hash(  Course &key, int tableSize ) 
        {
          
            return key.crn % tableSize;
        }
