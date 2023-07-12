////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////


typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;

} BTNode;

////////////////////////////////////////////////////////////////////


void mirrorTree(BTNode *node);

void printSmallerValues(BTNode *node, int m);
int smallestValue(BTNode *node);
int hasGreatGrandchild(BTNode *node);

void printTree_InOrder(BTNode *node);

////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[])
{

    int i;
    BTNode *root, *root2;
    BTNode btn[15];

    // Using manual dynamic allocation of memory for BTNodes

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



    //question 3
    printf("The smallest value in the tree is %d\n", smallestValue(root));


}



int smallestValue(BTNode *node)
{
    int middle , left , right;
    if (node == NULL){
        return 10000;
    }
    else {
        middle = node->item;
        left = smallestValue(node->left);
        right = smallestValue(node->right);
        if (left < middle && left < right){
            return left;
        }
        else if(right < middle && right < left){
            return right;
        }
        else {
            return middle;
        }
    }
}


//////////////////////////////////////////////////////////////////

void printTree_InOrder(BTNode *node)
{

    if (node == NULL) return;
    printTree_InOrder(node->left);
    printf("%d, ", node->item);
    printTree_InOrder(node->right);
    return;
}