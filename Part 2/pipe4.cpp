//pipe4.cpp  (data producer)
//To run code
//g++ pipe4.cpp -o pipe4
//g++ pipe5.cpp -o pipe5
// ./pipe4 "write message here."
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int data_processed;
    int file_pipes[2];
    char userinput[100]; //uninitialized bc we'll be getting user input
    char buffer[BUFSIZ + 1];
    pid_t fork_result;

    strcpy(userinput, argv[1]); //copies the first argv[1] into userinput
    
    for(int i = 2; i < argc; i++) //for loop to grab the other argv[i] in order to be able to send a message
    {
        strcat(userinput, " ");   //to have a whitespace in between words
        strcat(userinput, argv[i]); //the idea for this loop came from the youtube video https://youtu.be/aP1ijjeZc24 
    }
    memset(buffer, '\0', sizeof(buffer));

    if (pipe(file_pipes) == 0) {   //creates pipe
        fork_result = fork();
        if (fork_result == (pid_t)-1) {  //fork fails
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }

        if (fork_result == 0) {    //child
            sprintf(buffer, "%d", file_pipes[0]);
            (void)execl("pipe5", "pipe5", buffer, (char *)0);
            exit(EXIT_FAILURE);
        }
        else {                     //parent
            data_processed = write(file_pipes[1], &userinput, strlen(userinput));
            printf("%d - Sending message with %d bytes: %s\n", getpid(), data_processed, buffer);
        }
    }
    exit(EXIT_SUCCESS);
}
