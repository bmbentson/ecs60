#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

enum {NORTH, EAST, SOUTH, WEST};

bool isEmptyIntersection(char **grid, int ns, int ew, int citySize)
{
  return ns >= 0 && ew >= 0 && ew < citySize && ns < citySize
    && grid[ns][ew] != ' '
    && ((ew > 0 && grid[ns][ew - 1] == ' ')
    || (ew < citySize - 1 && grid[ns][ew + 1] == ' ')
    || (ns > 0 && grid[ns - 1][ew] == ' ')
    || (ns < citySize - 1 && grid[ns + 1][ew] == ' '));
}

void addStreet(char **grid, int citySize)
{
  int start, end, ns, ew, startNS, startEW;
  bool foundEmptyIntersection = false;

  startNS = rand() % citySize;
  startEW = rand() % citySize;

  for(int i = 1; !foundEmptyIntersection; i++)
  {
    for(int j = 0; !foundEmptyIntersection && j < i * 8; j++)
    {
      switch(rand() % 4)
      {
        case NORTH:
          ns = startNS - i;
          ew = startEW + rand() % (i * 2) - i;
          foundEmptyIntersection = isEmptyIntersection(grid, ns, ew, citySize);
        break;
        case WEST:
          ns = startNS + rand() % (i * 2) - i;
          ew = startEW - i;
          foundEmptyIntersection = isEmptyIntersection(grid, ns, ew, citySize);
          break;
        case SOUTH:
          ns = startNS + i;
          ew = startEW + rand() % (i * 2) - i;
          foundEmptyIntersection = isEmptyIntersection(grid, ns, ew, citySize);
          break;
        case EAST:
          ns = startNS + rand() % (i * 2) - i;
          ew = startEW + i;
          foundEmptyIntersection = isEmptyIntersection(grid, ns, ew, citySize);
          break;
      } // switch
    } // for j
  } // for i and empty intersection not found

  while(true)
  {
    int direction = rand() % 2;
    if(direction == EAST
      && ((ew > 0 && grid[ns][ew - 1] == ' ')
      || (ew < citySize - 1 && grid[ns][ew + 1] == ' ')))
    {
      start = ew - rand() % 10 - 2;
      end = ew + rand() % 10 + 2;

      if(start < 0)
        start = 0;
      if(end > citySize - 1)
        end = citySize - 1;

      for(ew = start; ew <= end; ew++)
        if(grid[ns][ew] == ' ')
          grid[ns][ew] = '-';
        else
          if(grid[ns][ew] == '|')
            grid[ns][ew] = '+';

      return;
    } // if East to West street and an empty grid available
    else // try north to south street
      if ((ns > 0 && grid[ns - 1][ew] == ' ')
        || (ns < citySize - 1 && grid[ns + 1][ew ] == ' '))
      {
        start = ns - rand() % 10 - 2;
        end = ns + rand() % 10 + 2;

        if(start < 0)
          start = 0;
        if(end > citySize - 1)
          end = citySize - 1;

        for(ns = start; ns <= end; ns++)
          if(grid[ns][ew] == ' ')
            grid[ns][ew] = '|';
          else
            if(grid[ns][ew] == '-')
              grid[ns][ew] = '+';

        return;
      } // if north south street and an empty grid available
  } // while true
} // addStreet


void fillGrid(int streetCount, char **grid, int citySize)
{
  int start, end;

  start = citySize / 2 - rand() % 10 - 2;
  end = citySize / 2 + rand() % 10 + 2;

  for(int i = start; i <= end; i++)
  {
    grid[i][citySize / 2] = '|';
    grid[citySize / 2][i] = '-';
  } // for i
  
  grid[citySize / 2][citySize / 2] = '+'; // guarantee intersection at 
  // (citySize / 2, citySize / 2)


  for(int i = 1; i < streetCount; i++)
    addStreet(grid, citySize);
} // fillGrid()

void writeBlocks(char **grid, ofstream &outf, int citySize)
{
  int i, j;

  for(i = 0; i < citySize; i++)
  {
    for(j = 0; j < citySize; j++)
      outf << grid[i][j];

    outf << endl;
  }  // for i
}  // writeBlocks()


int main(int argc, char* argv[])
{
  int seed, streetCount, citySize;
  char **grid;

  char filename[80]; //, streetNames[550][25];
  cout << "City size: ";
  cin >> citySize;
  cout << "Number of streets: ";
  cin >> streetCount;
  cout << "Seed: ";
  cin >> seed;
  srand(seed);
  sprintf(filename, "City-%d-%d-%d.txt", citySize, streetCount, seed);

  grid = new char*[citySize];
  for(int i = 0; i < citySize; i++)
  {
    grid[i] = new char[citySize];
    for(int j= 0; j < citySize; j++)
      grid[i][j] = ' ';
  } // for i

  fillGrid(streetCount, grid, citySize);
  ofstream outf(filename);
  outf << citySize << endl;
  writeBlocks(grid, outf, citySize);

  for(int i = 0; i < citySize; i++)
    delete [] grid[i];

  delete [] grid;
  return 0;
} // main()

