// Brian Bentson
#include <iostream>
#include "StreetSelector.h"
#include "RunWire.h"

using namespace std;

StreetSelector::StreetSelector(const char **grid, int citySize, Street *streets,
  int *numStreets)
{

runner(grid, citySize,streets,numStreets);
};



 void StreetSelector::runner(const char **grid, int citySize, Street *streets,
  int *numStreets)
{

int adjmatrix[300000][9]; // t/f,north,south,east,west,dv,pv by adjmatrix,y,x



int adjcounter=0,adjcounter2 =0;


int xcoord=0;
int ycoord=0;
int adjaccessor;
int north, south, east, west;//used during prims to access the adjmatrix



// creating the vertexes and edge list
while(ycoord <(citySize )){

			
	if (grid[ycoord][xcoord] == '+'){

		layout[ycoord][xcoord] = adjcounter;//map of veretex location [y][x] to adjmatrix location[num]
			adjmatrix[adjcounter][0] = 0;//false has not been visted. whille get set to true during prims
			adjmatrix[adjcounter][7] = ycoord;	
			adjmatrix[adjcounter][8] = xcoord;
			adjmatrix[adjcounter][5] = 0;//previous distance


					//setting east coord for adj matrix
				int i=1;
					if(xcoord != citySize){
			while(grid[ycoord][xcoord+i] == '-'  ){
				i++;
				}
				if (grid[ycoord][xcoord+i] == '+' )
				adjmatrix[adjcounter][3] = i;
				else
				adjmatrix[adjcounter][3] = 0;
				}
					// setting west coord for adj matrix

					i=1;
					if(xcoord !=0){
			while(grid[ycoord][xcoord-i] == '-'){
				i++;
				}
				if (grid[ycoord][xcoord-i] == '+' )
				adjmatrix[adjcounter][4] = i;
				else
				adjmatrix[adjcounter][4] = 0;
				}


					//setting south coord for adj matrix
				 i=1;
				if(ycoord != citySize){
			while((ycoord+i) != citySize-1){
				if(grid[ycoord+i][xcoord] == '|'   )
				i++;
				
				else
						break;
				}
				
				if (grid[ycoord+i][xcoord] == '+' )
				adjmatrix[adjcounter][2] = i;
				else
				adjmatrix[adjcounter][2] = 0;
				}
				

					//setting north coord for adj matrix

					 i=1;
					if(ycoord != 0){
				while( (ycoord-i) != 0){
					if(grid[ycoord-i][xcoord] == '|' )
					i++;
					
					else
						break;
					
				
				}
				if (grid[ycoord-i][xcoord] =='+' )
				adjmatrix[adjcounter][1] = i;
				else
				adjmatrix[adjcounter][1] = 0;
				}
				
				

			adjcounter++;
			}
		

if(xcoord == citySize){
xcoord =0;
ycoord++;

}
else 
xcoord++;


}


//reads correctly
*numStreets = adjcounter ;
adjcounter2 = 0;






//Prims


Pvertex powerplant(layout[citySize/2][citySize/2],0);

prim.insert(powerplant);
adjmatrix[layout[citySize/2][citySize/2]][6] = layout[citySize/2][citySize/2];



while(!prim.isEmpty() ){

Pvertex temp(prim.findMin());





adjaccessor =temp.adjvertexnum;


if(adjmatrix[adjaccessor][0]==1)
prim.deleteMin();


else{

xcoord=adjmatrix[adjaccessor][8];
ycoord =adjmatrix[adjaccessor][7];

prim.deleteMin();
adjmatrix[adjaccessor][0] =1;
north=adjmatrix[adjaccessor][1];
south=adjmatrix[adjaccessor][2];
east=adjmatrix[adjaccessor][3];
west=adjmatrix[adjaccessor][4];

//north
if(north!=0 ){
if((adjmatrix[layout[ycoord-north][xcoord]][5] > north  || adjmatrix[layout[ycoord-north][xcoord]][5] ==0 ) && adjmatrix[layout[ycoord-north][xcoord]][0] ==0 ){ //did you find a smaller path if so make a new vertex throw it in there if the vertex is not marked true already
adjmatrix[layout[ycoord-north][xcoord]][5]= north;
adjmatrix[layout[ycoord-north][xcoord]][6]= adjaccessor;


Pvertex northvertex(layout[ycoord-north][xcoord],north);
prim.insert(northvertex);

}
}

//south
if(south!=0 ){
if((adjmatrix[layout[ycoord+south][xcoord]][5] > south  || adjmatrix[layout[ycoord+south][xcoord]][5]==0) && adjmatrix[layout[ycoord+south][xcoord]][0]==0 ){
adjmatrix[layout[ycoord+south][xcoord]][5]=south;
adjmatrix[layout[ycoord+south][xcoord]][6]= adjaccessor;


Pvertex southvertex(layout[ycoord+south][xcoord],south);
prim.insert(southvertex);

}
}


///east
if(east!=0 ){
if((adjmatrix[layout[ycoord][xcoord+east]][5]>east || adjmatrix[layout[ycoord][xcoord+east]][5] ==0) && adjmatrix[layout[ycoord][xcoord+east]][0] ==0 ){
adjmatrix[layout[ycoord][xcoord+east]][5]=east;
adjmatrix[layout[ycoord][xcoord+east]][6]= adjaccessor;



Pvertex eastvertex(layout[ycoord][xcoord+east],east);
prim.insert(eastvertex);

}
}


//west
if(west!=0 ){
if((adjmatrix[layout[ycoord][xcoord-west]][5] >west || adjmatrix[layout[ycoord][xcoord-west]][5]==0)  && adjmatrix[layout[ycoord][xcoord-west]][0]==0 ){
adjmatrix[layout[ycoord][xcoord-west]][5]=west;
adjmatrix[layout[ycoord][xcoord-west]][6]= adjaccessor;


Pvertex westvertex(layout[ycoord][xcoord-west],west);
prim.insert(westvertex);
}
}




 adjcounter2++;
}

}



//buidling streets;
int i=0;
while(i< adjcounter+2){




          
                        (streets[i]).startCoordinates[0] =(short)adjmatrix[(adjmatrix[i][6])][7];
			(streets[i]).startCoordinates[1] =(short)adjmatrix[(adjmatrix[i][6])][8];

			(streets[i]).endCoordinates[0] =(short)adjmatrix[i][7];
			(streets[i]).endCoordinates[1] =(short)adjmatrix[i][8];
		
		

  

i++;



}







} // StreetSelector()


