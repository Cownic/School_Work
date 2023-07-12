#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/* This is storing the value each time it is a new value so we can get the value the next time without 
    going into a recursive call
*/
int fibDPTopDown(int n , int *ptrArr);
void store(int *ptrArr , int n , int z);
int notIn(int *ptrArr , int n);
int retrive(int *ptrArr , int n);

int main()
{
    int n , i;
    int result = 0;
    int *ptrArr;
    printf("Enter a value:");
    scanf("%d" , &n);
    ptrArr = (int*)malloc(sizeof(int) * n);
    for (i = 0 ; i < n ; i++){
        ptrArr[i] = -1;
    }
    result = fibDPTopDown(n , ptrArr);
    printf("The fibonacci sequence for %d is : %d" , n , result);
}

int fibDPTopDown(int n , int *ptrArr)
{
    int f1 , f2;

    if (n == 0 || n == 1){
        store(ptrArr ,n , n );
        return n;
    }
    else {
        if (notIn(ptrArr, n-1)){
            f1 = fibDPTopDown(n-1 , ptrArr);
        }
        else {
            f1 = retrive(ptrArr , n-1);
        }

        if (notIn(ptrArr , n-2)){
            f2 = fibDPTopDown(n-2 , ptrArr); 
        }
        else {
            f2 = retrive(ptrArr , n-2);
        }
    }

    f1+=f2;
    store(ptrArr ,n , f1);
    return f1;
}

void store(int *ptrArr , int n , int z)
{
    ptrArr[n] = z;
}

int notIn(int *ptrArr , int n)
{
    if (ptrArr[n] == -1){
        return 1;
    }
    else {
        return 0;
    }
}

int retrive(int *ptrArr , int n)
{
    return ptrArr[n];
}