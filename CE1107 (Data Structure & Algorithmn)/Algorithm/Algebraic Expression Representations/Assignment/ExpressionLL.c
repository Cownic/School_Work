#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 80 // The size of the array

enum ExpType
{
    OPT,
    OPERAND
};

typedef struct _listnode
{
    int item;
    enum ExpType type;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist
{
    int size;
    ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item, enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList(LinkedList ll);

void expressionLL(char *infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExpLL, int seed);

int main()
{
    char infix[SIZE];

    printf("Enter an infix expression:\n");
    gets(infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    expressionLL(infix, &inExpLL);

    int seed;
    printf("Enter a seed: \n");
    scanf("%d", &seed);
    printExpLL(inExpLL, seed);

    removeAllNodes(&inExpLL);
    return 0;
}
void reverse(char *infix)
{
    int i;
    char temp;
    int length = strlen(infix);
    for (i = 0 ; i < length/2 ; i++){
        temp = infix[i];
        infix[i] = infix[length-1-i];
        infix[length-1-i] = temp;
    }

    printf("%s" , infix);

}
void expressionLL(char *infix, LinkedList *inExpLL)
{
    int i = 0;
    int sum;
    reverse(infix);
    while (infix[i] != '\0'){
        if (isdigit(infix[i])){
            sum = infix[i] - '0'; //shortcut to change a character to a number
            i++;
            while (isdigit(infix[i])){
                sum = (sum * 10) + (infix[i] - '0');
                i++;
                if (infix[i] == '\0'){
                    break;
                }
            }
            insertNode(inExpLL , sum , OPERAND);
            sum = 0;
        }
        else {
            insertNode(inExpLL , infix[i] , OPT);
            i++;
        }
    }
}

void printExpLL(LinkedList inExpLL, int seed)
{
    ListNode *temp = NULL;
    temp = inExpLL.head;
    while (temp != NULL)
    {
        if (temp->type == OPERAND)
            printf(" %d ", temp->item + seed);
        else
            printf(" %c ", (char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type)
{
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if (newNode == NULL)
        exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head = newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr)
{
    if (LLPtr == NULL || LLPtr->size == 0)
    { // Queue is empty or NULL pointer
        return 0;
    }
    else
    {
        ListNode *temp = LLPtr->head;
        LLPtr->head = LLPtr->head->next;

        free(temp);
        LLPtr->size--;
        return 1;
    }
}

int isEmptyLinkedList(LinkedList ll)
{
    if (ll.size == 0)
        return 1;
    else
        return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
    while (deleteNode(LLPtr))
        ;
}