#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int item;
    struct _listnode *next;
    } ListNode;

void printList(ListNode *cur);
ListNode *findNode(ListNode *cur, int index);
int insertNode(ListNode **ptrHead, int index, int item);
int removeNode(ListNode **ptrHead, int index);

int main()
{
    ListNode *head = NULL;
    int size = 0;
    int item;
    int index;

    printf("Enter a list of numbers , terminated by any non-digit character : \n");
    while (scanf("%d" , &item)){
        if(insertNode(&head , size , item)){
            size++;
        }
    }
    scanf("%*s");

    printList(head);

    while(1) {
        printf("Enter the index of the node to be removed: ");
        scanf("%d" , &index);

        if(removeNode(&head , index)){
            size--;
        }
        else{
            printf("The node cannot be removed.\n");
            break;
        }
        printf("After the removal operation,\n");
        printList(head);
    }

    printList(head);
    return 0;
}

void printList(ListNode *cur)
{
    ListNode *head = cur;
    printf("Current List : ");
    if (head == NULL)
    {
        printf("Empty List!");
    }
    while (head != NULL)
    {
        printf("%d ", head->item);
        head = head->next;
    }
    printf("\n");
}

ListNode *findNode(ListNode *cur, int index)
{
    if (cur == NULL || index < 0)
    {
        return NULL;
    }
    while (index > 0)
    {
        cur = cur->next;
        if (cur == NULL)
        {
            return NULL;
        }
        index--;
    }
    return cur;
}

int insertNode(ListNode **ptrHead, int index, int item)
{
    ListNode *pre, *cur;
    if (index == 0)
    {
        cur = *ptrHead; //getting a new pointer to point at where head pointer was pointing to
        *ptrHead  = malloc(sizeof(ListNode)); //create new node with head pointer
        (*ptrHead)->item = item; //inserting value into new node
        (*ptrHead)->next = cur;//getting new node to point to any other pointer that head pointer used to point to
        return 0;

    }
    else if ((pre = findNode(*ptrHead, index-1)) != NULL)
    {
        cur = pre->next; // creating new pointer to point to the next node
        pre->next = malloc(sizeof(ListNode)); // remove connection to the next node by creating a new node
        pre->next->item = item; //load value into new node
        pre->next->next = cur; //connecting new node with next node
        return 1;
    }
    return 0;
}

int removeNode(ListNode **ptrHead ,int index)
{
    ListNode *pre , *cur;
    if (*ptrHead == NULL){
        return -1;
    }

    if (index == 0){
        cur = *ptrHead; // replace the current head pointer pointing at first node
        *ptrHead = cur->next; //getting the pointerhead to point to the second node
        free(cur);
        return 0;
    }
    if((pre = findNode(*ptrHead , index-1)) != NULL){
        cur = pre->next; //cur is now pointing at the node that is going to be removed
        pre->next = cur->next;
        free(cur); //getting the node before to point straight to after node
        return 1;
    }
    return -1;
}


