#include <stdlib.h>
#include <stdio.h>


int fibRecursive(int n);

int main()
{
    int n;
    int result = 0;
    printf("Enter a value:");
    scanf("%d" , &n);
    result = fibRecursive(n);
    printf("The fibonacci sequence for %d is : %d" , n , result);
}

int fibRecursive(int n)
{
    if (n <= 1){
        return n;
    }
    
    return fibRecursive(n-1) + fibRecursive(n-2);
}