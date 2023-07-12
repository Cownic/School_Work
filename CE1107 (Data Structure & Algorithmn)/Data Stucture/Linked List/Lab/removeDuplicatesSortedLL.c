#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
	int size;
	ListNode *head;
} LinkedList;

void removeDuplicatesSortedLL(LinkedList *ll);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll , int index);
int insertNode(LinkedList *ll , int index , int item);
int removeNode(LinkedList *ll , int index);

int main()
{
    LinkedList ll;
	int c, i, j;
	c = 1;

	//Initialize the linked list as an empty linked list
	ll.head = NULL;
	ll.size = 0;

	printf("1: Insert an integer to the linked list:\n");
	printf("2: Remove duplicates from a sorted linked list:\n");
	printf("0: Quit:\n");;

    while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i);
			j = insertNode(&ll, ll.size, i);
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 2:
			removeDuplicatesSortedLL(&ll); // You need to code this function
			printf("The resulting linked list after removing duplicate values from the sorted linked list is: ");
			printList(&ll);
			removeAllItems(&ll);
			break;
		case 0:
			removeAllItems(&ll);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}
	return 0;
}

void removeDuplicatesSortedLL(LinkedList *ll)
{
    ListNode *cur , *temp;
    if (ll == NULL || ll->head == NULL){
        return;
    }
    cur = ll->head;
    while (cur->next != NULL){
        if (cur->item == cur->next->item){
            temp = cur->next;
            cur->next = cur->next->next;
            free(temp);
            ll->size--;
        }
        else { // putting in else so it will keep compring with the first occurence of a number before moving on to the next one
            cur = cur->next;
        }
    }

}

void printList(LinkedList *ll)
{
    ListNode *cur ;
    if (ll == NULL){
        return NULL;
    }
    cur = ll->head;
    if (cur == NULL){
        printf("Empty List!");
    }
    while ( cur != NULL){
        printf("%d " , cur->item);
        if (cur == NULL){
            return NULL;
        }
        cur = cur->next;
    }
    printf("\n");
}

void removeAllItems(LinkedList *ll)
{
    ListNode *temp , *cur;
    cur = ll->head;
    while (cur != NULL){
        temp = cur->next;
        free(cur);
        cur = temp;
    }
    ll->head = NULL;
    ll->size = 0;
}

ListNode * findNode(LinkedList *ll , int index)
{
    ListNode *cur , *pre;
    if (ll == NULL || index < 0 || index >= ll->size){
        return NULL;
    }
    cur = ll->head;
    if (cur == NULL || index < 0){
        return NULL;
    }
    while (index != NULL){
        cur = cur->next;
        if (cur == NULL){
            return NULL;
        }
        index--;
    }
    return cur;
}

int insertNode(LinkedList *ll , int index , int item)
{

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = item;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
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
    if (ll == NULL || index < 0 || index >= ll->size-1){
        return NULL;
    }
    if (ll->head == NULL || index < 0){
        return NULL;
    }
    if (index == 0){
        cur = ll->head;
        pre = cur->next;
        free(cur);
        cur = pre;
        ll->size--;
        return 0;
    }
    if ((pre = findNode(ll , index-1)) != NULL){
        cur = pre->next;
        pre->next = cur->next;
        free(cur);
        ll->size--;
        return 0;
    }
    return -1;
}