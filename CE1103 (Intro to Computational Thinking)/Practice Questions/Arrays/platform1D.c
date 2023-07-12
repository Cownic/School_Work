/*(platform1D) The number of consecutive array elements in an array that contains the same integer value
forms a ‘platform’. Write a C function that takes in an array of integers ar and size as parameters, and
returns the length of the maximum platform in ar to the calling function.*/

#include <stdio.h>

int platform1D(int ar[] , int size);
int main()
{
    int i , b[50] , size;

    printf("Enter the array size: \n");
    scanf("%d" , &size);
    printf("Enter %d data: \n" , size);
    for (i = 0 ; i < size ; i++){
        scanf("%d" , &b[i]);
    }
    printf("platform1D(): %d\n" , platform1D(b , size));
    return 0;
}

int platform1D(int ar[] , int size)
{
    int longest = 1;
    int count = 1;
    int current = ar[0];
    int i;
    for (i = 1 ; i < size ; i++){
        if (ar[i] == current){
            count++;
        }
        else {
            if (count > longest){
                longest = count;
            }
            current = ar[i];
            count = 1;
        }
    }

    if (count > longest){
        longest = count;
    }

    return longest;

}