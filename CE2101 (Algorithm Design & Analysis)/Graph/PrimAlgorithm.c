//Generate minimun spanning tree for adjacency matrix
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

#define V 5

void primMST(int graph[V][V]);
void printMST(int parent[] , int graph[V][V]);
int minKey(int key[] , bool mstSet[]);


int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    primMST(graph);

    return 0;
}


//extracting the minimum distance in each run of the algorithm
int minKey(int key[] , bool mstSet[])
{
    int i ;
    int minimum = INT_MAX;
    int minimumIndex = INT_MAX;
    for (i = 0 ; i < V ; i++){
        if (mstSet[i] == false && key[i] < minimum){
            minimum = key[i];
            minimumIndex = i;
        }
    }
    return minimumIndex;
}


//print the constructed MST stored in parent[]
void printMST(int parent[] , int graph[V][V])
{
    int i;
    for (i = 1 ; i < V ; i++){
        printf("%d - %d \t%d \n" , parent[i] , i , graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V])
{
    int i;
    //store the minimum spanning tree
    int parent[V];

    //used to pick the minimum weight edge in cut
    int key[V];

    //represent the set of vertices in MST already
    bool MST[V];

    for (i = 0 ; i < V ; i++){
        MST[i] = false;
        key[i] = INT_MAX;
    }


    // update the source vertex
    key[0] = 0;
    parent[0] = -1; //root is initialise as -1

    //assuming graph have V vertices , it will have V-1 edges in a MST
    for (i = 0 ; i < V-1 ; i++){
        int u = minKey(key , MST);

        MST[u] = true;

        for (int v = 0 ; v < V ; v++){
            if (graph[u][v] && MST[v] == false && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent , graph);
}

