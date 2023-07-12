#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 80 //The limit of expression length

typedef struct _stackNode{
    double item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, double item);
int pop(Stack *sPtr);
double peek(Stack s);
int isEmptyStack(Stack s);

double exePostfix(char*);

int main()
{
    char postfix[SIZE];

    printf("Enter a postfix expression:\n");
    gets(postfix);

    printf("The answer is %.2lf.\n",exePostfix(postfix));

    return 0;
}


double exePostfix(char* postfix)
{
	// Write your code here
    Stack s;
    s.head = NULL;
    s.size = 0;
    int i = 0;
    double A , B;
    while (postfix[i] != '\0'){
        if (isdigit(postfix[i])){
            push(&s , postfix[i] - '0');
        }
        else { // A is behind of B in the actul expression , so we should do B sth A
            A = peek(s);
            pop(&s);
            B = peek(s);
            pop(&s);
            if (postfix[i] == '*'){
                push(&s , B*A);
            }
            else if (postfix[i] == '/'){
                push(&s , B/A);
            }
            else if (postfix[i] == '+'){
                push(&s , B+A);
            }
            else if (postfix[i] == '-'){
                push(&s , B-A);
            }
        }
        i++;
    }

    return peek(s);
}

void push(Stack *sPtr, double item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

double peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}