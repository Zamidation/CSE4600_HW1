//test_wait.cpp
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
 
using namespace std;
 
int main()
{
  pid_t pid;        //process id
  char *message;
  int n;
  int exit_code;
  int status;

  pid_t grandchild[3];

  grandchild[0] = getpid();

  cout << "fork program starting\n";
  
  for(int j = 0; j < 2; j++) // do it twice
  {
    pid = fork();
    switch (pid) {
    case -1:
      cout << "Fork failure!\n";
      return 1;
    case 0: //children
      grandchild[j+1] = getpid();
      if (j == 0){
        message = "This is the child\n";
        }
      else
        message = "This is the grandchild with ID: ";
      n = 5;
      exit_code = 9;
      break;
    default:
      message = "This is the parent\n";
      n = 3;
      exit_code = 0;
      break;
    }

    //if(getpid() != grandchild[3]);
    //  wait(&status); //wait for child, Child finishes here

    for (int i = 0; i < n; ++i) {
      
      if(j == 1 && n == 5) // grandchild
      {
        cout << message << grandchild[2] << " and my Ancestors are: " << grandchild[1] << " , " << grandchild[0] << endl;
      }
      else {
        cout << message;}
      sleep (1);
    }
    if(pid != 0) // release the parents 
      break;
  }
  //waiting for child to finish
  if (pid != 0) {        //parent 
    int stat_val;
    pid_t child_pid;
 
    child_pid = wait (&stat_val);    //wait for child
    cout << "Child finished: PID = " << child_pid << endl;
    if (WIFEXITED (stat_val))
     cout << "child exited with code " << WEXITSTATUS (stat_val) << endl;
    else
    cout << "child terminated abnormally!" << endl;
  }
  exit (exit_code); 
}
