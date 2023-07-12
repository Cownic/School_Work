/*(countEvenDigits) Write a C function to count the number of even digits, i.e. digits with values
0,2,4,6,8 in a positive number (>0). For example, if number is 1234567, then 3 will be returned.
Write the function in two versions. The function countEvenDigits1() returns the result,
while the function countEvenDigits2() returns the result via the pointer parameter, count.*/

#include <stdio.h>
int countEvenDigits1(int number);
void countEvenDigits2(int number, int *count);
int main()
{
    int number, count;
    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("countEvenDigits1(): %d\n", countEvenDigits1(number));
    countEvenDigits2(number, &count);
    printf("countEvenDigits2(): %d\n", count);
    return 0;
}
int countEvenDigits1(int number)
{
    int count = 0;
    while (number > 0){
        if ((number%10) % 2 == 0){
            count++;
        }
        number = number / 10;
    }
    return count;
}
void countEvenDigits2(int number, int *count)
{
    *count = 0;
    while (number >0){
        if((number%10) % 2 == 0){
            (*count)++;
        }
        number = number / 10;
    }
}