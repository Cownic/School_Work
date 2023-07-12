#include <stdio.h>
#include <stdlib.h>
//Bottom up approach (use memorisation method)
// different from 1/0 knapsack problem
int unboundedKnapSack(int w[], int p[], int C, int n);
int max(int a , int b);
int main()
{
    int result;
    //number of items that we have
    int n = 3;
    //capacity of the knapsack
    int C = 14;
    //weight array
    int w[3] = {5,6,8};
    //benefit array
    int p[3] = {7,6,9};

    result = unboundedKnapSack(w, p, C, n);
    printf("The maximum profit is %d for C: %d & n:%d", result, C, n);

    return 0;
}

int max(int a , int b)
{
    if (a > b){
        return a;
    }
    else {
        return b;
    }
}
int unboundedKnapSack(int w[] , int p[] , int c , int n)
{
    int profit[c+1];
    int i , j , k;

    //initialise the knapsack as all zero
    for (i = 0 ; i <= c ; i++){
        profit[i] = 0;
    }

    for (i = 0 ; i <= c ; i++){
        for (j = 0 ; j < n ; j++){
            if (w[j] <= i){
                profit[i] = max(profit[i] , profit[i-w[j]] + p[j]);
            }
        }
    }

    for (k = 0 ; k <= c ; k++){
                printf("%d " , profit[k]);
            }
            printf("\n");



    return profit[c];
}