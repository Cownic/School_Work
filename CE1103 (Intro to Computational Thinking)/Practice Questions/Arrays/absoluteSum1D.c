/*(absoluteSum1D) Write a C function that returns the sum of the absolute values of the elements of a
vector with the following prototype:

float absoluteSum1D(int size, float vector[]); , where size is the number of elements in the vector.*/

#include <stdio.h>
#include <math.h>
float absoluteSum1D(int size, float vector[]);
int main()
{
    float vector[10];
    int i, size;

    printf("Enter vector size: \n");
    scanf("%d", &size);

    printf("Enter %d data: \n", size);
    for (i = 0; i < size; i++)
        scanf("%f", &vector[i]);
    printf("absoluteSum1D(): %.2f", absoluteSum1D(size, vector));

    return 0;
}
float absoluteSum1D(int size, float vector[])
{
    int i;
    double total;
    for (i = 0 ; i < size ; i++){
        if (vector[i] > 0){
            total += vector[i];
        }
        else {
            total -= vector[i];
        }
    }
    return total;
}
