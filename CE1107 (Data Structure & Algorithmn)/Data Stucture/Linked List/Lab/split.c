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
void deleteList(ListNode **ptrHead);
int split(ListNode *cur, ListNode **ptrHead, ListNode **ptrOddList);

int main()
{
    ListNode *head = NULL;
    ListNode *oddHead = NULL;
    ListNode *evenHead = NULL;

    int size = 0;
    int item;

    printf("Enter a list of numbers , terminated by a non-digit character: \n");
    while (scanf("%d ", &item))
    {
        if (insertNode(&head, size, item))
        {
            size++;
        }
    }
   scanf("%*s");

    printf("\nBefore split() is called:\n");
    printf("The original list: \n");
    printList(head);

    split(head, &evenHead, &oddHead);

    printf("\nAfter split() was called:\n");
    printf("The original list:\n");
    printList(head);
    printf("The even list:\n");
    printList(evenHead);
    printf("The odd list:\n");
    printList(oddHead);

    if (head != NULL)
    {
        deleteList(&head);
    }
    if (oddHead != NULL)
    {
        deleteList(&oddHead);
    }
    if (evenHead != NULL)
    {
        deleteList(&evenHead);
    }
    return 0;
}

void printList(ListNode *cur)
{
    if (cur == NULL)
    {
        return;
    }
    while (cur != NULL)
    {
        printf("%d ", cur->item);
        cur = cur->next;
    }
    printf("\n");
}

ListNode *findnode(ListNode *cur, int index)
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

    if (*ptrHead == NULL || index == 0)
    {
        cur = *ptrHead;
        *ptrHead = malloc(sizeof(ListNode));
        (*ptrHead)->item = item;
        (*ptrHead)->next = cur;
        return 1;
    }
    else if ((pre = findnode(*ptrHead, index - 1)) != NULL)
    {
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = item;
        pre->next->next = cur;
        return 1;
    }
    return 0;
}

void deleteList(ListNode **ptrHead)
{
    ListNode *cur, *temp;
    cur = *ptrHead;

    while (cur != NULL)
    {
        temp = cur->next;
        free(cur);
        cur = temp;
    }
    *ptrHead = NULL;
}

int split(ListNode *cur, ListNode **ptrEvenList, ListNode **ptrOddList)
{
    int even = -1;
    int oddIndex = 0;
    int evenIndex = 0;
    if (cur == NULL)
    {
        return 0;
    }
    while (cur != NULL)
    {
        if (even != 1)
        {
            insertNode(ptrOddList, oddIndex, cur->item);
            oddIndex++;
        }
        else
        {
            insertNode(ptrEvenList, evenIndex, cur->item);
            evenIndex++;
        }
        cur = cur->next;
        even = -even;
    }
}