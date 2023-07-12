#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void MergeInsertion(int ar[], int first, int last , int *ptrCount , int S);
void MergeSort(int ar[], int start, int end);
void merge(int ar[], int start, int middle, int end , int *ptrCount);
void InsertionSort(int ar[] , int first , int last , int *ptrCount);

int main()
{
    int comparisions;
    int *ptrCount = &comparisions;
    int ar[100000];
    int i , j , k;
    struct timeval tv1;
    struct timeval tv2;

    //random 10000 numbers and putting into array
    for (i = 0; i < 99999; i++)
    {
        //ar[i] = 99999 -i;
        //ar[i] = rand() % (100000 - 1) + 1;
    }

    gettimeofday(&tv1 , 0);

    MergeInsertion(ar , 0 , 99999 , ptrCount , 16);

        
    gettimeofday(&tv2 , 0);

    printf("--------------------------------------------\n");


    double time_spent = (double)(tv2.tv_usec - tv1.tv_usec)/1000000 + (double)(tv2.tv_sec - tv1.tv_sec);

    printf("\n");
    printf("For array size = 100000 and sorted in ascending order: \n");
    printf("Number of Comparisions: %d "  , comparisions);
    printf("Time taken : %f\n", time_spent);


}


void MergeInsertion(int ar[], int first, int last , int *ptrCount , int S)
{
    
    if ((last - first) <= S){
        InsertionSort(ar , first , last , ptrCount);
    }
    else {
        int middle = (first+last) / 2;
        MergeInsertion(ar , first  , middle , ptrCount , S);
        MergeInsertion(ar , middle + 1 , last , ptrCount , S);
        merge(ar , first , middle , last , ptrCount);
    }
}

void merge(int ar[] , int start , int middle , int end , int *ptrCount)
{
    //getting a second pointer to point to the start of second half
    int start2 = middle + 1;

    //if already sorted , we can return already
    if (ar[middle] <= ar[start2]){
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
        }
        (*ptrCount)++;
    }
}

void InsertionSort(int ar[] , int first , int last , int *ptrCount)
{
   int i , j;
    int temp;
    //if lesser than 2 elemenets , it is already sorted
    if (last - first <= 1){
        return;
    }
    for (i = first + 1  ; i <= last ; i++){
        for (j = i  ; j >= first ; j--){
            (*ptrCount)++;
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
    
    /*
   for (int i = first + 1; i <= last; i++)
    {
        int temp = ar[i];
        int j = i - 1;
        while (j >= first && ar[j] > temp)
        {
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = temp;
    }
    */
}