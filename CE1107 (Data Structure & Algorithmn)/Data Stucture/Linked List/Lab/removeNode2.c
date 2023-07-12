#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode ;

typedef struct _linkedlist {
    ListNode *head;
    int size;
} LinkedList;

void printList2(LinkedList ll);
ListNode * findNode2(LinkedList ll , int index);
int insertNode2(LinkedList *ll , int item , int index);
int removeNode2(LinkedList *ll , int index);

int main()
{
    LinkedList ll;
    ll.head = NULL;
    ll.size = 0;
    int item;
    int index;

    printf("Enter a list of numbers , terminated by any non-digit character: \n");
    while(scanf("%d" , &item)){
        if(!insertNode2(&ll,ll.size,item)){
            break;
        }
    }

    scanf("%*s");

    printList2(ll);

    while(1) {
        printf("Enter the index of the node to be removed: ");
        scanf("%d" , &index);

        if (!removeNode2(&ll , index)){
            printf("The node cannot be removed.\n");
            break;
        }
        printf("After the removal operation,\n");
        printList2(ll);
    }
    printList2(ll);
    return 0;
}

void printList2(LinkedList ll)
{
    ListNode *cur;
    if (ll.head == NULL){
        printf("Empty LinkedList!\n");
        return;
    }
    else {
        cur = ll.head;
        while (cur != NULL){
            printf("%d " , cur->item);
            cur = cur->next;
        }
        printf("\n");
    }
}

ListNode *findNode2(LinkedList ll , int index)
{
    ListNode *cur;
    if (ll.head == NULL || index < 0 || index > ll.size){
        return NULL;
    }
    else {
        cur = ll.head;
        while (index > 0){
            cur = cur->next;
            if (cur == NULL){
                return NULL;
            }
            index--;
        }
        return cur;
    }

}

int insertNode2(LinkedList *ll , int index , int item)
{
    ListNode *pre , *newNode;

    if (index == 0){
        newNode = ll->head;
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = NULL;
        ll->head = newNode;
        ll->size++;
        return 1;
    }
    else if ((pre = findNode2(*ll , index-1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = pre->next;
        pre->next = newNode;
        ll->size++;
        return 1;
    }
    return 0;   
}

int removeNode2(LinkedList *ll , int index)
{
    ListNode *cur , *pre;
    if (ll == NULL || ll->head == NULL || index > ll->size){
        return 0;
    }

    if (index == 0){
        cur = ll->head->next;
        free(ll->head);
        ll->head = cur;
        ll->size--;
        return 1;
    }
    else {
        if ((pre = findNode2(*ll , index-1)) != NULL){
            cur = pre->next;
            pre->next = pre->next->next;
            free(cur);
            ll->size--;
            return 1;
        }
    }
    return 0;
    
}
