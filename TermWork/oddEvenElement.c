/*
Q3.
Write a C program to create a linked list P, and then write a ‘C’
function named split to create two linked lists Q & R from P So
that Q contains all elements in odd positions of P and R contain
the remaining elements. Finally print both linked lists i.e. Q and R.
*/
typedef struct node{
	int data;
	struct node *next;
}nodetype;

#include <stdio.h>
#include <stdlib.h>

//common function to insert new node
void insertNode(nodetype **head, int x){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    p->data = x;
	p->next = *head;
    *head = p;
}
//odd/even separator based on position
void separator(nodetype *P, nodetype **Q, nodetype **R){
    int i=1;
    while(P!=NULL){
        if(i%2)
            insertNode(Q, P->data);
        else
            insertNode(R, P->data);
        P = P->next;
        i++;
    }
}
//display function
void display(nodetype *head){
    while (head!=NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter num of nodes: ");
    scanf("%d", &n);
    nodetype *P = NULL, *Q= NULL, *R=NULL;
    printf("Enter a linked list elements:\n");
    while (n!=0)
    {
        int x;
        scanf("%d", &x);
        insertNode(&P, x);
        n--;
    }
    //separating the nodes
    separator(P, &Q, &R);
    //printing...
    printf("elements at odd positions are: ");
    display(Q);
    printf("elements at even positions are: ");
    display(R);
    
    return 0;
}