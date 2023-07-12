/*(find2Max1D) Write a C function find2Max1D() that takes an one-dimensional array of integer
numbers ar and size (>1) as parameters. The function returns the largest and second largest numbers of
the array to the calling function through the two pointer parameters max1 and max2 respectively. For
example, if the array a[]={1,7,8,6,9,4,5,2,3}, then max1 is 9, and max2 is 8. In this question, you may
assume that the input data contains unique integers*/

#include <stdio.h>
void find2Max1D(int ar[] , int size , int *max1 , int *max2);
int main()
{
    int max1 , max2;
    int ar[10] , size , i;

    printf("Enter array size:\n");
    scanf("%d" , &size);
    printf("Enter %d data:\n" , size);
    for (i = 0 ; i < size ; i++){
        scanf("%d" , &ar[i]);
    }
    find2Max1D(ar ,size , &max1 , &max2);
    printf("Max1: %d\nMax2: %d\n" , max1 , max2);
    return 0;
}

void find2Max1D(int ar[] , int size , int *max1 , int *max2)
{
    int i;
    int temp;
    *max1 = ar[0];
    *max2 = ar[size-1];
    if (*max2 > *max1){
        temp = *max1;
        *max1 = *max2;
        *max2 = temp;
    }
    for (i = 1 ; i < size ; i++){
        if (*max1 > ar[i] && *max2 < ar[i]){
            *max2 = ar[i];
        }
        else if (ar[i] > *max1 && ar[i] > *max2){
            if (*max1 > *max2){
                *max2 = *max1;
            }
            *max1 = ar[i];
        }
    }
}