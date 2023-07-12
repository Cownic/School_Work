/*(sweepSpace) Write two versions of a C function that remove all the blank spaces in a string.
The first version sweepSpace1() will use array notation for processing the string, while the
other version sweepSpace2() will use pointer notation. */

#include <stdio.h>
#include <string.h>
char *sweepSpace1(char *str);
char *sweepSpace2(char *str);
int main()
{
    char str[80], str2[80], *p;
    printf("Enter the string: \n");
    fgets(str, 80, stdin);
    if (p = strchr(str, '\n'))
        *p = '\0';
    strcpy(str2, str);
    printf("sweepSpace1(): %s\n", sweepSpace1(str));
    printf("sweepSpace2(): %s\n", sweepSpace2(str2));
    return 0;
}

char *sweepSpace1(char *str)
{
    int i , j = 0;
    int len;
    len = strlen(str);
    for (i = 0 ; i < len ; i++){
        if (str[i] != ' '){ //if encountered a space , the new string position will not increase when the old string position will increase , then replace in place
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    return str;
}

char *sweepSpace2(char *str)
{
    int i, j = 0;
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (*(str + i) != ' ')
        {
            *(str + j) = *(str + i);
            j++;
        }
    }
    *(str + j) = '\0';
    return str;
}
