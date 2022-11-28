//linked-array-list representation of graph
#include <stdio.h>
#include <stdlib.h>

typedef struct graphNode{
    int data;
    struct graphNode *next;
}graphtype;
typedef struct linkNode{
    struct graphNode *head;
}linktype;

//function to add values to graph
void addNodes(graphtype* graph, int n){
    printf("Enter data to be added:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &((graph+i)->data));
        (graph+i)->next = NULL;
    }
}
//function to add Edge
void addEdge(graphtype** head, int x){
    graphtype* p = (graphtype*)malloc(sizeof(graphtype));
    p->data = x;
    p->next = *head;
    *head = p;
}
//function to add Edges to Nodes of graph
void createEdges(graphtype* graph, int n){
    for(int i=0; i<n; i++){
        int x;
        printf("Enter the index of nodes, node %d is connected to, enter -1 to stop:", i+1);
        do{
            scanf("%d", &x);
            if(x!=-1)
                addEdge(&((graph+i)->next), x-1);
        }while(x!=-1);
    }
}
void display(graphtype* graph, int n){
    for(int i=0; i<n; i++){
        printf("%d ", (graph+i)->data);
        graphtype* temp = (graph+i)->next;
        while(temp!=NULL){
            printf("->%d ", temp->data+1);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int num;
    printf("Enter the number of nodes: ");
    scanf("%d", &num);
    const int n = num;
    graphtype* graph = (graphtype*)malloc(sizeof(graphtype)*n);
    //printf("%d", sizeof(graph));
    
    addNodes(graph, n);
    createEdges(graph, n);
    display(graph, n);

    return 0;
}
/*
Enter the number of nodes: 5
Enter data to be added:
78 60 29 50 49
Enter the index of nodes, node 1 is connected to, enter -1 to stop:5 2 -1
Enter the index of nodes, node 2 is connected to, enter -1 to stop:3 -1
Enter the index of nodes, node 3 is connected to, enter -1 to stop:-1
Enter the index of nodes, node 4 is connected to, enter -1 to stop:3 1 -1
Enter the index of nodes, node 5 is connected to, enter -1 to stop:2 4 -1
78 ->2 ->5 
60 ->3 
29 
50 ->1 ->3 
49 ->4 ->2 
*/
