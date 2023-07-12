/*Write a C program that prints the ID and grade of each student in a class. The input
contains the student IDs and their marks. The range of the marks is from 0 to 100. The
relationships of the marks and grades are given below:
Grade Mark
A 100‐75
B 74‐65
C 64‐55
D 54‐45
F 44‐0
Use a switch statement for your code below
Use the sentinel value –1 for student ID to indicate the end of user input.*/

#include <stdio.h>

int main(){
    int marks;
    int studentID;
    printf("Please enter your student ID: \n");
    scanf("%d" , &studentID);
    while (studentID != -1){
       printf("Please enter your marks:\n");
       scanf("%d" , &marks);
       switch ((marks + 5) / 10)
       {
        case 10:
        case 9:
        case 8:
            printf("Grade = %c\n" , 'A');
            break;
        case 7:
            printf("Grade = %c\n" , 'B');
                break;
        case 6:
            printf("Grade = %c\n" , 'C');
            break;
        case 5:
            printf("Grade = %c\n" , 'D');
            break;
       default:
            printf("Grade = %c\n" , 'F');
            break;
       }
       printf("Enter your student ID: \n");
       scanf("%d" , &studentID);
    }
    return 0;
}

