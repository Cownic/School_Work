/*Write a C program main() that requests a list of numbers from the user, terminated by a
sentinel value of ‘-1’. After the linked list is built, your program should print all numbers
stored in the linked list. Sample output:
Enter a list of numbers, terminated by the value -1:
1
2
3
4
5
-1
Current list: 1 2 3 4 5*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode {
    int item;
    struct _listnode *next;
} ListNode ;

int searchList (ListNode *head , int value);

void main()
{
    ListNode *cur , *temp , *head;
    int n;
    int result;

    cur = NULL;
    head = NULL;

    printf("Enter a list of numbers ,  terminated by the value -1:\n");
    scanf("%d" , &n);
    while (n != -1){
        if (head == NULL){ // case when the linkedlist is empty
            head = malloc(sizeof(ListNode)); 
            cur = head;
        }
        else {
            cur->next = malloc(sizeof(ListNode));
            cur = cur->next;
        }
        cur->item = n;
        cur->next = NULL;
        scanf("%d" , &n);
    }

    printf("The current list: ");
    cur = head;
    if (cur == NULL){
        printf("Empty List!\n");
        return;
    }
    while (cur != NULL){
        printf("%d " , cur->item);
        cur = cur->next;
    }
    printf("\n");
    //Q3 : Writing a  program to search for a value in the linked list
    printf("Enter value to search for: ");
    scanf("%d" , &n);
    result  = searchList(head , n);
    if (result == -1){
        printf("The value is not found in the array.\n");
    }
    else {
        printf("Value %d found at index %d\n" , n , result);
    }

    //Q4 : Freeing up the allocated memory after using them

    cur = head;
    while (cur != NULL){
        temp = cur->next;
        free(cur);
        cur = temp;
    }
    temp = NULL;
    cur = NULL;
    head = NULL;
}


int searchList(ListNode *head , int value)
{
    ListNode *cur;
    int index;
    if (head == NULL){
        printf("The array is empty!\n");
        return -1;
    }
    cur = head;
    while (cur != NULL){
        if (cur->item == value){
            return index;
        }
        else {
            index++;
        }
        cur = cur->next;
    }
    return -1;
}