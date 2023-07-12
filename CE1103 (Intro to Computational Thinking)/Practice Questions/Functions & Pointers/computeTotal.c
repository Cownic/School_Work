/*(computeTotal) Write a function that accepts an integer numOfLines as parameter, reads in
specified number of lists of numbers according to numOfLines, one list per line, computes the
total for each list and displays the total on the screen. For each list of numbers, the first number
indicates how many elements are in the list. Your function does not need to check user input errors.*/

#include <stdio.h>
void computeTotal(int numOfLines);
int main()
{
    int numOfLines;
    printf("Enter number of lines: \n");
    scanf("%d", &numOfLines);

    computeTotal(numOfLines);
    return 0;
}
void computeTotal(int numOfLines)
{
    int i;
    int total;
    int num;
    int noOfNumbers;
    for (i = 1 ; i <= numOfLines ; i++){
        total = 0;
        printf("Enter line %d:\n" , i);
        scanf("%d" , &noOfNumbers);
        while (noOfNumbers != 0){
            scanf("%d" , &num);
            total+=num;
            noOfNumbers--;
        }
        printf("Total: %d\n" , total);
    }
}