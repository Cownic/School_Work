/*(allEvenDigits) Write a function that returns either 1 or 0 according to whether or not all the digits
of the positive integer argument number are even. For example, if the input argument is 2468, then
the function should return 1; and if the input argument is 1234, then 0 should be returned. Write
the function in two versions. The function allEvenDigits1() returns the result to the caller,
while allEvenDigits2() passes the result through the pointer parameter, result.*/

#include <stdio.h>
int allEvenDigits1(int num);
void allEvenDigits2(int num, int *result);
int main()
{
    int number, p = 999, result = 999;
    printf("Enter a number: \n");
    scanf("%d", &number);
    p = allEvenDigits1(number);
    if (p == 1)
        printf("allEvenDigits1(): yes\n");
    else if (p == 0)
        printf("allEvenDigits1(): no\n");
    else
        printf("allEvenDigits1(): error\n");
    allEvenDigits2(number, &result);
    if (result == 1)
        printf("allEvenDigits2(): yes\n");
    else if (result == 0)
        printf("allEvenDigits2(): no\n");
    else
        printf("allEvenDigits2(): error\n");
    return 0;
}
int allEvenDigits1(int num)
{
    while (num > 0){
        if ((num%10) % 2 != 0){
            return 0;
        }
        num = num / 10;
    }
    return 1;
}

void allEvenDigits2(int num, int *result)
{
    while (num > 0){
        if ((num%10) % 2 != 0){
            *result = 0;
            return;
        }
        num = num / 10;
    }
    *result = 1;
    return;
}