/*Write a C function that takes in two parameters str and substr, and counts the
number of substring substr occurred in the character string str. If the substr is not contained in
str, then it will return 0. Please note that you do not need to consider test cases such as str =
"aooob" and substr = "oo".*/

#include <stdio.h>
#include <string.h>
#define INIT_VALUE -1
int countSubstring(char str[], char substr[]);
int main()
{
    char str[80], substr[80], *p;
    int result = INIT_VALUE;

    printf("Enter the string: \n");
    fgets(str, 80, stdin);
    if (p = strchr(str, '\n'))
        *p = '\0';
    printf("Enter the substring: \n");
    fgets(substr, 80, stdin);
    if (p = strchr(substr, '\n'))
        *p = '\0';
    result = countSubstring(str, substr);
    printf("countSubstring(): %d\n", result);
    return 0;
}
int countSubstring(char str[], char substr[])
{
    int count;
    char *p = str;
    while ((p = strstr(p , substr)) != NULL){
        count++;
        *p++;
    }
    return count;
}