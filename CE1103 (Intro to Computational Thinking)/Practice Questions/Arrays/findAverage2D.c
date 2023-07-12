/*(findAverage2D) Write a C function that takes a 4x4 two-dimensional array of floating point numbers
matrix as a parameter. The function computes the average of the first three elements of each row of the
array and stores it at the last element of the row*/

#include <stdio.h>
void findAverage2D(float matrix[4][4]);
int main()
{
    float ar[4][4];
    int i , j;

    printf("Enter data: \n");
    for (i = 0 ; i < 4 ; i++){
        for (j = 0 ; j < 4 ; j++){
            scanf("%f" , &ar[i][j]);
        }
    }

    findAverage2D(ar);
    printf("findAverage2D(): \n");
    for (i = 0 ; i < 4 ; i++){
        for (j = 0 ; j < 4 ; j++){
            printf("% .2f " , ar[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void findAverage2D(float matrix[4][4])
{
    int i,j;
    float average;
    for (i = 0 ; i < 4 ; i++){
        average = 0;
        for (j = 0 ; j < 3 ; j++){
            average = average + matrix[i][j];
        }
        matrix[i][3] = average / 3;
    }
}