#include <pthread.h>
#include <stdio.h>

using namespace std;

//The thread for first one
void *run_thread1( void *data)
{
   printf("My thread identifier is Thread 1\n");

   pthread_exit ( 0 );

}

//The thread for second one
void *run_thread2( void *data)
{

   printf("My thread identifier is Thread 2\n");

   pthread_exit ( 0 );
}

//The thread for third one
void *run_thread3( void *data)
{
  
   printf("My thread identifier is Thread 3\n");

   pthread_exit ( 0 );
}

int main()
{
   pthread_t id1, id2, id3;    //thread identifiers 
   pthread_attr_t attr1, attr2, attr3; //set of thread attributes

   pthread_attr_init ( &attr1 );
   pthread_attr_init ( &attr2 );
   pthread_attr_init ( &attr3 ); //new thread

   void *data;   //pointer to give as parameter to function

   //create the threads
   pthread_create ( &id1, &attr1, run_thread1 , data );
   pthread_create ( &id2, &attr2, run_thread2 , data );
   pthread_create ( &id3, &attr3, run_thread3 , data ); //new thread

   //wait for the threads to exit
   pthread_join( id1, NULL );
   pthread_join( id2, NULL );
   pthread_join( id3, NULL ); //new thread

   return 0;

}
