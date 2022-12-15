/*
Abhinav Choudhary
B.tech CST
3rd Sem
uni roll: 21021726
class roll: 49
Write a C program to implement Kurskal’s algorithm
*/
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
//supply appropriate node data
int getNodeData(linktype* head, int j){
    if(head==NULL)
        return 0;
    if(j==0)
        return head->wt;
    while(j--){
        head=head->next;
    }
    return head->wt;
}
void createEdgeList(graphtype* g, int edgeList, int n){
    //work in progress
}
//trying to simulate kruskal's algorithm
int kruskals(graphtype* g, int n){
    int i=0, j=0, k=0, total=0;
    while(i!=n-1){
        if(k==n){
            //resetting k and incrementing j
            k=0; j++;
        }
        int p = getNodeData((g+k)->head, j);
        if(p!=0){
            total+=p;
            i++;
        }
        k++;
    }
    return total;
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
    int result = kruskals(graph, n);
    printf("kruskals result: %d", result);

    return 0;
}