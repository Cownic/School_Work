#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode
{
	int item;
	struct _listnode *next;
} ListNode;			// You should not change the definition of ListNode

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} LinkedList;			// You should not change the definition of LinkedList


void pairwiseSwap(LinkedList *ll);
void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

int main()
{
    int x;
	LinkedList ll;
	//Initialize the linked list 1 as an empty linked list
	ll.head = NULL;
	ll.size = 0;


  insertNode(&ll , 0 , 1);
  insertNode(&ll , 1 , 2);
  insertNode(&ll , 2 , 3);
  insertNode(&ll , 3 , 4);
  insertNode(&ll , 4 , 5);
  insertNode(&ll , 5 , 6);
  printf("The LinkedList is: \n");
  printList(&ll);
  printf("\n");
  pairwiseSwap(&ll);
  printList(&ll);

  return 0;
}

void pairwiseSwap(LinkedList *ll)
{
    int temp;
    ListNode *cur;
    if (ll == NULL || ll->head == NULL){
        return;
    }

    cur = ll->head;

    while (cur != NULL && cur->next != NULL){
        temp = cur->item;
        cur->item = cur->next->item;
        cur->next->item = temp;
        cur = cur->next->next;
    }
}


void printList(LinkedList *ll)
{
    ListNode *temp;
    if (ll == NULL){
        return ;
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
    ListNode *cur;
    if (ll == NULL){
        return;
    }
    if (ll->head != NULL){
        temp = ll->head->next;
        free(ll->head);
        ll->head = temp;
    }
    ll->head = NULL;
    ll->size = 0;

}


ListNode *findNode(LinkedList *ll, int index)
{
    ListNode *cur;
    if (ll == NULL || index < 0 || index > ll->size){
        return NULL;
    }
    cur = ll->head;
    if (cur == NULL || index < 0){
        return NULL;
    }

    while (index > 0){
        cur = cur->next;
        if (cur == NULL){
            return NULL;
        }
        index--;
    }
    return cur;
}

int insertNode(LinkedList *ll, int index, int value)
{
    ListNode *pre , *cur;
    if (ll == NULL || index < 0 || index > ll->size){
        return 0;
    }

    if (ll->head == NULL || index == 0){
        cur = ll->head;
        ll->head = malloc(sizeof(ListNode));
        ll->head->item = value;
        ll->head->next = cur;
        ll->size++;
        return 0;
    }

    if ((pre = findNode(ll , index-1)) != NULL){
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = value;
        pre->next->next = cur;
        ll->size++;
        return 0;
    }
    return -1;
}


int removeNode(LinkedList *ll, int index)
{
    ListNode *pre , *cur;

    if (ll == NULL || index < 0 || index >= ll->size ){
        return -1;
    }

    if(ll->head == NULL || index == 0){
        cur = ll->head->next;
        free(ll->head);
        ll->head = cur;
        ll->size--;
        return 0;
    }

    if ((pre = findNode(ll , index-1))!= NULL){
        if (pre->next == NULL){
            return -1;
        }
        cur = pre->next;
        pre->next = cur->next;
        free(cur);
        ll->size--;
        return 0;
    }

    return -1;
}