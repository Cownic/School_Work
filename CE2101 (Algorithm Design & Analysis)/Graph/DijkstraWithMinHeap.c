#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

//Structure to represent a node in adjacency list
struct AdjListNode
{
    int destination;
    int weight;
    struct AdjListNode *next;
};

//structure to represent an adjacency list
struct AdjList
{
    struct AdjList *head;
};


//creating a graph sturcture
//a graph is represented by an array of adjacency list
//size of array == number of vertices in the graph
struct Graph
{
    int vertices;
    struct AdjList *array;
};

//utility function to create a new adjacency list node
struct AdjListNode *newAdjListNode(int destination , int weight){
    struct AdjListNode *newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->weight = weight;
    newNode->destination = destination;
    newNode->next = NULL;
    return newNode;
}


//utility function that creates a graph of V vertices
struct Graph *createGraph(int vertices)
{
    int i;
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->array = (struct AdjList *)malloc(sizeof(struct AdjList) * vertices);


    //initialising each of the adjacency list for each node
    for (i = 0 ; i < vertices ; i++){
        graph->array[i].head = NULL;
    }
    return graph;
}

//adding of an edge to an directed/ undirected graph

void addEdge(struct Graph *graph , int source , int destination , int weight)
{
    struct AdjListNode *newNode = newAdjListNode(destination , weight);
    newNode->next  = graph->array[source].head;
    graph->array[source].head = newNode; 

    //if undirected , nid to add weight from destination to source also 
    newNode = newAdjListNode(source , weight);
    newNode->next = graph->array[destination].head;
    graph->array[destination].head = newNode;
}


//a min heap node structure
struct MinHeapNode
{
    int vertex;
    int distance;
};


//structure to represent a min heap structure

struct MinHeap
{
    int size;

    int capacity;


    //This is used in drcreaseKey()
    int *pos;
    struct MinHeapNode **array;
};

//utility function to create a new MinHeap Node

struct MinHeapNode * newMinHeapNode(int vertex , int distance)
{
    struct MinHeapNode *minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->distance = distance;
    minHeapNode->vertex = vertex;

    return minHeapNode;
}

//utility function to create a MinHeap structure
struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(sizeof(int) * capacity);
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

//swapping function to swap 2 nodes in minheap 
void swapMinHeapNode(struct MinHeapNode **a , struct MinHeapNode **b)
{
    struct MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

//standard function of heapify 
//function also update the position of nodes when they are swapped 
//positionh is neede for decreaseKey() later

void minHeapify(struct MinHeap *minHeap , int index)
{
    int smallest , leftchild , rightchild;
    smallest = index;
    leftchild = (2 * index) + 1;
    rightchild = (2 * index) + 1;

    if (leftchild < minHeap->size && minHeap->array[leftchild]->distance < minHeap->array[smallest]->distance){
        smallest = leftchild;
    }

    if (rightchild < minHeap->size && minHeap->array[rightchild]->distance < minHeap->array[smallest]->distance){
        smallest = rightchild;
    }

    //nid do swapping at this point
    if (smallest != index){
        struct MinHeapNode *smallestNode = minHeap->array[smallest];
        struct MinHeapNode *indexNode = minHeap->array[index];

        //swap positions
        minHeap->pos[smallestNode->vertex] = index;
        minHeap->pos[indexNode->vertex] = smallest;

        //swap the nodes physically
        swapMinHeapNode(&minHeap->array[smallest] , &minHeap->array[index]);

        minHeapify(minHeap , smallest);
    }
}

//utility function to check if the given min Heap is empty or not
int isEmpty(struct MinHeap *MinHeap)
{
    return MinHeap->size == 0;
}

struct MinHeapNode *extractMin(struct MinHeap *minHeap)
{
    if (isEmpty(minHeap)){
        return NULL;
    }

    //store the root node
    struct MinHeapNode *root = minHeap->array[0];

    //replace the root with the last node in min heap

    struct MinHeapNode *lastNode = minHeap->array[minHeap->size -1];

    //update the position of last node

    minHeap->pos[root->vertex] = minHeap->size -1;
    minHeap->pos[lastNode->vertex] = 0;

    //reduce heapsize and heapify root
    --minHeap->size;
    minHeapify(minHeap , 0);

    return root;
}

//function used to decrease the dist value of a given vertex
//uses the pos[] of minheap to get the current index of node in minHeap

void decreaseKey(struct MinHeap *minHeap , int v , int dist)
{
    // get the index of the vertex in heap array
    int i = minHeap->pos[v];

    while(i && minHeap->array[i]->distance < minHeap->array[(i-1)/2]->distance){
        //taking over my parent node position if my current distance is lesser than parent
        minHeap->pos[minHeap->array[i]->vertex] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->vertex] = i;

        //swapping the physical nodes
        swapMinHeapNode(&minHeap->array[i] , &minHeap->array[(i-1)/2]);

        //moving on to parent index and continue 
        i = (i-1)/2;
    }
}


//utility function to check if a given vertex is still in minheap anot

bool isInMinHeap(struct MinHeap *minHeap , int v)
{
    if (minHeap->pos[v] < minHeap->size){
        return true;
    }
    return false;
}


//utility function to print the solution

void printArr(int dist[] , int n)
{
    printf("Vertex Distance from Source\n");
    for (int i = 0 ; i < n ; i++){
        printf("%d \t\t %d \n" , i , dist[i]);
    }
}

//main dijkstra alforithm

void dijkstraMinHeap(struct Graph *graph , int source)
{
    //get the number of vertices in the graph
    int V = graph->vertices;


    //keep track of the minimum distance 
    int dist[V];

    //create a minHeap as a priority queue to select an vertex

    struct MinHeap *minHeap = createMinHeap(V);

    //initialise the minheap with all the vertices , dist values of all vertices
    for (int v = 0 ; v < V ; v++){
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v , dist[v]);
        minHeap->pos[v] = v;
    }

    //initialising the source vertex
    minHeap->array[source] = newMinHeapNode(source , dist[source]);
    minHeap->pos[source] = source;
    dist[source] = 0;
    decreaseKey(minHeap , source , dist[source]);

    minHeap->size = V;

    while (!isEmpty(minHeap)){
        //extract the vertex with the minimum distance value
        struct MinHeapNode *minHeapNode = extractMin(minHeap);

        int u = minHeapNode->vertex;

        //trasverse thru all the adjacent vertices of u and update their distance values accordingly
        struct AdjListNode *pCrawl = graph->array[u].head;
        while (pCrawl != NULL){
            int v = pCrawl->destination;

            if (isInMinHeap(minHeap , v) && dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v]){
                dist[v] = dist[u] + pCrawl->weight;

                decreaseKey(minHeap , v , dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    printArr(dist , V);

}


int main()
{
  /*int V , E , i;
    int source , destination , weight;
    printf("Enter the number of vertices you want in the graph: ");
    scanf("%d" , &V);
    struct Graph *graph = createGraph(V);
    printf("Enter the number of edges you want in the graph: ");
    scanf("%d" , &E);

    for (i = 0 ; i < E ; i++){
        int source = 
    }
 */


    // create the graph given in above fugure
    int V = 9;
    struct Graph *graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    dijkstraMinHeap(graph, 0);

    return 0;
}



