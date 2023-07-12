/*(specialNumbers1D) A special number is a 3 digit positive integer, in which the sum of the cubes of each
digit is equal to the number. For example, the number 407 is a special number as 407 = 4×4×4 + 0×0×0 +
7×7×7. Write a C function that computes special numbers from 100 up to the a specified number. The
function takes an array of integers ar, num and size as parameters. The parameter num is the specified
integer number. The parameter size is declared as a pointer which will return the size of the array storing
the special numbers to the caller*/

#include <stdio.h>

void specialNumbers1D(int ar[], int num, int *size);
int main()
{
    int a[20], i, size = 0, num;

    printf("Enter a number (between 100 and 999): \n");
    scanf("%d", &num);
    specialNumbers1D(a, num, &size);
    printf("specialNumbers1D(): ");
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    return 0;
}

void specialNumbers1D(int ar[], int num, int *size)
{
    int i;
    int j;
    int sum = 0;
    for (i = 100; i <= num; i++)
    {
        j = i; //so that the for loop will not be affected
        while (j > 0)
        {
            sum = sum + ((j % 10) * (j % 10) * (j % 10));
            j = j / 10;
        }
        if (sum == i) // must compare to i instead of j as j will become 0
        {
            ar[*size] = sum;
            (*size)++;
        }
        sum = 0;
    }
}