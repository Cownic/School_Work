//////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//////////////////////////////////   linked list //////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
	int size;
	ListNode *head;
	ListNode *tail;
} LinkedList;

////////////////////////////////// stack    //////////////////////////////////////////////
typedef struct stack{
	LinkedList ll;
} Stack;

//////////////////////////////////// queue ////////////////////////////////////////////

typedef struct _queue{
	LinkedList ll;
} Queue;

////////////////////////////////////////////////////////////////////////////////
void printList(ListNode *head);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

//////////////////////////////////////////////////

void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

//////////////////////////////////////////////////

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int isEmptyQueue(Queue *s);

///////////////////////////////////////////////////////////////
// four questions

int palindrome(char *word);
int palindrome1(char *word);


//////////////////////////////////////////////////////////////////
/////

int main()
{
	Stack s;
	Queue q;
	int item[] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };
	int i;
	char *word1 = "A man a plan a canal Panama";
	char *word2 = "Superman in the sky";


	//for question 3
	palindrome(word1); //*word1="A man a plan a canal Panama";
	palindrome(word2);// *word2="Superman in the sky";
    palindrome1(word1);
    palindrome1(word2);
	return 0;

}



////////////////////////////////////////////////////////////
//Question 3

int palindrome(char *word)
{
    Stack S;
    Queue Q;
    S.ll.head = NULL;
    S.ll.tail = NULL;
    S.ll.size = 0;
    Q.ll.head = NULL;
    Q.ll.tail = NULL;
    Q.ll.size = 0;
    int i , size;
    for (i = 0 ; i < strlen(word) ; i++){
        if (word[i] != ' '){
            push(&S , toupper(word[i]));
            enqueue(&Q , toupper(word[i]));
        }
    }
    size = S.ll.size / 2;

    while (size > 0){
        if (dequeue(&Q) != pop(&S)){
            printf("The string is not a palindrome!\n");
            return -1;
        }
        size--;
    }
    printf("The string is a palindrome!\n");
    return 0;

}

int palindrome1(char *word)
{
    Stack s1 , s2;
    s1.ll.head = NULL;
    s1.ll.size = 0;
    s1.ll.tail = NULL;
    s2.ll.head = NULL;
    s2.ll.size = 0;
    s2.ll.tail = NULL;

    int i , odd ;
    int count =0;
    for (i = 0 ; word[i] != '\0' ; i++){
        if (word[i] != ' '){
            push(&s1 , tolower(word[i]));
            count++;
        }
    }

    odd = count % 2;
    i = count / 2;

    while (i > 0){
        push(&s2 , pop(&s1));
        i--;
    }

    if (odd){
        pop(&s1);
    }

    while (!isEmptyStack(&s1) && !isEmptyStack(&s2)){
        if (pop(&s1) != pop(&s2)){
            printf("It's not a palindrome!\n");
            return -1;
        }
    }

    printf("It's a palindrome!\n");
    return 0;


}


////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, int item){
	insertNode(&(s->ll), 0, item);
}

int pop(Stack *s){
	int item;

	item = ((s->ll).head)->item;
	removeNode(&(s->ll), 0);
	return item;
}

int peek(Stack *s){
	return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s){
	if ((s->ll).size == 0)
		return 1;
	return 0;
}


////////////////////////////////////////////////////////////////////////////////

void enqueue(Queue *q, int item){
	insertNode(&(q->ll), q->ll.size, item);
}

int dequeue(Queue *q){
	int item;
	item = ((q->ll).head)->item;
	removeNode(&(q->ll), 0);
	return item;
}

int isEmptyQueue(Queue *q){
	if ((q->ll).size == 0)
		return 1;
	return 0;
}



////////////////////////////////////////////////////////////////////////////////

void printList(ListNode *head){

	ListNode *temp = head;

	if (temp == NULL)
		return;

	while (temp != NULL){
		printf("%d ", temp->item);
		temp = temp->next;
	}
	printf("\n");
}

ListNode * findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->tail = ll->head;
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}

	// Inserting as new last node
	if (index == ll->size){
		pre = ll->tail;
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		ll->tail = pre->next;
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));

		if (index == ll->size)
			ll->tail = pre->next;

		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}

int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		if (ll->size == 0)
			ll->tail = 0;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		// Removing the last node, update the tail pointer
		if (index == ll->size - 1){
			ll->tail = pre;
			free(pre->next);
			pre->next = NULL;
		}
		else{
			cur = pre->next->next;
			free(pre->next);
			pre->next = cur;
		}
		ll->size--;
		return 0;
	}

	return -1;
}

