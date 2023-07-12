#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void MergeSort(int ar[], int start, int end , int *ptrCount);
void merge(int ar[], int start, int middle, int end , int *ptrCount);


int main()
{
    int comparisions;
    int *ptrCount = &comparisions;
    int ar[10000];
    int ar1[10000];
    int i , j , k;
    struct timeval tv1;
    struct timeval tv2;

    //random 10000 numbers and putting into array
    for (i = 0; i < 9999; i++)
    {
        ar[i] =  i;
        //ar[i] = rand() % (10000 - 1) + 1;
    }

    gettimeofday(&tv1 , 0);

    MergeSort(ar , 0 , 9999 , ptrCount );

        
    gettimeofday(&tv2 , 0);

    printf("--------------------------------------------\n");


    double time_spent = (double)(tv2.tv_usec - tv1.tv_usec)/1000000 + (double)(tv2.tv_sec - tv1.tv_sec);

    printf("\n");
    printf("For array size = 100000 and sorted in ascending order: \n");
    printf("Number of Comparisions: %d "  , comparisions);
    printf("Time taken : %f\n", time_spent);



}

void MergeSort(int ar[], int first, int last , int *ptrCount)
{

    
    if (first < last){

        int middle = (first + last) / 2;
        //Spliting the array into smaller and smaller subproblems
        MergeSort(ar , first , middle , ptrCount);
        MergeSort(ar , middle+1 , last , ptrCount);

        //sorting ascending function
        merge(ar , first , middle , last , ptrCount);
    }


}

void merge(int ar[] , int start , int middle , int end , int *ptrCount)
{
    //getting a second pointer to point to the start of second half
    int start2 = middle + 1;

    //if already sorted , we can return already
    if (ar[middle] <= ar[start2]){
        (*ptrCount)++;
        return;
    }

    while (start <= middle && start2 <= end){
        //if  first array element is smaller than the second array element
        if (ar[start] <= ar[start2]){
            start++;
        }
        else {
        //if the first array element is smaller then the second array element
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
            (*ptrCount)++;
        }
    }
}
