        #ifndef _QUADRATIC_PROBING_H_
        #define _QUADRATIC_PROBING_H_

  
        #include "mystring.h"
	#include "course.h"

        // QuadraticProbing Hash table class
        //
        // CONSTRUCTION: an initialization for ITEM_NOT_FOUND
        //               and an approximate initial size or default of 101
        //
        // ******************PUBLIC OPERATIONS*********************
        // void insert( x )       --> Insert x
       
        // Hashable find( x )     --> Return item that matches x
      
        // int hash(course ....)
        //                        --> Static method to hash courses

        template <class HashedObj>
        class QuadraticHashTable
        {
          public:
            explicit QuadraticHashTable( );

      

            HashedObj & find(  HashedObj & x ) ;

           
            void insert( HashedObj & x );
          
           
       
            HashedObj  array[2003];
          
            
            
            
           
            int findPos( HashedObj & x ) ;

            
	    int hash (Course &key, int tableSize) ;
         
        };

        #include "QuadraticProbing.cpp"
        #endif
