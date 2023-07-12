#include <stdio.h>
#include <pthread.h>

//Thread Function
void *threadFunc ( void * arg)
{
  char *str;
  int i = 0;
  str = (char*) arg;
  while ( i < 110 ){
    usleep(2);
    printf("thread is running : %s\n" , str);
    ++i;
  }
  return NULL;
}


int main(void)
{
  pthread_t T1;
  int i = 0;
  pthread_create(&T1, NULL, threadFunc , "foo");

  while (i<100){
    usleep(3);
    printf("main is running....\n");
    ++i;
  }
  printf("main waiting for thread to terminate.\n");
  pthread_join(T1 , NULL);

  return 0;
}
