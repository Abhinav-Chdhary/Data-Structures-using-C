/*
program to create two linked lists positive and negative from a Original
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
void insertNode(nodetype **head){
	nodetype *p = (nodetype*)malloc(sizeof(nodetype));
	printf("Enter value to be inserted:");
	scanf("%d", &p->data);
	p->next = *head;
	*head=p;
}
//negative and positive separator
void separator(nodetype *head, nodetype **pos, nodetype **neg){
    while(head!=NULL){
        if()
    }
}

int main(){

    return 0;
}