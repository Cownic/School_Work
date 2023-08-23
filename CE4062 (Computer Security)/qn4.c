#include <stdio.h>
#include <stdlib.h>

char CheckPassword()
{
  char good = 'N';
  char Password[2]; // Buffer overflow attack here
  printf("Address of Password[2] :%p\n", Password);
  printf("Address of good: %p\n", &good);
  gets(Password);
  return good;
}

int main(int argc, char* argv[])
{
  printf("Enter your password:");
  
  if(CheckPassword() == 'Y')
  {
    printf("Your random number is %d\n", rand()%100);
  }
  else{
    printf("You don't have the permission to get a random number");
    exit(-1);
  }
  return 0;
}