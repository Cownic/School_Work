#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void subSeq(char s[] , int n);
int main()
{
    char input[] = "ABC";
    
}

void subSeq(char s[] , int n)
{
    int i , j , k;
    int length;

    for (i = 0 ; i < n ; i++){
        for (j = 0 ; j < n ; j++){
            length = (j-i) + i;
            for (k = i ; k <= length ; k++){
                printf("%c" , s[k]);
            }
            printf("\n");
        }
    }
}