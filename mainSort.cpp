#include "sort.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  Sorts s;
  string location = "";
  if(argc == 2)
  {
    location = argv[1];
  }
  s.readFile(location);
  //s.viewArray();
  s.run();
  return 0;
}
