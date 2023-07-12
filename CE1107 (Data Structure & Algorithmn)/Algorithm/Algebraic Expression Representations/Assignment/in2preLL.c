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

typedef struct _stackNode
{
    char item;
    struct _stackNode *next;
} StackNode;

typedef struct _stack
{
    int size;
    StackNode *head;
} Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

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

void in2PreLL(char *infix, LinkedList *inExpLL);
void reverse(char *str);
int precedence(char op);

void printExpLL(LinkedList inExp);

int main()
{
    char infix[SIZE];

    printf("Enter an infix expression:\n");
    gets(infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    in2PreLL(infix, &inExpLL);

    printExpLL(inExpLL);

    removeAllNodes(&inExpLL);
    return 0;
}

void reverse(char *str)
{
    char *tail;
    char tmp;
    if (*str != '\0')
    {
        tail = str + strlen(str) - 1;

        while (str < tail)
        {
            tmp = *str;
            *str++ = *tail;
            *tail-- = tmp;
        }
    }
}

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 1;
    else
        return 0;
}

void in2PreLL(char *infix, LinkedList *inExpLL)
{
    int i = 0;
    int j = 0;
    int ten = 10;
    Stack s;
    s.head = NULL;
    s.size = 0;
    int sum;
    if (*infix == '\0')
    {
        return;
    }
    reverse(infix);
    while (infix[i] != '\0')
    {
        if (isdigit(infix[i]))
        {
            sum = infix[i] - '0';
            i++;
            while (isdigit(infix[i]))
            {

                sum = sum + ten * (infix[i] - '0');
                i++;
                ten = ten * 10;
                if (infix[i] == '\0')
                {
                    break;
                }
            }
            insertNode(inExpLL, sum, OPERAND);
            sum = 0;
            ten = 10;
        }
        else if (infix[i] == ')')
        {

            push(&s, infix[i]);
            i++;
        }
        else if (infix[i] == '+' || infix[i] == '-')
        {
            if (!isEmptyStack(s))
            {
                while (peek(s) == '*' || peek(s) == '/')
                {
                    insertNode(inExpLL, peek(s), OPT);
                    pop(&s);
                    if (isEmptyStack(s))
                    {
                        break;
                    }
                }
            }
            push(&s, infix[i]);
            i++;
        }
        else if (infix[i] == '(')
        {
            while (peek(s) != ')')
            {
                insertNode(inExpLL, peek(s), OPT);
                pop(&s);
            }
            if (peek(s) == ')')
            {
                pop(&s);
            }
            i++;
        }
        else if (infix[i] == '*' || infix[i] == '/')
        {
            push(&s, infix[i]);
            i++;
        }
    }

    while (!isEmptyStack(s))
    {
        insertNode(inExpLL, peek(s), OPT);
        pop(&s);
    }
}

void printExpLL(LinkedList inExpLL)
{
    ListNode *temp = NULL;
    temp = inExpLL.head;
    while (temp != NULL)
    {
        if (temp->type == OPERAND)
            printf(" %d ", temp->item);
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
    {
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

void push(Stack *sPtr, char item)
{
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if (sPtr == NULL || sPtr->head == NULL)
    {
        return 0;
    }
    else
    {
        StackNode *temp = sPtr->head;
        sPtr->head = sPtr->head->next;
        free(temp);
        sPtr->size--;
        return 1;
    }
}

char peek(Stack s)
{
    return s.head->item;
}

int isEmptyStack(Stack s)
{
    if (s.size == 0)
        return 1;
    else
        return 0;
}