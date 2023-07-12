/*(swapMinMax1D) Write the C function swapMinMax1D() that takes in an array of integers ar
and size (>1) as parameters, finds the index positions of the largest number and smallest number in 
the array, swaps the index positions of these two numbers, and passes the array to the calling function 
via call by reference. For example, if ar is {1,2,3,4,5}, then the resultant array ar will be 
{5,2,3,4,1} after executing the function. If there are more than one largest or smallest number in 
the array, we will swap the last occurrence of the largest and smallest numbers. For example, if ar is 
{5,2,1,1,8,9,9}, then the resultant array ar will be {5,2,1,9,8,9,1} after executing the 
function*/

#include <stdio.h>
void swapMinMax1D(int ar[], int size);
int main()
{
    int ar[50], i, size;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i = 0; i < size; i++)
        scanf("%d", ar + i);
    swapMinMax1D(ar, size);
    printf("swapMinMax1D(): ");
    for (i = 0; i < size; i++)
        printf("%d ", *(ar + i));
    return 0;
}
void swapMinMax1D(int ar[], int size)
{
    int temp, i;
    int largestIndex, smallestIndex;
    int largest, smallest;
    largest = ar[0];
    smallest = ar[0];
    largestIndex = 0;
    smallestIndex = 0;

    for (i = 1; i < size; i++)
    {
        if (ar[i] > largest)
        {
            largestIndex = i;
            largest = ar[i];
        }
        else if (ar[i] < smallest)
        {
            smallestIndex = i;
            smallest = ar[i];
        }
        else if (ar[i] == smallest && ar[i] == largest)
        {
            smallestIndex = i;
            largestIndex = i;
        }
        else if (ar[i] == largest)
        {
            largestIndex = i;
        }
        else if (ar[i] == smallest)
        {
            smallestIndex = i;
        }
    }
    ar[smallestIndex] = largest;
    ar[largestIndex] = smallest;
}