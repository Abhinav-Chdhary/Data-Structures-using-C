/*
Abhinav Choudhary
B.tech CST
3rd Sem
uni roll: 21021726
class roll: 49

10.Write a C program to implement DFS.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
}nodetype;

typedef struct Graph {
    int numVertices;
    int* visited;

    nodetype** adjLists;
}graphtype;
// Create a node
nodetype* createNode(int v) {
    struct node* p = (nodetype*)malloc(sizeof(nodetype));
    p->vertex = v;
    p->next = NULL;
    return p;
}
// DFS algo
void DFS(struct Graph* graph, int vertex) {
    struct node* adjList = graph->adjLists[vertex];
    struct node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
        DFS(graph, connectedVertex);
    }
    temp = temp->next;
    }
}
// Create graph
graphtype* createGraph(int vertices){
    graphtype* graph = (graphtype*)malloc(sizeof(graphtype));
    graph->numVertices = vertices;
    graph->adjLists = (nodetype*)malloc(vertices * sizeof(nodetype*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge
void addEdge(graphtype* graph, int src, int dest){
    // Add edge from src to dest
    nodetype* p = createNode(dest);
    p->next = graph->adjLists[src];
    graph->adjLists[src] = p;

    // Add edge from dest to src
    p = createNode(src);
    p->next = graph->adjLists[dest];
    graph->adjLists[dest] = p;
}

// Print the graph
void printGraph(graphtype* graph){
    int v;
    for (v = 0; v < graph->numVertices; v++){
    nodetype* temp = graph->adjLists[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
    }
}

int main() {
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);

    DFS(graph, 2);

    return 0;
}