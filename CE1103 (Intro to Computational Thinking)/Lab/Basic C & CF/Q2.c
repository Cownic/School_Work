/*Write a C program that reads in several lines of non‐negative integer numbers,
computes the average for each line and prints out the average. The value –1 in each line
of user input is used to indicate the end of input for that line.*/

#include <stdio.h>

int main()
{
    int total = 0;
    int count = 0;
    int line;
    int input;
    int i;
    double average;

    printf("Enter the number of lines:\n");
    scanf("%d" , &line);

    for (i = 0 ; i < line ; i++){
        printf("Enter line %d:\n" , i+1);
        scanf("%d" , &input);
        while (input != -1){
            total = total + input;
            count++;
            scanf("%d" , &input);
        }
        average = total / count;
        printf("Average : %.2f\n" , average);
        count = 0;
        total = 0;
    }
   
    return 0;
}