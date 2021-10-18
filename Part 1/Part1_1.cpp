#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

//Create 10 processes with 1 parent and each child
// P -> C1 -> C2 -> ... -> C9
// Practice with only 2, Parent and Child 1

using namespace std;

int main(int artgc, char *argv[])
{
    pid_t pid; // process ID
    int status;
    char *name = argv[1];
    int n;
    int exit_code;

    cout << "Part 1 is starting.\n";

    for(int i = 0; i < 10; i++) // create 9 children, 10 processes in total
    {
        pid = fork(); // Parent will go to default, child will go to 0; hopefully not create 2^10 processes
        switch (pid)
        {
        case 0: // child process
            cout << "I am a child with process ID %d\n: "
            break;
    
        default:
            break;
        }
    }
    
}

/*
int main(int argc, char *argv[]){
    int status;
    char *name = argv[1];
    // create new process using fork. The call to fork in the parent 
    // return the PID of the new child process
    pid_t pid;
    //int pid;
    for(int i = 0; i < 2; i++)
    {
        pid = fork(); // ONLY WORKS WITH 1 PROCESS, need a way to define more processes
    }
    if(pid == 0)
    {
        // Child process continues to execute, exception that 
        // child process the call to the fork remains 0
        printf("Child of %s is %d\n", name, pid);
        //execlp("/bin/ls", "ls", NULL); // Run exec command for the child to display the content of the current directory
        return 0;
    }

    else
    {
        printf("I am the parent, my child is %d\n", pid);
        wait(&status); //wait for child, Child finishes here
        printf("Exit status: %d\n", WEXITSTATUS(status)); // print the exit status of the child
    }

    return 0;
}
*/