/*(maxCharToFront) Write a C function that accepts a character string str as parameter, finds the largest
character from the string (based on ASCII value), and moves it to the beginning of the string. E.g., if the
string is "adecb", then the string will be "eadcb" after executing the function. The string will be
passed to the caller via call by reference. If more than one largest character is in the string, then the first
appearance of the largest character will be moved to the beginning of the string*/

#include <stdio.h>
#include <string.h>
void maxCharToFront(char *str);
int main()
{
    char str[80], *p;

    printf("Enter a string: \n");
    fgets(str, 80, stdin);
    if (p = strchr(str, '\n'))
        *p = '\0';
    printf("maxCharToFront(): ");
    maxCharToFront(str);
    puts(str);
    return 0;
}
void maxCharToFront(char *str)
{
    int mark;
    char str1[80];
    strcpy(str1 , str);
    //printf("%s" , str1);
    int i ;
    int j = 1;
    char maxChar = str[0];
    for (i = 0 ; str[i] != '\0' ; i++){
        if (str[i] > maxChar){
            maxChar = str[i];
        }
    }

    str[0] = maxChar;
    for (i = 0; str1[i] != '\0' ; i++){
        if (str1[i] != maxChar){
            str[j++] = str1[i];
        }
        else if (str1[i] == maxChar){
            mark++;
            if (mark > 1){
                str[j++] = str1[i];
            }
        }
    }
    str[j] = '\0';
}