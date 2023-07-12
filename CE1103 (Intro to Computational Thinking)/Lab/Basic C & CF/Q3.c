/*Write a C program that accepts a positive number height between 1 and 10 as its
parameter value, and prints a triangular pattern according to height. Note that only 1, 2
and 3 are used to generate the patterns.*/

#include <stdio.h>

int main()
{
    int i , j;
    int print;
    int height;
    printf("Enter the height:\n");
    scanf("%d" , &height);

    for (i = 1 ; i <= height ; i++){
        for (j = 1 ; j <= i ; j++){
            print = i % 3;
            if (print == 0){
                printf("%d" , 3);
            }
            else {
                printf("%d" , print);
            }
        }
        printf("\n");
    }
    return 0;
}