#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 200 // The number digit limitation

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode; // You should not change the definition of BTNode

typedef struct _node
{
    BTNode *item;
    struct _node *next;
} StackNode;

typedef struct _stack
{
    int size;
    StackNode *head;
} Stack;

void deleteTree(BTNode **root);

void createExpTree(BTNode **root, char *prefix);
void printTree(BTNode *node);
void printTreePostfix(BTNode *node);
double computeTree(BTNode *node);

void push(Stack *sPtr, BTNode *item);
int pop(Stack *sPtr);
BTNode *peek(Stack s);
int isEmptyStack(Stack s);

BTNode *createNode(int item);
int isOperator(char input);

int main()
{
    char prefix[SIZE];
    BTNode *root = NULL;

    // printf("Enter an prefix expression:\n");
    gets(prefix);

    createExpTree(&root, prefix);

    // printf("The Infix Expression:\n");
    printTree(root);
    printf("\n");
    // printf("The Postfix (Reverse Polish) Expression:\n");
    printTreePostfix(root);
    printf("\n");
    // printf("Answer ");
    printf("%.2f\n", computeTree(root));
    deleteTree(&root);
    return 0;
}

BTNode *createNode(int item)
{
    BTNode *newNode = malloc(sizeof(BTNode));
    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isOperator(char input)
{
    if (input == '*' || input == '/' || input == '+' || input == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void createExpTree(BTNode **root, char *prefix)
{

    int i;
    int sum;
    int ten = 10;
    BTNode *newNode;
    Stack s;
    s.head = NULL;
    s.size = 0;
    if (isdigit(prefix[i]))
    {
        (*root) = createNode(prefix[i] - '0');
        return;
    }
    else
    {
        (*root) = createNode(prefix[i]);
        i++;
    }
    push(&s, (*root));

    while (prefix[i] != '\0')
    {
        if (isdigit(prefix[i]))
        {
            if (isEmptyStack(s))
            {
                break;
            }
            sum = prefix[i] - '0';
            i++;
            while (isdigit(prefix[i]))
            {
                sum = (sum * ten) + prefix[i] - '0';
                ten = ten * 10;
                i++;
                if (prefix[i] == '\0')
                {
                    break;
                }
            }
            newNode = createNode(sum);
            sum = 0;
            ten = 10;
            BTNode *parent = peek(s);
            if (parent->left == NULL)
            {
                parent->left = newNode;
            }
            else
            {
                parent->right = newNode;
                pop(&s);
            }
        }
        else if (isOperator(prefix[i]))
        {
            newNode = createNode(prefix[i]);
            if (isEmptyStack(s))
            {
                push(&s, newNode);
            }
            else
            {
                BTNode *parent = peek(s);
                if (parent->left == NULL)
                {
                    parent->left = newNode;
                }
                else
                {
                    parent->right = newNode;
                    pop(&s);
                }
                push(&s, newNode);
            }
            i++;
        }
        else if (prefix[i] == ' ')
        {
            i++;
            continue;
        }
    }

    /*
     int i = 0;
    int sum;
    int ten = 10;
    Stack s;
    s.head = NULL;
    s.size = 0;
    if (*prefix == '\0'){
        return;
    }
    reverse(prefix);
    printf("%s \n" , prefix);
    while (prefix[i] != '\0'){
        if (isdigit(prefix[i])){
            sum = prefix[i] - '0';
            printf("%d " , sum);
            i++;
            while (isdigit(prefix[i])){
                sum = sum * ten + (prefix[i]-'0');
                ten = ten * 10;
                i++;
                if (prefix[i] == '\0'){
                    break;
                }
            }
            BTNode *newNode = createNode(sum);
            push(&s , newNode);
            sum = 0;
            ten = 10;
        }
        else if (prefix[i] == ' '){
            i++;
            continue;
        }
        else if (isOperator(prefix[i])) {
            BTNode *newNode = createNode(prefix[i]);
            BTNode *left = peek(s);
            pop(&s);
            BTNode *right = peek(s);
            pop(&s);
            newNode->left = left;
            newNode->right = right;
            push(&s , newNode);
            i++;
        }
    }
    (*root) = peek(s);
    */
}

void printTree(BTNode *node)
{
    BTNode *tmp = node;
    if (node == NULL)
    {
        return;
    }
    else
    {
        printTree(tmp->left);
        if (isOperator(tmp->item))
        {
            printf("%c ", (tmp->item));
        }
        else
        {
            printf("%d ", tmp->item);
        }
        printTree(tmp->right);
    }
}

void printTreePostfix(BTNode *node)
{
    BTNode *tmp = node;
    if (node == NULL)
    {
        return;
    }
    else
    {
        printTreePostfix(tmp->left);
        if (!isOperator(tmp->item))
        {
            printf("%d ", tmp->item);
        }
        printTreePostfix(tmp->right);
        if (isOperator(tmp->item))
        {
            printf("%c ", (tmp->item));
        }
    }
}

double computeTree(BTNode *node)
{
    double left, right;
    double sum = 0.00;
    BTNode *tmp = node;
    if (tmp == NULL)
    {
        return 0.00;
    }
    else
    {
        left = computeTree(tmp->left);
        right = computeTree(tmp->right);

        if (isOperator(tmp->item))
        {
            switch (tmp->item)
            {
            case '*':
                return left * right;
                break;
            case '/':
                return left / right;
                break;
            case '+':
                return left + right;
                break;
            case '-':
                return left - right;
                break;
            default:
                return 0.000000000000000;
            }
        }
        return tmp->item;
    }
}

void push(Stack *sPtr, BTNode *item)
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

BTNode *peek(Stack s)
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

void deleteTree(BTNode **root)
{
    BTNode *temp;
    if (*root != NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}