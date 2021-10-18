//test_exec.cpp
#include <unistd.h>
#include <iostream>
 
using namespace std;
 
int main()
{
  //cout << "Running ps with execlp\n"; // ORIGINAL
  //execlp ("ps", "ps", "-ax", 0); 
  
  cout << "Running ps with execl\n"; // NEW*
  execl("ps", "ps", "-ax", 0);
 
  cout << "The program is exiting!\n";
  
  return 0;
}
