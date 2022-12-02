//Enter a weighted graph, and arrange the weights in ascending order
#include <stdio.h>
#include <stdlib.h>

typedef struct linkNode{
    int src, dst, wt;
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
//function to add Edge
void addEdge(linktype** head, int src, int dst, int wt){
    linktype* p = (linktype*)malloc(sizeof(linktype));
    p->src = src;
    p->dst = dst;
    p->wt = wt;
    p->next = NULL;
    
    if(head==NULL){
        (*head) = p;
        return;
    }
    
    linktype *temp = (*head);
    linktype *prev = NULL;
    int insertedFlag=0;
    do{  
        if(temp==NULL || wt<temp->wt){
            if(prev!=NULL){
                prev->next = p;
            }
            else{
                (*head) = p;
            }
            p->next = temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }while(1);
}
//function to add Edges to Nodes of graph
void createEdges(graphtype* graph, int n){
    for(int i=0; i<n; i++){
        int ch;
        printf("Enter destination and weight of edges for %d:\n", (graph+i)->data);
        do{
            printf("continue: 1/0:");
            scanf("%d", &ch);
            if(ch==1){
                int destination, weight;
                scanf("%d %d", &destination, &weight);
                addEdge(&((graph+i)->head), (graph+i)->data, destination, weight);
            }
        }while(ch==1);
    }
}
//display
void display(graphtype* graph, int n){
    for(int i=0; i<n; i++){
        printf("%d ", (graph+i)->data);
        linktype* temp = (graph+i)->head;
        while(temp!=NULL){
            printf("--%d--> %d ", temp->wt, temp->dst);
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
    
    addNodes(graph, n);
    createEdges(graph, n);
    display(graph, n);

    return 0;
}
/*sample I/O
Enter the number of nodes: 5
Enter data to be added:
60 55 42 2 99
Enter destination and weight of edges for 60:
continue: 1/0:1
99 6
continue: 1/0:1
55 2
continue: 1/0:0
Enter destination and weight of edges for 55:
continue: 1/0:1
99 1
continue: 1/0:1
2 1
continue: 1/0:0
Enter destination and weight of edges for 42:
continue: 1/0:1
99 4
continue: 1/0:1
55 6
continue: 1/0:0
Enter destination and weight of edges for 2:
continue: 1/0:1
42 5
continue: 1/0:1
99 3
continue: 1/0:0
Enter destination and weight of edges for 99:
continue: 1/0:0
60 --2--> 55 --6--> 99 
55 --1--> 99 --1--> 2 
42 --4--> 99 --6--> 55 
2 --3--> 99 --5--> 42 
99 
*/
