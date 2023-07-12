/*(perfectProd) A perfect number is one that is equal to the sum of all its factors (excluding the
number itself). For example, 6 is perfect because its factors are 1, 2, and 3, and 6 = 1+2+3; but 24
is not perfect because its factors are 1, 2, 3, 4, 6, 8, 12, but 1+2+3+4+6+8+12 = 36. Write a
function that takes a number, num, prints the perfrct numbers that are less than the number, and
returns the product of all perfect numbers. For example, if the number is 100, the function should
return 168 (which is 6*28), as 6 and 28 are the only perfect numbers less than 100. If there is no
perfect number for the input number, then the function should return 1. Write the function in two
versions. The function perfectProd1() returns the result to the caller, while perfectProd2() passes
the result through the pointer parameter result.*/

#include <stdio.h>
int perfectProd1(int num);
void perfectProd2(int num, int *result);
int main()
{
    int number, result = 0;
    printf("Enter a number: \n");
    scanf("%d", &number);

    printf("Calling perfectProd1() \n");
    printf("perfectProd1(): %d\n", perfectProd1(number));

    printf("Calling perfectProd2() \n");
    perfectProd2(number, &result);

    printf("perfectProd2(): %d\n", result);
    return 0;
}
int perfectProd1(int num)
{
    int i;
    int j;
    int sum;
    int total = 1;

    for (i = 1 ; i <= num ; i++){
        sum = 0;
        for (j = 1 ; j <= i/2 ; j++){
            if (i%j == 0){
                sum+=j;
            }
        }
        if (sum == i){
            total *= sum;
            printf("Perfect number: %d\n" , sum);
        }
    }

    if (total == 1){
        return 0;
    }
    return total;
}
void perfectProd2(int num, int *result)
{
    int i , j;
    int sum;
    *result = 1;
    for (i = 1 ; i <= num ; i++){
        sum = 0;
        for (j = 1 ; j <= i/2 ; j++){
            if (i%j == 0){
                sum+=j;
            }
        }
        if (sum == i){
            *result = *result * i;
            printf("Perfect number: %d\n" , sum);
        }
    }

    if (*result == 1){
        *result = 0;
        return;
    }

    return;
}