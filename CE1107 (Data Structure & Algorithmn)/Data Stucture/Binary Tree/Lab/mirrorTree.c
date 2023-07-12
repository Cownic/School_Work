#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void mirrorTree(BTNode *node);
void printTree_InOrder(BTNode *node);

int main()
{
    int i;
    BTNode *root , *root2;
    BTNode btn[15];
    //Create the tree in Q1(mirror tree)
    //Using manual dynamic allocation of memory for BTNode

    root = malloc(sizeof(BTNode));
    root->item = 4;

    root->left = malloc(sizeof(BTNode));
    root->left->item = 5;

    root->right = malloc(sizeof(BTNode));
    root->right->item = 2;

    root->left->left = NULL;

    root->left->right = malloc(sizeof(BTNode));
    root->left->right->item = 6;

    root->left->right->left = NULL;
    root->left->right->right = NULL;

    root->right->left = malloc(sizeof(BTNode));
    root->right->left->item = 3;

    root->right->right = malloc(sizeof(BTNode));
    root->right->right->item = 1;

    root->right->left->left = NULL;

    root->right->left->right = NULL;

    root->right->right->left = NULL;

    root->right->right->right = NULL;

    printTree_InOrder(root);
    printf("\n");
    mirrorTree(root);
    printTree_InOrder(root);
    printf("\n\n");

    return 0;
}

void mirrorTree(BTNode *node)
{
    BTNode *temp;

    if (node == NULL){
        return;
    }
    else {
        mirrorTree(node->left);
        mirrorTree(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

void printTree_InOrder(BTNode *node)
{
    if (node == NULL){
        return;
    }
    else {
        printTree_InOrder(node->left);
        printf("%d, " , node->item);
        printTree_InOrder(node->right);
        return;
    }
}
