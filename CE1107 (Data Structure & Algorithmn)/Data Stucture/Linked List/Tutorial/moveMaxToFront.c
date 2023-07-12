#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode ;

typedef struct _linkedlist
{
    ListNode *head;
    int size;
} LinkedList;



int moveMaxToFront(ListNode **ptrHead);
int moveMaxToBack(ListNode **ptrHead);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode * findNode(LinkedList *ll , int index);
int insertNode(LinkedList *ll , int index , int item);
int removeNode(LinkedList *ll , int index);

int main()
{
    int c ,i , j;
    c = 1;
    LinkedList ll;
    ll.head = NULL;
    ll.size = 0;

    printf("1: Insert an integer to the linked list:\n");
    printf("2: Move the largest stored value to the front of the list:\n");
    printf("3: Move the largest stored value to the back of the list:\n");
    printf("0: Quit:\n");

    while (c != 0){
        printf("Please input your choice(1/2/3/4/0): ");
        scanf("%d" , &c);

        switch(c)
        {
        case 1:
            printf("Input an integer that you want to add to the linked list:" );
            scanf("%d" , &i);
            j = insertNode(&ll , ll.size , i);
            printf("The resulting linked list is: ");
            printList(&ll);
            break;
        case 2:
            moveMaxToFront(&(ll.head));
            printf("The resulting linked list after moving largest stored value to the front of the list is: ");
            printList(&ll);
            removeAllItems(&ll);
            break;
        case 3:
            moveMaxToBack(&(ll.head));
            printf("The resulting linked list after moving the largest stored value to the back of the list is:");
            printList(&ll);
            removeAllItems(&ll);
            break;
        case 4:
            printf("Input the index of the integer that you want to remove from the linked list:");
            scanf("%d" , &i);
            j = removeNode(&ll , i);
            printf("The resulting linked list is: ");
            printList(&ll);
            break;
        case 0:
            removeAllItems(&ll);
            break;
        default:
            printf("Choice unknown!\n");
            break;
        }
    }
    return 0;
}

void printList(LinkedList *ll)
{
    ListNode *temp;
    if (ll->size < 0){
        return NULL;
    }
    temp = ll->head;
    if (temp == NULL){
        printf("Empty List!");
    }
    while (temp != NULL){
        printf("%d " , temp->item);
        temp = temp->next;
    }
    printf("\n");
}

void removeAllItems(LinkedList *ll)
{
    ListNode *temp;
    if (ll == NULL){
        return NULL;
    }
    if (ll->head == NULL){
        return NULL;
    }
    while (ll->head != NULL){
        temp = ll->head->next;
        free(ll->head);
        ll->head = temp;
    }
    ll->head = NULL;
    ll->size = 0;
}

ListNode * findNode(LinkedList *ll , int index)
{
    ListNode *temp;
    if (ll == NULL || index < 0 || index >= ll->size){
        return NULL;
    }
    temp = ll->head;
    if (temp == NULL || index < 0){
        return NULL;
    }

    while (index > 0){
        temp = temp->next;
        if (temp == NULL){
            return NULL;
        }
        index--;
    }
    return temp;
}

int insertNode(LinkedList *ll , int index , int item)
{
    ListNode *pre , *cur;
    if (ll == NULL || index < 0 || index > ll->size +1){
        return -1;
    }
    if (ll->head == NULL || index == 0){
        cur = ll->head;
        ll->head = malloc(sizeof(ListNode));
        ll->head->item = item;
        ll->head->next = cur;
        ll->size++;
        return 0;
    }

    if((pre = findNode(ll , index - 1)) != NULL){
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = item;
        pre->next->next = cur;
        ll->size++;
        return 0;
    }
    return -1;
}

int removeNode(LinkedList *ll , int index)
{
    ListNode *pre , *cur;
    if (ll == NULL || index >= ll->size - 1 || index < 0){
        return NULL;
    }
    if (ll->head == NULL || index < 0){
        return NULL;
    }
    if (index == 0){
        cur = ll->head;
        ll->head = ll->head->next;
        free(cur);
        cur = ll->head;
        ll->size--;
    }

    if ((pre = findNode(ll , index-1)) != NULL){
        if (pre->next == NULL){
            return NULL;
        }
        cur = pre->next;
        pre->next = cur->next;
        free(cur);
        ll->size--;
        return 0;
    }

}

int  moveMaxToFront(ListNode **ptrHead)
{
     int maxitem;
    ListNode *cur , *pre , *preMax;
    if ((*ptrHead) == NULL){
        return -1;
    }

    cur = (*ptrHead);
    pre = NULL;
    preMax = NULL;
    maxitem = cur->item;

    while (cur != NULL){
        if (cur->item > maxitem){
            maxitem = cur->item;
            preMax = pre;
        }
        pre = cur;
        cur = cur->next;
    }

    if (preMax == NULL){
        return -1;
    }
    else {
        cur = preMax->next;
        preMax->next = preMax->next->next;
        cur->next = (*ptrHead);
        (*ptrHead) = cur;
        return 1;
    }


}

int moveMaxToBack(ListNode **ptrHead)
{
    ListNode *cur , *pre , *preMax , *tail;
    int maxitem;
    if ((*ptrHead) == NULL){
        return -1;
    }

    cur = (*ptrHead);
    tail = (*ptrHead);
    while (tail->next != NULL){
        tail = tail->next;
    }
    pre = NULL;
    preMax = NULL;
    maxitem = cur->item;
    while (cur != NULL){
        if (cur->item > maxitem){
            maxitem = cur->item;
            preMax = pre;
        }
        pre = cur;
        cur = cur->next;
    }

    if (preMax == NULL){
        return -1;
    }
    else {
        cur = preMax->next;
        preMax->next = preMax->next->next;
        tail->next = cur;
        tail->next->next = NULL;
        return -1;
    }
}
