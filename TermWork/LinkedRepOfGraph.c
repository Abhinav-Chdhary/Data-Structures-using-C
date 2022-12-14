/*
Abhinav Choudhary
B.tech CST
3rd Sem
uni roll: 21021726
class roll: 49
Write a C program to implement linked representation of a
 graph in memory using array of 
 pointers.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct linkNode{
    int dst;
    struct linkNode* next;
}linktype;
typedef struct graphNode{
    int data;
    struct linkNode *head;
}graphtype;

//function to add values to graph
void addNodes(graphtype* graph, int n){
    printf("Enter data to be added:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &((graph+i)->data));
        (graph+i)->head = NULL;
    }
}
//function to add new edges
void addEdge(linktype** head, int x, int destination){
    linktype* p= (linktype*)malloc(sizeof(linktype));
    p->next = *head;
    p->dst = destination;
    *head = p;
}
//function to create edges from a node
void createEdges(graphtype* graph, int n){
    for(int i=0; i<n; i++){
        int ch;
        printf("Enter destinations for %d:\n", (graph+i)->data);
        do{
            printf("continue: 1/0:");
            scanf("%d", &ch);
            if(ch==1){
                int destination;
                scanf("%d", &destination);
                addEdge(&((graph+i)->head), (graph+i)->data, destination);
            }
        }while(ch==1);
    }
}
//function to display the graph
void display(graphtype* graph, int n){
    printf("The graph:\n");
    for(int i=0; i<n; i++){
        printf("%d", (graph+i)->data);
        linktype* temp = (graph+i)->head;
        while(temp!=NULL){
            printf(" --> %d", temp->dst);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int num;
    printf("Enter the number of nodes: ");
    scanf("%d", &num);
    const int n = num;
    graphtype* graph = (graphtype*)malloc(sizeof(graphtype)*n);

    addNodes(graph, n);
    createEdges(graph, n);
    display(graph, n);

    return 0;
}