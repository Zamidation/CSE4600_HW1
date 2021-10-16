//pipe1a.cpp
//To execute code type in line 3 then line 4
// g++ -o pipe1a pipe1a.cpp
// ./pipe1a ls -1
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) //command line argument
{
  char userIn[100];//user input uninitialized
  
  strcpy(userIn, argv[1]); //getting the user input

  FILE *fpi;				//for reading a pipe
 
  char buffer[BUFSIZ+1];		//BUFSIZ defined in <stdio.h>
  
  int chars_read;
  memset (buffer, 0,sizeof(buffer));	//clear buffer
  fpi = popen (userIn, "r");	//pipe to the userInput command
  if (fpi != NULL) {
    //read data from pipe into buffer
    chars_read = fread(buffer, sizeof(char), BUFSIZ, fpi);  
    if (chars_read > 0) 
     cout << "Output from pipe: " << buffer << endl;
    pclose (fpi); 			//close the pipe
    return 0; 
  }

  return 1;
}
