/*(customer) Write a C program that repeatedly reads in customer data from the user and prints the
customer data on the screen until the customer name "End Customer" (i.e., first_name last_name) is
read. Your program should include the following two functions: the function nextCustomer() reads
and returns a record for a single customer to the caller via a pointer parameter acct, and the function
printCustomer() takes a parameter acct and then prints the customer information. */

#include <stdio.h>
#include <string.h>
struct account{
    struct{
        char lastName[10];
        char firstName[10];
    } names;
    int accountNum;
    double balance;
};

void nextCustomer(struct account *acct);
void printCustomer(struct account acct);
int main()
{
    struct account record;
    int flag = 0;

    do {
        nextCustomer(&record);
        if (strcmp(record.names.firstName , "End") == 0 && strcmp(record.names.lastName , "Customer") == 0){
            flag = 1;
        }
        if (flag != 1){
            printCustomer(record);
        } 
    }while (flag != 1);
}

void nextCustomer(struct account *acct)
{
    printf("Enter names (firstName lastName):\n");
    scanf("%s %s" , acct->names.firstName , acct->names.lastName);
    if (strcmp(acct->names.firstName , "End") == 0 && strcmp(acct->names.lastName , "Customer") == 0){
            return;
        }
    printf("Enter account number:\n");
    scanf("%d" , &acct->accountNum);
    printf("Enter balance:\n");
    scanf("%lf" , &acct->balance);
}

void printCustomer(struct account acct)
{
    printf("%s %s %d %.2lf\n" , acct.names.firstName , acct.names.lastName , acct.accountNum , acct.balance);
}

