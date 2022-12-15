/*
Q2. Program to create two linked lists positive and negative from a Original
linked list, so that positive linked list contains all positive
elements and negative linked list contains negative elements. Positive
and negative linked lists should use the node of existing original 
linked list. 
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
//negative and positive separator
void separator(nodetype *head, nodetype **pos, nodetype **neg){
    while(head!=NULL){
        if(head->data >= 0)
            insertNode(pos, head->data);
        else
            insertNode(neg, head->data);
        head = head->next;
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
    nodetype *head = NULL, *positive= NULL, *negative=NULL;
    printf("Enter linked list elements:\n");
    while (n!=0)
    {
        int x;
        scanf("%d", &x);
        insertNode(&head, x);
        n--;
    }
    //separating the nodes
    separator(head, &positive, &negative);
    //printing...
    printf("positive elements are: ");
    display(positive);
    printf("negative elements are: ");
    display(negative);
    
    return 0;
}