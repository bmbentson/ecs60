	//Brian Bentson        

	#ifndef _BINARY_HEAP_H_
        #define _BINARY_HEAP_H_

        
      

        // BinaryHeap class
        //
        // CONSTRUCTION: with a negative infinity sentinel and
        //               optional capacity (that defaults to 100)
        //
        // ******************PUBLIC OPERATIONS*********************
        // void insert( x )       --> Insert x
        // deleteMin( minItem )   --> Remove (and optionally return) smallest item
        // Comparable findMin( )  --> Return smallest item
        // bool isEmpty( )        --> Return true if empty; else false
        // bool isFull( )         --> Return true if full; else false
        // void makeEmpty( )      --> Remove all items
        // ******************ERRORS********************************
        // Throws Underflow and Overflow as warranted

        template <class Comparable>
        class BinaryHeap
        {
          public:
            explicit BinaryHeap( );

            bool isEmpty( ) const;
            bool isFull( ) const;
            const Comparable & findMin( ) const;

            void insert(  Comparable & x );
            void deleteMin( );
            void deleteMin( Comparable & minItem );
            void makeEmpty( );

          private:
            int                currentSize;  // Number of elements in heap
          Comparable  array[400000];        // The heap array

            void buildHeap( );
            void percolateDown( int hole );
        };

        #include "BinaryHeap.cpp"
        #endif
