/*(square) Write a function square1() that returns the square of a positive integer
number num, by computing the sum of odd integers starting with 1 as shown in the
example below. The result is returned to the calling function. For example, if num =
4, then 42 = 1 + 3 + 5 + 7 = 16 is returned; if num = 5, then 52 = 1 + 3 + 5 + 7 + 9 = 25 is
returned.*/

#include <stdio.h>
int square1(int num);
void square2(int num, int *result);
int main()
{
    int number, result = 0;
    printf("Enter the number: \n");
    scanf("%d", &number);

    printf("square1(): %d\n", square1(number));

    square2(number, &result);
    printf("square2(): %d\n", result);

    return 0;
}
int square1(int num)
{
    int counter = num * 2;
    int i;
    int total = 0;
    for (i = 1 ; i <= counter ; i++){
        if (i%2 != 0){
            total+=i;
        }
    }
    return total;

}
void square2(int num, int *result)
{
    int counter = num * 2;
    int i;
    int total = 0;
    for (i = 1 ; i <= counter ; i++){
        if (i%2 != 0){
            *result+=i;
        }
    }
    return;
}