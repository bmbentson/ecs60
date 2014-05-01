#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "StreetSelector.h"
#include "RunWire.h"
#include "CPUTimer.h"

using namespace std;

ostream& operator << (ostream &os, const Street &street)
{
  os << " (" << street.startCoordinates[NS] << ", " << street.startCoordinates[EW]
    << ") ("  << street.endCoordinates[NS] << ", " << street.endCoordinates[EW]
    << ") ";

    return os;
}

char** readFile(const char *filename, int *citySize)
{
  int i;
  ifstream inf(filename);
  inf >> *citySize;
  inf.ignore(100, '\n');
  char **grid = new char*[*citySize + 2];

  for(i = 0; i < *citySize; i++)
  {
    grid[i] = new char[*citySize];
    inf.getline(grid[i], *citySize + 2);
  } // for i

  inf.close();
  return grid;
} // readFile()


int dfs(Street17 **grid2, int ns, int ew, int citySize, int length)
{
  if(grid2[ns][ew].visited)
    return length;

  grid2[ns][ew].visited = true;
  length++;

  if(grid2[ns][ew].adj[NORTH])
    length = dfs(grid2, ns - 1, ew, citySize, length);

  if(grid2[ns][ew].adj[SOUTH])
    length = dfs(grid2, ns + 1, ew, citySize, length);

  if(grid2[ns][ew].adj[WEST])
    length = dfs(grid2, ns, ew - 1, citySize, length);

  if(grid2[ns][ew].adj[EAST])
    length = dfs(grid2, ns, ew + 1, citySize, length);

  return length;
} // dfs()

int checkStreets(char**grid, int citySize, Street *streets, int numStreets)
{
  int length = 0, start, end, temp, length2 = 1;
  Street17 **grid2 = new Street17*[citySize];
  char **grid3 = new char*[citySize];
  for (int i = 0; i < citySize; i++)
  {
    grid2[i] = new Street17[citySize];
    grid3[i] = new char[citySize + 3];
  } // for i


  for (int i = 0; i < numStreets; i++)
  {
    if(streets[i].startCoordinates[NS] < 0
      || streets[i].startCoordinates[EW] < 0
      || streets[i].startCoordinates[NS] >= citySize
      || streets[i].startCoordinates[EW] >= citySize
      || streets[i].endCoordinates[NS] < 0
      || streets[i].endCoordinates[EW] < 0
      || streets[i].endCoordinates[NS] >= citySize
      || streets[i].endCoordinates[EW] >= citySize)
    {
      cout << "Invalid coordinates at street #" << i << ' ' << streets[i] << endl;
      return 0;
    } // if invalid coordinates

    if (streets[i].startCoordinates[NS] == streets[i].endCoordinates[NS])
    {
      start = streets[i].startCoordinates[EW];
      end = streets[i].endCoordinates[EW];
      if(start > end)
      {
        temp = end;
        end = start;
        start = temp;
      } // if start > end then swap

      length2 += end - start;

      for(int j = start; j <= end; j++)
      {
        grid2[streets[i].startCoordinates[NS]][j].visited = false;
        if(j < end)
          grid2[streets[i].startCoordinates[NS]][j].adj[EAST] = true;
        if(j > start)
          grid2[streets[i].startCoordinates[NS]][j].adj[WEST] = true;
        if(grid[streets[i].startCoordinates[NS]][j] == '+')
          grid[streets[i].startCoordinates[NS]][j] = '*';
        else
          if(grid[streets[i].startCoordinates[NS]][j] == ' ')
            cout << "Trying to use " << streets[i].startCoordinates[NS]
                << ", " << j << " which is not a street\n";
          else
            if(grid[streets[i].startCoordinates[NS]][j] == '|')
              cout << "Trying to use " << streets[i].startCoordinates[NS]
                << ", " << j << " from " << streets[i].startCoordinates[NS]
                << ", " << j - 1 << " but " << streets[i].startCoordinates[NS]
                << ", " << j << " is not an east to west street\n";
          else
            grid[streets[i].startCoordinates[NS]][j] = 'x';
      } // for j
    } // if same NS coordinates
    else
      if(streets[i].startCoordinates[EW] == streets[i].endCoordinates[EW])
      {
        start = streets[i].startCoordinates[NS];
        end = streets[i].endCoordinates[NS];
        if(start > end)
        {
          temp = end;
          end = start;
          start = temp;
        } // if start > end then swap

        length2 += end - start;

        for(int j = start; j <= end; j++)
        {
          grid2[j][streets[i].startCoordinates[EW]].visited = false;
          if(j < end)
            grid2[j][streets[i].startCoordinates[EW]].adj[SOUTH] = true;
          if(j > start)
            grid2[j][streets[i].startCoordinates[EW]].adj[NORTH] = true;

          if(grid[j][streets[i].startCoordinates[EW]] == '+')
            grid[j][streets[i].startCoordinates[EW]] = '*';
          else
            if(grid[j][streets[i].startCoordinates[EW]] == '-')
              cout << "Trying to use " << j << ", "
                << streets[i].startCoordinates[EW] << " from " << j - 1
                << ", " << streets[i].startCoordinates[EW] << " but "
                << j << ", " << streets[i].startCoordinates[EW] << " is not a north to south street\n";
            else
            if(grid[j][streets[i].startCoordinates[EW]] == ' ')
              cout << "Trying to use " << j << ", "
                << streets[i].startCoordinates[EW] << " which is not a street\n";
            else
              grid[j][streets[i].startCoordinates[EW]] = 'x';
        } // for j
      } // if same EW coordinates
      else
      {
        cout << "Street #" << i << " is a diagonal\n";
      }
  } // for i

 length = dfs(grid2, streets[0].startCoordinates[NS],
    streets[0].startCoordinates[EW], citySize, 0);
  for(int i = 0; i < citySize; i++)
    for(int j = 0; j < citySize; j++)
    {
      if(!grid2[i][j].visited)
        cout << "Unconnected street at " << i << ", " << j << endl;

      if(grid[i][j] == '+')
        cout << "Unconnected intersection at " << i << ", " << j << endl;
    } // for j

  return length;
} // checkStreets()

int main(int argc, char* argv[])
{
  char **grid;
  StreetSelector *streetSelector;
  int citySize, numStreets, length = 0;
  CPUTimer ct;

  if(argc != 2)
  {
    cout << "usage: RunWire.out CityFilename\n";
    return 1;
  }

  grid = readFile(argv[1], &citySize);
  Street *streets = new Street[citySize * citySize];
  ct.reset();
  streetSelector = new StreetSelector((const char**)grid, citySize, streets, &numStreets);
  double CPUTime = ct.cur_CPUTime();
  delete streetSelector;
  length = checkStreets(grid, citySize, streets, numStreets);
  cout << "CPU Time: " << CPUTime << " Length: " << length << endl;
  return 0;
}

