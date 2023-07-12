#include <stdio.h>
#include <stdlib.h>

void quickSort(int ar[] ,  int start , int end);
int partition(int ar[] , int start , int end);

int main()
{
    int i;
    int ar[8] = {10,6,3,9,11,20,4,5};
    printf("The list before sorting is:\n");
    for (i = 0; i < 8 ; i++){
        printf("%d " , ar[i]);
    }

    printf("\n");
    quickSort(ar , 0 , 7);

    printf("The list after sorting is:\n");
    for (i = 0 ; i < 8 ; i++){
        printf("%d " , ar[i]);
    }
}

void quickSort(int ar[] , int start , int end)
{
    int pivot_pos;
    if (start < end){ //ending condtion
        pivot_pos = partition(ar , start , end); // allow for problem size to decrease every recursive call
        //No nid touch pivot_pos anymore as it is in correct position already
        quickSort(ar , start , pivot_pos -1);
        quickSort(ar , pivot_pos + 1 , end);
    }
}

int partition(int ar[] , int start , int end)
{
    int i , lastSmall , pivot , temp , pivotValue;

    pivot = (start+end)/2;
    pivotValue = ar[pivot];

    //shifting the pivot element value to the start of the array
    temp = ar[pivot];
    ar[pivot] = ar[start];
    ar[start] = temp;

    lastSmall = start;

    for (i = start+1 ; i <= end ;  i++){
        if (ar[i] < pivotValue){
            ++lastSmall;
            temp = ar[lastSmall];
            ar[lastSmall] = ar[i];
            ar[i] = temp;
        }
    }
    temp = ar[lastSmall];
    ar[lastSmall] = ar[start];
    ar[start] = temp;

    return lastSmall;

/*
    int temp;
    int lb = start;
    int ub = end;
    int pivot = ar[end];

    while (lb < ub){
        while (ar[lb] < pivot){
            lb++;
        }
        while (ar[ub] >= pivot){
            ub--;
        }
        if (lb < ub){
            temp = ar[lb];
            ar[lb] = ar[ub];
            ar[ub] = temp;
        }
    }    
    temp = ar[lb];
    ar[lb] = ar[end];
    ar[end] = temp;
    return lb;
*/
}