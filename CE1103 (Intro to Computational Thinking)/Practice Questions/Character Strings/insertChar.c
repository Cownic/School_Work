/*(insertChar) Write the C function that takes in a string str1 as an argument, copies the contents of
character string str1 into character string str2. In addition, the function also has a character
parameter ch. For every three characters copied from str1 to str2, the character ch is inserted
into str2. The function returns the resultant string to the calling function via call by reference. For
example, if the string str1 is "abcdefg", and the inserted character ch is ‘#’, then the resultant
string str2 = "abc#def#g" will be returned to the calling function.*/

#include <stdio.h>
#include <string.h>
void insertChar(char *str1, char *str2, char ch);
int main()
{
    char a[80], b[80];
    char ch, *p;

    printf("Enter a string: \n");
    fgets(a, 80, stdin);
    if (p = strchr(a, '\n'))
    {
        *p = '\0';
    }
    printf("Enter the character to be inserted: \n");
    ch = getchar();
    insertChar(a, b, ch);
    printf("insertChar(): ");
    puts(b);
    return 0;
}

void insertChar(char *str1, char *str2, char ch)
{
    int count = 0;
    while (*str1 != '\0')
    {
        *str2++ = *str1++;
        count++;
        if (count == 3)
        {
            *str2++ = ch;
            count = 0;
        }
    }
     *str2 = '\0';

     //using indexing approach
    /*str2 = '\0'; 
    int count = 0;
    int j = 0;
    int i;
   for (i = 0 ;str1[i] != '\0' ; i++){
       str2[j] = str1[i];
       j++;
       count++;
       if (count == 3 && str1[i] != '\0'){
           str2[j] = ch;
           j++;
           count = 0;
       }
   }
    str2[j] = '\0';
    */
}