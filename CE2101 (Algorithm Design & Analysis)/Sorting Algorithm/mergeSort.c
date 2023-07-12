#include <stdio.h>
#include <stdlib.h>

void mergeSort(int ar[] , int start , int end);
void merge(int ar[] , int start , int middle  , int end); //sorting function

int main()
{
    int i = 0;
    int length = 8;
    int ar[8] = {1,6,3,9,11,20,4,5};

    printf("The list before sorting is:\n");
    for (i = 0 ;i < 8 ; i++){
        printf("%d " , ar[i]);
    }

    printf("\n");

    mergeSort(ar , 0 , 7);

    printf("The list after sorting is:\n");
    for (i = 0; i < 8 ; i++){
        printf("%d " , ar[i]);
    }

    return 0;
}

void mergeSort(int ar[] , int start , int end)
{
    //base case for recursion
    if (start < end){

        
        int middle = (start+end) / 2;
        //Spliting the array into smaller and smaller subproblems
        mergeSort(ar , start , middle);
        mergeSort(ar , middle+1 , end);

        //sorting ascending function
        merge(ar , start , middle , end);
    }
}


void merge(int ar[] , int start , int middle , int end)
{
    int length = (end-start) + 1;
    int tempar[length];
    int i = 0;
    int k = start;
    int j = middle+1;
    while (k <= middle && j <= end){
        if (ar[k] < ar[j]){
            tempar[i] = ar[k];
            k++;
            i++;
        }
        else {
            tempar[i] = ar[j];
            j++;
            i++;
        }
    }
    //settling the left over
    while (k <= middle){
        tempar[i] = ar[k];
        k++;
        i++;
    }

    //settling the leftover
    while (j<= end){
        tempar[i] = ar[j];
        j++;
        i++;
    }

    //copying the temp array back to the main array
    for (i = 0 ; i < length ; i++){
        ar[start + i] = tempar[i];
    }
}


