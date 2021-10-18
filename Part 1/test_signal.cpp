//test_signal.cpp
#include <signal.h>
#include <unistd.h>
#include <iostream>
 
using namespace std;

// MODIFIED FOR PART 2

void func (int sig)
{
  cout << "Oops! -- I got a signal " << sig << endl;
}
 
int main()
{

    //(void) signal (SIGINT, func);    //catch terminal interrupts
  
    struct sigaction new_action, old_action ; // create two different sigaction structures
    new_action.sa_handler = func;   // assign action on new_action as func
    sigemptyset(&new_action.sa_mask);   // Block Segterm signal
    sigaddset(&new_action.sa_mask, SIGTERM); // while handler runs, ignore SIGTERM
    new_action.sa_flags = 0;    // remove all flags

    sigaction(SIGINT, NULL, &old_action); //read old signal associated to SIGINT

    if (old_action.sa_handler != SIG_IGN) //if handler wasn't SIG_IGN
    {
        sigaction(SIGINT, &new_action, NULL); //replace signal
    }
    
    //for (int i = 0; i < 20; ++i) {
    while(1){
        cout << "CSUSB CSE 4600 Operating Systems. Homework on signals" << endl;
        sleep (1); 
    }
    return 0;
}
