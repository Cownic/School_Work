/*Write a function that extracts the even digits from a positive number, and
combines the even digits sequentially into a new number. The new number is returned to the
calling function. If the input number does not contain any even digits, then the function returns -1.
For example, if the input number is 1234567, then 246 will be returned; and if the input number is
13, then –1 will returned. You do not need to consider the input number such as 0, 20, 3033, etc.
Write the function in two versions. The function extEvenDigits1() returns the result to the
caller, while the function extEvenDigits2() returns the result through the pointer parameter,
result*/

#include <stdio.h>
#define INIT_VALUE 999

int extEvenDigits1(int num);
void extEvenDigits2(int num , int *result);

int main()
{
    int number , result = INIT_VALUE;

    printf("Enter a number:\n");
    scanf("%d" , &number);
    printf("extEvenDigits1(): %d\n" , extEvenDigits1(number));

    extEvenDigits2(number , &result);
    printf("extEvenDigits2(): %d\n " , result);

    return 0;
}

int extEvenDigits1(int num)
{
    int total;
    int count = 1;
    while (num > 0){
        if ((num%10) % 2 == 0){
            total = total + ((num%10) * count);
            count = count * 10;
            
        }
        num = num / 10;
    }

    if (total == 0){
        return -1;
    }
    else {
        return total;
    }
}

void extEvenDigits2(int num , int *result)
{
    int count = 1;
    *result = 0;
    while (num > 0){
        if ((num%10) % 2 == 0){
            *result = *result + ((num%10) * count);
            count = count * 10;
        }
        num = num / 10;
    }

    if (*result == 0){
        *result = -1;
        return;
    }
}