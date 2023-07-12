#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

int hasGreatGrandchild(BTNode *node);
void printTree_InOrder(BTNode *node);

int main(int argc, const char *argv[])
{
    int i;
    //char reply

    BTNode *root, *root2;
    BTNode btn[15];
    //Question 4 hasGreatGrandchildren
    //Create a tree tall enough so some nodes have great-grand children
    //Use array of BTNodes , create tree by linking the nodes together

    for (i = 0; i <= 6; i++)
    {
        btn[i].item = i;
        btn[i].left = &(btn[i * 2 + 1]);
        btn[i].right = &(btn[i * 2 + 2]);
    }

    for (i = 7; i <= 14; i++)
    {
        btn[i].item = i;
        btn[i].left = NULL;
        btn[i].right = NULL;
    }
    root2 = &btn[0];

    printf("The tree for question 4 visited by in-order is \n");
    printTree_InOrder(root2);
    printf("\nthe values stored in all nodes of the tree that have at least one great-grandchild are: ");

    hasGreatGrandchild(root2);

    return 0;
    //printf("\nenter any key to exit:");
    //fflush(stdin);
    //scanf("%c", &reply);
}

int hasGreatGrandchild(BTNode *node)
{
    int l , r;
    if (node == NULL){
        return 0;
    }
    else {
        l = hasGreatGrandchild(node->left);
        r = hasGreatGrandchild(node->right);
        if (r > l){
            l = r;
        }
        if (l > 2){
            printf("%d, " , node->item);
        }
        return l + 1;
    }
}

void printTree_InOrder(BTNode *node)
{
    if (node == NULL){
        return NULL;
    }
    else {
        printTree_InOrder(node->left);
        printTree_InOrder(node->right);
        printf("%d, " , node->item);
        return;
    }
}