#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int LCS(char string1[] , char string2[]);



int main()
{
    int result;
    char string1[] = "CAGAG";
    char string2[] = "ACTGG";

    result = LCS(string1 , string2);
    printf("The longest common subsequence length between %s & %s  is : %d" , string1 , string2 , result);

    return 0;
}

int LCS(char string1[] , char string2[])
{
    int i , j;
    int k = 0;
    int n = strlen(string1);
    int m = strlen(string2);
    int ar[n+1][m+1];
    char hintAr[n+1][m+1];
    char answer[n];

    for (i = 0 ; i <= n ; i++){
        ar[i][0] = 0;
        hintAr[i][0] = '|';
    }
    for (i = 0 ; i <= m ; i++){
        ar[0][i] = 0;
        hintAr[0][i] = '-';
    }

    for (i = 1 ; i <= n ; i++){
        for (j = 1; j <= m ; j++){
            if (string1[i-1] == string2[j-1]){ //string index start from 0
                ar[i][j] = ar[i-1][j-1] + 1;
                hintAr[i][j] = '\\';
            }
            else if (ar[i-1][j] >= ar[i][j-1]){
                ar[i][j] = ar[i-1][j];
                hintAr[i][j] = '|';

            }
            else {
                ar[i][j] = ar[i][j-1];
                hintAr[i][j] = '-';
            }
        }
    }

    for (i = 0 ; i <= n ; i++){
        for (j = 0 ; j <= m ; j++){
            printf("%d " , ar[i][j]);
        }
        printf("\n");
    }

    for (i = 0 ; i <= n ; i++){
        for (j = 0 ; j <= m ; j++){
            printf("%c " , hintAr[i][j]);
        }
        printf("\n");
    }

    i = n;
    j = m;
    while (i != 0 || j != 0){
        if (hintAr[i][j] == '\\'){
            answer[k] = string1[i-1]; //string start from index 0
            k++;
            i--;
            j--;

        }
        else if (hintAr[i][j] == '|'){
            i--;
        }
        else {
            j--;
        }
    }

    for (i = k-1 ; i >= 0 ; i--){
            printf("%c " , answer[i]);
        }


    return ar[n][m];
}

