//A longest increasing subsequence is an increasing subsequence of maximum length
//Problem : Given a sequnce of n integers , determine the length of the longest increasing subsequence
#include <stdio.h>
#include <stdlib.h>


int LIS(int ar[] , int n);
int main()
{
    int result;
    int ar[] = {-7, 10 , 9 , 2 , 3 , 8 , 8, 1};

    int n = 8;

    result = LIS(ar , n);

    printf("%d " , result);

    return 0;
}

int LIS(int ar[] , int n)
{
    //create a n+1 array
    int temp[n+1];
    int length[n+1];
    int i , j;
    for (i = 0 ; i < n ; i++){
        temp[i] = ar[i];
        length[i] = 0;
    } 
    //To ensure that the longest length will always be returned
    temp[n] = INT_MAX;
    length[n] = 0;

    length[0] = 1;

    for (i = 0 ; i <= n ; i++){
        for (j = 0 ; j < i ; j++){
            if (temp[i] > temp[j]){
                length[i] = __max(length[i] , length[j]+1);
            }
        }
    }

    return length[n] -1;

}