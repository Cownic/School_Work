#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode; // You should not change the definition of ListNode

typedef struct _linkedlist
{
    int size;
    ListNode *head;
} LinkedList; // You should not change the definition of LinkedList

//////////////////////// function prototypes /////////////////////////////////////

// You should not change the prototype of this function
void moveOddItemsToBack(LinkedList *ll);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

//////////////////////////// main() //////////////////////////////////////////////

int main()
{
    LinkedList ll;
    int c, i, j;
    c = 1;
    //Initialize the linked list 1 as an empty linked list
    ll.head = NULL;
    ll.size = 0;

    printf("1: Insert an integer to the linked list:\n");
    printf("2: Move all odd integers to the back of the linked list:\n");
    printf("0: Quit:\n");

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
            moveOddItemsToBack(&ll); // You need to code this function
            printf("The resulting linked list after moving odd integers to the back of the linked list is: ");
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

void moveOddItemsToBack(LinkedList *ll)
{
    ListNode *cur;
    int index = 0;
    int size = ll->size;
    if (ll == NULL || ll->head == NULL)
    {
        return;
    }
    cur = ll->head;
    while (size > 0)
    {
        if (cur->item % 2 != 0)
        {
            insertNode(ll, ll->size, cur->item);
            cur = cur->next;
            removeNode(ll, index);
        }
        else
        {
            index++;
            cur = cur->next;
        }
        size--;
    }
}

void printList(LinkedList *ll)
{
    ListNode *temp;
    if (ll == NULL)
    {
        return NULL;
    }

    temp = ll->head;
    if (temp == NULL)
    {
        printf("Empty List!");
    }

    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

void removeAllItems(LinkedList *ll)
{
    ListNode *temp;
    ListNode *cur;
    if (ll == NULL)
    {
        return NULL;
    }
    if (ll->head != NULL)
    {
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
    if (ll == NULL || index < 0 || index > ll->size)
    {
        return NULL;
    }
    cur = ll->head;
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

int insertNode(LinkedList *ll, int index, int value)
{
    ListNode *pre, *cur;
    if (ll == NULL || index < 0 || index > ll->size)
    {
        return NULL;
    }

    if (ll->head == NULL || index == 0)
    {
        cur = ll->head;
        ll->head = malloc(sizeof(ListNode));
        ll->head->item = value;
        ll->head->next = cur;
        ll->size++;
        return 0;
    }

    if ((pre = findNode(ll, index - 1)) != NULL)
    {
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
    ListNode *pre, *cur;

    if (ll == NULL || index < 0 || index >= ll->size)
    {
        return -1;
    }

    if (ll->head == NULL || index == 0)
    {
        cur = ll->head->next;
        free(ll->head);
        ll->head = cur;
        ll->size--;
        return 0;
    }

    if ((pre = findNode(ll, index - 1)) != NULL)
    {
        if (pre->next == NULL)
        {
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
