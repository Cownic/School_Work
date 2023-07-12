/*(longWordLength) Write a C function that accepts an English sentence as parameter, and returns the
length of the longest word in the sentence. For example, if the sentence is "I am happy.", then the
length of the longest word "happy" in the sentence 5 will be returned. Assume that each word is a
sequence of English letters.*/

#include <stdio.h>
#include <string.h>
int longWordLength(char *s);
int main()
{
    char str[80], *p;
    printf("Enter a string: \n");
    fgets(str, 80, stdin);
    if (p = strchr(str, '\n'))
        *p = '\0';
    printf("longWordLength(): %d\n", longWordLength(str));
    return 0;
}
int longWordLength(char *s)
{
    int count = 0;
    int longest = 0;
    int i =0;

    while (s[i] != '\0'){
        if (s[i] != ' '){
            count++;
        }
        else {
            if (longest < count){
                longest = count;
            }
            count = 0;
        }
        i++;
    }
    if (longest < count){
        longest = count;
    }
    return longest;
}