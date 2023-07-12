/*(reverseDigits) Write a C function that takes in a positive integer number, reverses its digits and
returns the result to the calling function. You may assume that the last digit of the input number is
not 0, i.e. the number will not be in the form of 1110, 1200, etc. Write two iterative versions of the
function. The function reverseDigits1() returns the computed result, while reverseDigits2() passes
the result through the pointer parameter result*/

#include <stdio.h>
int reverseDigits1(int num);
void reverseDigits2(int num, int *result);
int main()
{
    int num, result = 999;
    printf("Enter a number: \n");
    scanf("%d", &num);
    printf("reverseDigits1(): %d\n", reverseDigits1(num));

    reverseDigits2(num, &result);
    printf("reverseDigits2(): %d\n", result);

    return 0;
}
int reverseDigits1(int num)
{
    int newNumber = 0;

    while (num >0){
        newNumber = (newNumber * 10) + num%10;
        num = num / 10;
    }

    return newNumber;
}
void reverseDigits2(int num, int *result)
{
    *result = 0;
    while (num >0){
        *result = (*(result)*10) + num%10;
        num = num / 10;
    }
    
}