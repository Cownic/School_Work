#include <stdio.h>
#include <stdlib.h>

void mergeSort(int ar[] , int start , int end);
void merge(int ar[] , int start , int middle  , int end); //sorting function

int main()
{
    int i = 0;
    int length = 8;
    int ar[8] = {1,6,3,3,11,20,4,5};

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
    //getting a second pointer to point to the start of second half
    int start2 = middle + 1;

    //if already sorted , we can return already
    if (ar[middle] <= ar[start2]){
        return;
    }

    while (start <= middle && start2 <= end){
        //if  first array element is smaller than the second array element
        if (ar[start] < ar[start2]){
            start++;
        }
        else {
        //if the first array element is larger then the second array element
            int value = ar[start2];
            int index = start2;
            while(index != start){ //shifting all elements by 1 to the right to make space for the smaller element to move forward
                ar[index] = ar[index-1];
                index--;
            }
            //inserting the value at the new location
            ar[start] = value;
             //slowly moving all pointers to the right as the list get sorted
            start++;
            middle++;
            start2++;
        }
    }
}