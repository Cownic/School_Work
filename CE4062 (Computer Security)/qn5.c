#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_authentication(char *pwd)
{
  int auth_flag = 0;
  char Password[] = "qwerty";
  char buffer[8];
  strcpy(buffer, pwd);
  if (strncmp(buffer, Password, 8) == 0){
    auth_flag = 1;
  }
  return auth_flag;
}

int main(int argc, char * argv[])
{
  if(check_authentication(argv[1]))
  {
    printf("Access Granted\n");
  }
  else
  {
    printf("Access Denied\n");
  }
  return 0;
}