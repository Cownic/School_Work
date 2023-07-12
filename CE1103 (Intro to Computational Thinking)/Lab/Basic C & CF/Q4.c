/* Write a C program that computes the value of e^x according to the following formula*/

#include <stdio.h>
int main()
{
    int n, denominator = 1;
    float x, result = 1.0, numerator = 1.0;

    printf("Enter x: \n");
    scanf("%f", &x);
    for (n = 1; n <= 10; n++)
    {
        denominator *= n;
        numerator *= x;
        result += numerator / denominator;
    }
    printf("Result = %.2f\n", result);
    return 0;
}