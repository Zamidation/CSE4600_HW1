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
    
    //pid_t pid; // process ID
    int status;
    char *name = argv[1];
    int n;
    int counter;

    // Create an array of process IDs, all will be appended and include numbers
    pid_t pid[11];

    pid[0] = getpid();
    
    cout << "Part 1 is starting.\n";

    cout << "I am the Parent with process ID: " << pid[0] << endl;

    for(int i = 0; i < 10; i++) // create 9 children, 10 processes in total
    {
        n = fork(); // Parent will go to default, child will go to 0;
        switch (n)
        {
        case 0: // child process
            pid[i+1] = getpid();
            //cout << "\nI am a child with process ID: " << pid[i] << "and my parent ID is: " << pid[i-1] << endl;
            cout << "\nI am a child with process ID: " << getpid() << " and my Ancestors are: ";
            counter = i;
            while(counter != 0)
            {
                cout << pid[counter] << " , ";
                counter -= 1;
            }
            cout << pid[0] << endl;
            //cout << endl;
            break;
        default:    // Parent process
            //cout << "\nI am the Parent with process ID: " << pid[i] << endl;
            //pid[i] = getpid();
            wait(&status); //wait for child, Child finishes here
            break;
        }
        if(n != 0) // if a parent process, break from for loop
            //return 0;
            break;
    }
        
    return 0;
}