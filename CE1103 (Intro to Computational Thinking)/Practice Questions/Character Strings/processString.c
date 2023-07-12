/*(processString) Write a C function that accepts a string str and returns the total number of vowels
totVowels and digits totDigits in that string to the caller via call by reference*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void processString(char *str, int *totVowels, int *totDigits);
int isVowel(char ch);
int main()
{
    char str[50], *p;
    int totVowels, totDigits;
    printf("Enter the string: \n");
    fgets(str, 80, stdin);
    if (p = strchr(str, '\n'))
        *p = '\0';
    processString(str, &totVowels, &totDigits);
    printf("Total vowels = %d\n", totVowels);
    printf("Total digits = %d\n", totDigits);
    return 0;
}
void processString(char *str, int *totVowels, int *totDigits)
{
    int i;
    *totDigits = 0;
    *totVowels = 0;
    for (i = 0 ; str[i] != '\0' ; i++){
        if (isVowel(str[i])){
            (*totVowels)++;
        }
        else if (isdigit(str[i])){
            (*totDigits)++;
        }
    }
}

int isVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            return 1;
        }
        else {
            return 0;
        }
}