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
    struct timeval stop, start;
    int ar[100000];
    int ar1[100000];
    int i , j , k;

    //random 10000 numbers and putting into array
    for (i = 0; i < 99999; i++)
    {
        //ar[i] = i+1;
        ar[i] = 100000 - i;
        //ar[i] = rand() % (10000 - 1) + 1;
    }

    for (j = 1 ;  j <= 64 ; j *= 2){
        comparisions = 0;
        for (k = 0 ; k < 99999 ; k++){
            ar1[k] = ar[k];
        }


        struct timeval start;
        struct timeval end1;
        gettimeofday(&start , 0);

        MergeInsertion(ar1 , 0 , 99999 , ptrCount , j);

        
        gettimeofday(&end1 , 0);

        printf("--------------------------------------------\n");


        printf ("Total time = %f microseconds\n",(double)(end1.tv_usec - start.tv_usec) / 1000000 +(double)(end1.tv_sec  - start.tv_sec));

        //printf(" %d ", comparisions);
        
        printf("\n");
        printf("Number of Comparisions when S = %d is : %d\n" , j , comparisions);


        //printf("--------------------------------------------\n");
    }

   
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