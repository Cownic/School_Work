// Max - heap Data Structure

#include <stdio.h>
#include <time.h>

void printArray(int ar[] , int n);
void swap(int *a , int *b);
void heapify(int ar[] , int size , int i);
void heapSort(int ar[] , int n);

int main()
{
    int ar[] = {10, 34 , 76 , 45 , 2 , 32 , 12 , 9};

    //get the number of elements in the array
    int n = sizeof(ar) / sizeof(ar[0]);

    printf("Array before HeapSort:\n");
    printArray(ar , n);
    printf("\n");

    heapSort(ar , n);

    printf("Sorted Array:\n");
    printArray(ar , n);
    printf("\n");


    return 0;
}

void printArray(int ar[] , int n)
{
    int i;
    for (i = 0 ; i < n ; i++){
        printf("%d " , ar[i]);
    }
}

void swap(int *a , int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapSort(int ar[] , int n)
{
    int i;
    //Building a Max-Heap 
    for(i = n/2 ; i >= 0 ; i--){
        heapify(ar , n , i);
    }

    // HeapSort;
    // as we are arranging in a ascending order using a max heap 
    // the max element will constantly be in ar[0](root) so we swap 
    // from the last element to first element
    for (i = n-1 ; i >= 0 ; i--){
        swap(&ar[0] , &ar[i]);

        //after swapping we screw up the Max-heap 
        // so we call heapify to repair the broken max-heap
        // get highest element at root again 
        // root at position 0
        heapify(ar , i , 0);
    }
}

void heapify(int ar[] , int size , int i)
{
    //making use of the characteristics of a binary complete tree
    //passing in the index of the array and using it to calculate its children , if applicable
    int largest = i;
    int leftSub = (2*i) + 1;
    int rightSub = (2*i) + 2;

    //using the property of the tree structure , if the index is more than 2 times of size
    //it means that we have reach a child node ans we no nid to continue to do fixing anymore
    if (leftSub > size || rightSub > size){
        return;
    }

    //if left subtree is larger then the current root,root will be taken over by left subtree value
    if (leftSub < size && ar[leftSub] > ar[largest]){
        largest = leftSub;
    }
    //if the right subtree is larger than the current root,root will be taken over by right subtree value
    if (rightSub < size && ar[rightSub] > ar[largest]){
        largest = rightSub;
    }

    //swapping of the value and bringing the original value at root down one level to sort again
    if  (largest != i){
        swap(&ar[i] , &ar[largest]);
        heapify(ar , size, largest);
    }
}


