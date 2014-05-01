// Brian Bentson
#ifndef STREETSELECTOR_H
#define STREETSELECTOR_H

#include "RunWire.h"
#include "math.h"
#include "BinaryHeap.h"



class Pvertex{
public:



int adjvertexnum;
int dist ;





	Pvertex(int adj=0,int distance=0){
		adjvertexnum =adj;
		dist =distance;
		
		

	}

	Pvertex( const Pvertex &rhs){
		adjvertexnum = rhs.adjvertexnum;
		dist = rhs.dist;
		

	}

	bool operator!=(const Pvertex &rhs){
		

	
		if (adjvertexnum == rhs.adjvertexnum)
			return true;
		


		
		else {return false;}

		}

	 bool operator<( Pvertex &rhs){
			
		return dist < rhs.dist;

		}

};






class StreetSelector
{
int layout[3000][3000]; // grid layout of the vertices where each number corresponds to the position in the adj matrix
BinaryHeap<Pvertex> prim;
public:
  StreetSelector(const char**grid, int citySize, Street *streets,
    int *numStreets);

	 void runner(const char**grid, int citySize, Street *streets,
    int *numStreets);
    // fills streets and sets numStreets to the number of entries
}; // StreetSelector class

#endif
