/*(power) Write a function that computes the power p of a positive number num. The power may be
any integer value. Write two iterative versions of the function. The function power1() returns the
computed result, while power2() passes the result through the pointer parameter result.*/

#include <stdio.h>
float power1(float num, int p);
void power2(float num, int p, float *result);
int main()
{
    int power;
    float number, result = -1;
    printf("Enter the number and power: \n");
    scanf("%f %d", &number, &power);
    printf("power1(): %.2f\n", power1(number, power));
    power2(number, power, &result);
    printf("power2(): %.2f\n", result);
    return 0;
}
float power1(float num, int p)
{
    float total = 1.0;
    if (num == 0){
        return 0.0;
    }
    if (p > 0){
        while (p != 0){
            total = total * num;
            p--;
        }
        return total;
    }
    else if (p < 0){
        while (p != 0){
            total = total * num;
            p++;
        }
        return 1/ total;
    }
    else if (p == 0){
        return total;
    }
}
void power2(float num, int p, float *result)
{
    *result = 1.0;
    if (num == 0){
        *result = 0.0;
        return;
    }
    
    if (p > 0){
        while (p > 0){
            *result = *result * num;
            p--;
        }
        return;
    }
    else if (p < 0){
        while (p < 0){
            *result = *result * num;
            p++;
        }
        *result = 1 / *result;
        return;
    }
    else if (p == 0){
        *result = 1.0;
        return;
    }
}