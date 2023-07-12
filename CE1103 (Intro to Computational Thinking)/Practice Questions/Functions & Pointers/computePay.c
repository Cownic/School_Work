/*(computePay) Write a C function that determines the gross pay for an employee in a company.
The company pays straight-time for the first 160 hours worked by each employee for four weeks
and pays time-and-a-half for all hours worked in excess of 160 hours. The function takes in the
number of hours each employee worked for the four weeks, and the hourly rate of each employee.
Write the function in two versions. The function computePay1() returns the gross pay to the
calling function, while the function computePay2() returns the gross pay to the calling
function through the pointer parameter, grossPay.*/

#include <stdio.h>
double computePay1(int noOfHours, int payRate);
void computePay2(int noOfHours, int payRate, double *grossPay);
int main()
{
    int noOfHours, payRate;
    double grossPay;

    printf("Enter number of hours: \n");
    scanf("%d", &noOfHours);
    printf("Enter hourly pay rate: \n");
    scanf("%d", &payRate);
    printf("computePay1(): %.2f\n", computePay1(noOfHours, payRate));
    computePay2(noOfHours, payRate, &grossPay);
    printf("computePay2(): %.2f\n", grossPay);
    return 0;
}
double computePay1(int noOfHours, int payRate)
{
    double grossPay;
    if (noOfHours <= 160){
        grossPay = noOfHours * payRate;
        return grossPay;
    }
    else if (noOfHours > 160){
        grossPay = (160 * payRate) + ((noOfHours-160) * (1.5*payRate));
        return grossPay;
    }
}
void computePay2(int noOfHours, int payRate, double *grossPay)
{
    if (noOfHours <= 160){
        *grossPay = noOfHours * payRate;
        return;
        
    }
    else if (noOfHours > 160){
        *grossPay = (160 * payRate) + ((noOfHours-160) * (1.5*payRate));
        return;
        
    }
    
}
