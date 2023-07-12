/* Chain Matrix Multiplication - finding the order of multiplying the matrices 
so that we will do the minimal number of multiplication
*/
#include <stdio.h>
#include <stdlib.h>
void printParenthesis(int i , int j , int n , int *last , char name);
void matricOrder(int d[] , int n);
int main()
{
    int i , j;
    int n = 4;
    char name = 'A';
 
    //d array will be n+1 as each matrix is 2 dimensional
    int d[5] = {20 , 2 , 15 , 40 , 4};

    matricOrder(d , n);
}

void printParenthesis(int i , int j , int n , int *last , char name)
{
    if (i == j){
        printf("%c " , name++);
    }

    printf("(");

    printParenthesis(i, *((last + i * n) + j), n, last, name);
    printParenthesis(*((last + i * n) + j) + 1, j, n, last, name);

    printf(")");
}


void matricOrder(int d[] , int n)
{
    int i , j , k , c, L ;
    int name = 1;
    //find the cost of each matrix multipliaction by splitting at various points
    //initialising a 2d array dynamically
    int cost[n+1][n+1];
    //keep track of which will giv us the least number of multiplication
    int last[n+1][n+1];

    //initialise all slots as 0
    for (i = 0 ; i <= n ;i++){
        for (j = 0 ;j<= n ; j++){
            cost[i][j] = -1;
            last[i][j] = -1;
        }
    }

    //all this slots represent a single matrix and multiplication is not possible with one matrix , hence 0 mutiplicaition done
    for (i = 0 ; i < n ; i++){
        cost[i][i+1] = 0;
    }

    for (L = 2 ; L <= n ; L++){ //this is the difference between the row & col index (relationship)
        for (i = 0 ; i <= n-L ; i++){ //running from row 0 to row n-1
            j = i + L; //using offset to get the column index each time

            //initialise
            cost[i][j] = INT_MAX;

            for (k = i+1 ; k <= j-1 ; k++){ //finding all the possible ways to split the matrix multiplication
                c = cost[i][k] + cost[k][j] + (d[i] * d[j] * d[k]);
                if (c < cost[i][j]){
                   cost[i][j] = c; //updating my cost of multiplication in each step
                    last[i][j] = k; // rmb where i do my last multiplication
                }
            }
        }
    }


    //Print the cost matrix
    for (i = 0 ; i <= n ; i++){
        for (j = 0 ; j <= n ; j++){
            printf("%d           " , cost[i][j]);
        }
        printf("\n");
    }

    for (i = 0 ; i <= n ; i++){
        for (j = 0 ; j <= n ; j++){
            printf("%d           " , last[i][j]);
        }
        printf("\n");
    }

    printParenthesis(0 , n  , n+1 , (int*)last , name);
}


