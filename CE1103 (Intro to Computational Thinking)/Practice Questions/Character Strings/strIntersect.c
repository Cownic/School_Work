/* (strIntersect) Write the C function that takes in three strings str1, str2 and str3 as parameters,
stores the same characters that appeared in both str1 and str2 into the string, and returns str3 to the
calling function via call by reference. For example, if str1 is "abcdefghijk" and str2 is
"123i4bc78h9", then str3 is "bchi" will be returned to the calling function after executing the
function. If there is no common characters in the two strings, str3 will be a null string. You may
assume that each string contains unique characters, i.e. the characters contained in the same string will not
be repeated*/

#include <stdio.h>
void strIntersect(char *str1, char *str2, char *str3);
int main()
{
    char str1[50], str2[50], str3[50];

    printf("Enter str1: \n");
    scanf("%s", str1);
    printf("Enter str2: \n");
    scanf("%s", str2);
    strIntersect(str1, str2, str3);
    if (*str3 == '\0')
        printf("strIntersect(): null string\n");
    else
        printf("strIntersect(): %s\n", str3);
    return 0;
}
void strIntersect(char *str1, char *str2, char *str3)
{
    int i , j ;
    int k = 0;
    for (i = 0 ; str1[i] != '\0' ; i++){
        j = 0;
        while (str2[j] != '\0'){
            if (str1[i] == str2[j]){
                str3[k++] = str1[i];
                break;
            }
            j++;
        }
    }
    str3[k] = '\0';
}