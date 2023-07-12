#include <stdio.h>
#include <stdlib.h>

void insertionSort(int ar[] , int n);

int main()
{
    int i = 0;
    int length = 8;
    int ar[8] = {1,6,3,9,11,20,4,6};

    printf("The list before sorting is:\n");
    for (i = 0 ;i < 8 ; i++){
        printf("%d " , ar[i]);
    }

    printf("\n");

    insertionSort(ar , length);

    printf("The list after sorting is:\n");
    for (i = 0; i < 8 ; i++){
        printf("%d " , ar[i]);
    }

    return 0;
}

void insertionSort(int ar[] , int n)
{
    int i , j;
    int temp;
    //if lesser than 2 elemenets , it is already sorted
    if (n <= 1){
        return;
    }

    for (i = 1 ; i < n ; i++){
        for (j = i ; j > 0 ; j--){
            if (ar[j] < ar[j-1]){ //pair - wise swapping
                temp = ar[j];
                ar[j] = ar[j-1];
                ar[j-1] = temp;
            }
            else {
                break;
            }
        }
    }
}