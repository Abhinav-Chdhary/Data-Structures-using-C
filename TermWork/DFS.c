/*Q10.
Write a C program to implement DFS.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// define a structure for a graph node
typedef struct Node {
  int data;
  struct Node *next;
}nodetype;

// define a structure for a graph
typedef struct Graph {
  int numNodes;
  struct Node* nodes[MAX_NODES];
}graphtype;

// create a new graph node
nodetype* createNode(int data) {
  nodetype* node = (struct Node*)malloc(sizeof(nodetype));
  node->data = data;
  node->next = NULL;
  return node;
}

// add an edge to the graph
void addEdge(graphtype* graph, int src, int dest) {
  nodetype* newNode = createNode(dest);
  newNode->next = graph->nodes[src];
  graph->nodes[src] = newNode;
}

// perform a depth-first search starting from the given node
void DFS(graphtype* graph, int node, int visited[]) {
  visited[node] = 1;
  printf("%d ", node);

  nodetype* current = graph->nodes[node];
  while (current != NULL) {
    int neighbor = current->data;
    if (!visited[neighbor]) {
      DFS(graph, neighbor, visited);
    }
    current = current->next;
  }
}

int main() {
  // create a graph with 4 nodes
  graphtype* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numNodes = 4;

  // add edges to the graph
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 0);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 3);

  // array to keep track of visited nodes
  int visited[MAX_NODES];
  for (int i = 0; i < MAX_NODES; i++) {
    visited[i] = 0;
  }

  // perform a DFS starting from node 2
  printf("Nodes in the order that they were visited:\n");
  DFS(graph, 2, visited);

  return 0;
}
