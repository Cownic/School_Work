/*(printPattern2) Write a function that accepts an integer number height (between 1 and 9) as its
parameter, and prints a pattern with the specified height. For example, if height = 4, the
following pattern will be printed:
A
BA
ABA
BABA
If height = 7, then the following pattern will be printed:
A
BA
ABA
BABA
ABABA
BABABA
ABABABA*/

#include <stdio.h>
void printPattern2(int height);
int main()
{
    int height;

    printf("Enter the height: \n");
    scanf("%d" , &height);
    printf("printPattern2(): \n");
    printPattern2(height);

    return 0;
}

void printPattern2(int height)
{
    int i , j;
    for (i = 1 ; i <= height ; i++){
        for (j = 1 ; j <= i ; j++){
            if (i % 2 != 0){
                if (j % 2 != 0){
                    printf("A");
                }
                else {
                    printf("B");
                }
            }
            else if (i % 2 == 0){
                if (j % 2 != 0){
                    printf("B");
                }
                else {
                    printf("A");
                }
            }
        }
        printf("\n");
    }

    return;
}