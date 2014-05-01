// Author: Sean Davis
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>
#include "deque.h"
#include "CPUTimer.h"
#include "mynew.h"
using namespace std;

CPUTimer ct;
extern int currentRAM;

int main(int argc, char* argv[])
// argv[1] is data filename
// argv[2]: '0' = just time and time, '1' = show bad operations,  space and time

{
  char command, *ptr;
  int value, value2, pos;
  bool show = argv[2][0] == '1';
  struct stat fileStat; 
  int err = stat( argv[1], &fileStat ); 
  char *buffer = new char[fileStat.st_size]; 
  ifstream inf(argv[1]);
  inf.read(buffer, fileStat.st_size);
  inf.close();
  currentRAM = 0; 
  ct.reset();
  Deque<int> DQ;

  ptr = buffer;

  while(ptr)
  {
    command = *ptr;
    value = atoi(++ptr);
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
        ptr = strchr(ptr, ' ');
        value2 = atoi(++ptr);
        if(value2 != DQ.findKth(value) && show)
          cout << "Bad findKth: " << value << endl;
        break;
    } // switch
    
    ptr = strchr(ptr, '\n');
    if(ptr)
      ptr++;
  } // while more in file


  cout << "CPU time: " << ct.cur_CPUTime() << " RAM: " << currentRAM << endl;
  return 0;
}
//---------------------------------------------------------------------------
