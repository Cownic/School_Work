#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int simpleScan(char *P , char *T , int m);
int main()
{
    int result;
    char *P = "JunWei"; //Pattern
    char *T = "dhncwnjwnjJunWeihnxhwj"; //Text

    int m = strlen(P); //length of pattern

    result = simpleScan(P , T , m);

    if (result == -1){
        printf("The pattern cannot be found in the text!");
    }
    else {
        printf("The pattern is found in the test starting from index %d " , result);
    }
    return 0;
}


int simpleScan(char *P , char *T , int m)
{
    int n = strlen(T); //length of text

    int i , j , k;
    /* i is the current guess of where P begins in T
       j is the index of the current character in T
       k is the index of the current character in P
    */
    j = k = 0;
    i = 0;

    while (k < n-m){
        if (P[k] != T[j]){
            j = ++i ; // shifting right by one position to find the new starting position of the pattern
            if (j > n-m){// if the value i start finding from is greater than the length of the pattern , return as pattern cannot fit into remaining space
                break;
            }
            k = 0; // restart finding for the pattern if there is a mismatch
        }
        else {
            j++;
            k++;
            if (k == m){ // if k equal m means the whole pattern is in the test already so can return
                return i; // return the position of the starting point
            }
        }
    }
    return -1; // cannot find pattern in the test provided
}