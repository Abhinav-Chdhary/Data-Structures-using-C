//linked-array-list representation of graph
//!!INCOMPLETE!!
//program to perform basic operations of a binary search tree
#include <stdio.h>
#include <stdlib.h>

typedef struct graphNode{
    int data;
    struct graphNode *link;
}graphtype;
typedef struct linkNode{
    int link;
    struct linkNode *next;
}linktype;

//create a Node list
graphtype* createList(int n){
    graphtype* p = (graphtype*)malloc(sizeof(graphtype)*n);
    return p;
}
//function to add values to graph
void addNodes(graphtype* graph, int n){
    printf("Enter data to be added:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &((graph+i)->data));
        (graph+i)->link = NULL;
    }
}
//function to add Edge
//void addEdge(*linktype, )
//function to add Edges to Nodes of graph
void createEdges(graphtype* graph, int n){
    for(int i=0; i<n; i++){
        int x, ch;
        printf("Enter the nodes, node %d is connected to, enter -1 to stop:", i+1);
        do{
            scanf("%d", &x);
            //addEdge
        }while(x!=-1);
    }
}
void display(graphtype* graph, int n){
    for(int i=0; i<n; i++){
        printf("%d ", (graph+i)->data);
    }
}

int main() {
    int ch;
    const int n;
    printf("Enter no. of nodes\n");
    scanf("%d", &n);
    graphtype* graph = createList(n);
    //printf("%d", sizeof(graph));
    
    addNodes(graph, n);
    display(graph, n);

    return 0;
}
