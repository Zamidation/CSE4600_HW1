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
  
  strcpy(userIn, argv[1]); //copying first 
  for(int i = 2; i < argc; i++) 
    {
        strcat(userIn, " ");   //to have a whitespace in between words
        strcat(userIn, argv[i]); //the idea for this loop came from the youtube video https://youtu.be/aP1ijjeZc24 to be able to store possible multiple arguments [1], [2] etc
    }

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
