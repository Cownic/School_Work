/*(compress2D) Write a function that takes as input a square 2-dimensional array of binary data, 
compresses each row of the array by replacing each run of 0s or 1s with a single 0 or 1 and the number of 
times it occurs, and prints on each line the result of compression. For example, the row with data 
0011100011 may be compressed into 02130312*/

#include <stdio.h>
#define SIZE 100

void compress2D(int data[SIZE][SIZE] , int rowSize , int colSize);
int main()
{
    int data[SIZE][SIZE];
    int i,j;
    int rowSize, colSize;

    printf("Enter the array size(rowSize , colSize): \n");
    scanf("%d %d" , &rowSize , &colSize);
    printf("Enter the matrix (%dx%d): \n" , rowSize , colSize);
    for (i = 0 ; i < rowSize ; i++){
        for (j = 0 ; j < colSize ; j++){
            scanf("%d" , &data[i][j]);
        }
    }
    printf("compress2D(): \n");
    compress2D(data , rowSize , colSize);
    return 0;
}

void compress2D(int data[SIZE][SIZE] , int rowSize , int colSize)
{
    int i , j;
    int count ;
    int number;
    for (i = 0 ; i < rowSize ; i++){
        count = 1;
        number = data[i][0];
        for (j = 1 ; j < colSize ; j++){
            if (data[i][j] == number){
                count++;
            }
            else {
                printf("%d %d " , number , count);
                number = data[i][j];
                count = 1;
            }
        }
       
        printf("%d %d" , number , count);
    
        printf("\n");
    }
}