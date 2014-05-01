// Author: Sean Davis
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "deque.h"
#include "CPUTimer.h"
#include "mynew.h"
using namespace std;

CPUTimer ct;
extern int currentRAM;

int main(int argc, char* argv[])
// argv[1] is data filename
// argv[2]: '0' = just time and space, '1' = show bad operations,  space and time

{
  char command;
  int value, value2;
  bool show = argv[2][0] == '1';
  ct.reset();
  Deque <int> DQ;
  ifstream inf(argv[1]);

  while(inf >> command)
  {
    inf >> value;
    switch(command)
    {
      case 'u' : DQ.push(value); break;
      case 'o' :
        if(value != DQ.pop() && show)
          cout << "Bad pop: " << value << endl;
        break;
      case 'i' : DQ.inject(value); break;
      case 'e' :
        if(value != DQ.eject() && show)
          cout << "Bad eject: " << value << endl;
        break;
      case 'f' :
        inf >> value2;
        if(value2 != DQ.findKth(value) && show)
          cout << "Bad findKth: " << value << endl;
        break;
    } // switch
  } // while more in file


  cout << "CPU time: " << ct.cur_CPUTime() << " RAM: " << currentRAM << endl;
  return 0;
}
//---------------------------------------------------------------------------
