#include <stdio.h>
#include <stdlib.h>
/* This is solving from the smallest to the largest */
void fibBPBottomUp(int size);
int main()
{
    int size;
    int *ar;
    printf("Enter a value:");
    scanf("%d" , &size);

    fibBPBottomUp(size);

    return 0;
}

void fibBPBottomUp(int size)
{
    int ar[size + 1];
    int i;
    for (i = 0 ; i <= size ; i++){
        ar[i] = -1;
    }

    ar[1] = 1;
    ar[0] = 0;

    for (i = 2 ; i <= size ; i++){
        ar[i] = ar[i-1] + ar[i-2];
    }

    printf("The fibonacci sequence for n = size is : %d" , ar[size]);
}