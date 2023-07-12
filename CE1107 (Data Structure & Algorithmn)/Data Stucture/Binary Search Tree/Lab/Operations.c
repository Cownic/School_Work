// Binary search tree is a tree which is sorted. For a given node with a key , all the nodes with key smaller than the given node will be to the left of the subtree and right subtree will be for those with larger ley
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main()
{
    int i = 0;

    BTNode *root = NULL;

    // question 1
    do
    {
        printf("input a value you want to insert(-1 to quit):");

        scanf("%d", &i);
        if (i != -1)
            insertBSTNode(&root, i);
    } while (i != -1);

    // question 2
    printf("\n");
    printBSTInOrder(root);

    // question 3
    if (isBST(root, -1000000, 1000000) == 1)
        printf("It is a BST!\n");
    else
        printf("It is not a BST!\n");

    // question 4
    do
    {
        printf("\ninput a value you want to remove(-1 to quit):");
        scanf("%d", &i);
        if (i != -1)
        {
            root = removeBSTNode(root, i);
            printBSTInOrder(root);
        }
    } while (i != -1);
    return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
    if ((*node) == NULL)
    {
        (*node) = malloc(sizeof(BTNode));
        (*node)->item = value;
        (*node)->right = NULL;
        (*node)->left = NULL;
        return;
    }
    else
    {
        if ((*node)->item > value)
        {
            insertBSTNode(&((*node)->left), value);
        }
        else if ((*node)->item < value)
        {
            insertBSTNode(&((*node)->right), value);
        }
        else
        {
            printf("Already exist in the BST\n");
        }
    }
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
    if (node == NULL)
    {
        return;
    }
    printBSTInOrder(node->left);
    printf("%d ", node->item);
    printBSTInOrder(node->right);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
    int left, right;
    if (node == NULL)
    {
        return 1;
    }

    if (node->item >= max || node->item <= min)
    { // the node's value should belong to (min,max)
        return 0;
    }
    // left node smaller than current node item , so it should have maximum value < current node value
    // right node bigger than current node item , so it should have a minimum value > current node
    isBST(node->left, min, node->item);
    isBST(node->right, node->item, max);

    if (left && right)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{
    BTNode *temp;
    if (node == NULL)
    {
        printf("Cant find the value!\n");
        return NULL;
    }

    if (node->item > value)
    { // going to the left subtree
        node->left = removeBSTNode(node->left, value);
    }
    else if (node->item < value)
    { // going to the right subtree
        node->right = removeBSTNode(node->right, value);
    }
    else
    { // node->item == value
        if (node->left != NULL && node->right != NULL)
        {
            temp = findMin(node->right);                          // find the children node to the current node to be deleted
            node->item = temp->item;                              // replace current node item to the children node item
            node->right = removeBSTNode(node->right, temp->item); // deleting the right node
        }
        else
        {
            temp = node;
            if (node->left != NULL)
            {
                node = node->left; // if got left children , replace the parent position
            }
            else
            {
                node = node->right; // if got right children , replace the parent position
            }
            free(temp);
        }
    }
    return node;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMin(BTNode *p)
{
    if (p == NULL)
    {
        return NULL;
    }

    while (p->left != NULL)
    {
        p = p->left;
    }

    return p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////