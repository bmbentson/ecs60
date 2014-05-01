// Author: Sean Davis
#include <iostream>
#include <fstream>
#include "cities.h"
using namespace std;

int main()
{
  char command = 'n', CityName[80], LatDirection, LongDirection;
  int latitude, longitude, range;

  Cities cities;
  ifstream inf("cities.csv");
  inf >> cities;

  while(command != 'q')
  {
    cout << "\nPlease enter your request (area = a, location = l, name = n, ";
    cout << "quit = q) >> ";
    cin >> command;
    cin.getline(CityName, 80);  // eats up '\n'

    switch (command)
    {
      case 'a':
        cout << "Name >> ";
        cin.getline(CityName, 80);
        cout << "Range (in miles) >> ";
        cin >> range;
        cities.ShowArea(CityName, range);
        break;
      case 'l':
        cout << "Latitude (0 - 180) and direction (N, S)  >>  ";
        cin >> latitude >> LatDirection;
        cout << "Longitude (0 - 180) and direction (W, E) >> " ;
        cin >> longitude >> LongDirection;
        cities.ShowLocation(latitude, LatDirection, longitude, LongDirection);
        break;
      case 'n':
        cout << "Name >> ";
        cin.getline(CityName, 80);
        cities.ShowName(CityName);
        break;
    } // switch (command)

  } // while command is not q

  return 0;
}

