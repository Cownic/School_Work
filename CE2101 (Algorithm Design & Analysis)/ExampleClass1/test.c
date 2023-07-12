#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


void merge_sort(int input[], int start, int end , int *ptrCount)
{
    int mid = (start + end)/2;
    if(end-start <= 0)
        return;
    else if(end - start > 1)
    {
        merge_sort(input, start, mid , ptrCount);
        merge_sort(input, mid+1, end , ptrCount);
    }
    merge(input, start, end , ptrCount);

}

void merge(int input [], int start, int end , int *ptrCount)
{
    int mid = (start + end) / 2;
    int first = start;
    int last = mid+1;
    int temp[end - start + 1];
    int i = 0;
    if(end - start)
        return;
    while(start <= mid && last <= end)
    {
        if(input[first] < input[last])
            temp[i++] = input[first++];
        else
            temp[i++] = input[last++];
    }
    while(first <= mid)
        temp[i++] = input[first++];
    while(last <= end)
        temp[i++] = input[last++];
    for(i = 0; i <(end - start + 1); i++)
    {
        input[start + i] = temp[i];
    }
}


int main()
{
    int comparisions;
    int *ptrCount = &comparisions;
    struct timeval stop, start;
    int ar[10000];
    int ar1[10000];
    int i , j , k;

    //random 10000 numbers and putting into array
    for (i = 0; i < 9999; i++)
    {
        
        ar[i] = rand() % (100000 - 1) + 1;
    }

    for (j = 1 ;  j <= 64 ; j *= 2){
        comparisions = 0;
        for (k = 0 ; k < 9999 ; k++){
            ar1[k] = ar[k];
        }

        for (k = 0 ; k < 9999 ; k++){
            printf("%d " , ar[k]);
        }


        struct timeval start;
        struct timeval end1;
        gettimeofday(&start , 0);
        clock_t begin = clock();
        merge_sort(ar1 , 0 , 9999 , ptrCount);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        
        gettimeofday(&end1 , 0);

        for (k = 0 ; k < 9999 ; k++){
            printf("%d " , ar[k]);
        }

        printf("--------------------------------------------\n");


        //printf("Code runtime when S = %d is %d microseconds\n" ,j, ((end1.tv_sec - start.tv_sec) * 1000000) + (end1.tv_sec = start.tv_sec));
        //printf(" %d ", comparisions);
        
        printf("\n");
        printf("Number of Comparisions when S = %d is : %d\n" , j , comparisions);
        printf("Time taken : %f\n", time_spent);

        //printf("--------------------------------------------\n");
    }

}