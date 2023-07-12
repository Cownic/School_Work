#include <stdlib.h>
#include <stdio.h>
//Top-Down approach (recurisve)
//Time complexity is 2^n
//Alot will will be computed more than once in this approach
int knapsack(int w[] , int p[] , int C , int n);
int max(int a , int b);
int main()
{
    int result;
    //number of items that we have
    int n = 4;
    //capacity of the knapsack
    int C = 10;
    //weight array
    int w[4] = {5, 4, 6, 3};
    //benefit array
    int p[4] = {10, 40, 30, 50};

    result = knapsack(w, p, C, n);
    printf("The maximum profit is %d for C: %d & n:%d", result, C, n);

    return 0;
}

int max(int a , int b)
{
    // will return the bigger of the two
    if (a > b){
        return a;
    }
    else {
        return b;
    }
}

int knapsack(int w[] , int p[] , int C , int n)
{
    if (C == 0 || n == 0){
        return 0;
    }

    //if the weight of the current item is greater than 
    //the remaining knapsack capacity , then we will not put it in
    if (w[n-1] > C){
        return knapsack(w , p , C , n-1);
    }
    else {
        //return the bigger of the two
        // either dont include or include current item
        return max(knapsack(w , p , C , n-1) , p[n-1] + knapsack(w , p , (C-w[n-1]) , n-1));
    }
}