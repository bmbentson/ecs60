#ifndef RUNWIRE_H
  #define RUNWIRE_H

#include <iostream>
using namespace std;

enum {NORTH, EAST, SOUTH, WEST};
enum {NS, EW};

class Street
{
public:
  short startCoordinates[2]; // NS first, EW second
  short endCoordinates[2];  // NS first, EW second
  friend ostream& operator << (ostream &os, const Street &street);
}; // Street class

class Street17
{
public:
  bool visited;
  bool adj[4];
  Street17(): visited(true) {adj[0]= adj[1] = adj[2] = adj[3] = false;}
  
};

#endif
