#include <stdio.h>
#include <stdlib.h>
//Bottom up approach (use memorisation method)
//Time complexity is O(Cn)
int knapsack(int w[], int p[], int C, int n);
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

    result = knapsack(w, p, C, n);
    printf("The maximum profit is %d for C: %d & n:%d", result, C, n);

    return 0;
}

int knapsack(int w[], int p[], int C, int n)
{
    //c is used to keep track of number of items column index
    // r is to keep track of the current capacity  row index
    int c, r;
    int profit[C + 1][n + 1];

    for (c = 0; c <= n; c++)
    {
        profit[0][c] = 0; //if the number of items is zero , there will be no profit
    }

    for (r = 1; r <= C; r++)
    {
        profit[r][0] = 0;//if the capacity is zero , we cant put any items , hence no profit
    }

    //loop thru the whole 2d array and update from top left to bottom right
    for (r = 1; r <= C; r++)
    {
        for (c = 1; c <= n; c++)
        {
            //first case is to not include current item into my sack
            profit[r][c] = profit[r][c - 1];

            //second case is to include current item into my sack if my current capacity allows for it
            if (w[c - 1] <= r)
            {
                //comparing which to see which one is of a better profit and put better profit in
                if (profit[r][c] < profit[r - w[c - 1]][c - 1] + p[c - 1])
                {
                    profit[r][c] = profit[r - w[c - 1]][c - 1] + p[c - 1];
                }
            }
        }
    }

    for (r = 0; r <= C; r++)
    {
        for (c = 0; c <= n; c++)
        {
            printf("%d  |", profit[r][c]);
        }
        printf("\n");
    }

    return profit[C][n];
}
