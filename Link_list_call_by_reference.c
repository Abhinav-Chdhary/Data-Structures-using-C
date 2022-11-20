//link list insertion, deletion using double pointer
typedef struct node{
	int data;
	struct node *next;
}nodetype;

#include <stdio.h>
#include <stdlib.h>

//To insert at left hand side of a linked list
void insertLeft(nodetype **L){
	nodetype *p = (nodetype*)malloc(sizeof(nodetype));
	printf("Enter value to be inserted:");
	scanf("%d", &p->data);
	p->next = *L;
	*L=p;
}
//To insert at right hand side of a linked list
void insertRight(nodetype **R){
	nodetype *p = (nodetype*)malloc(sizeof(nodetype));
	printf("Enter value to be inserted:");
	scanf("%d", &p->data);
	if(*R!=NULL)
    	(*R)->next=p;
	p->next = NULL;
	*R = p;
}
//To insert at nth position of a linked list
void insertAt(nodetype **L, int n){
	nodetype *p = (nodetype*)malloc(sizeof(nodetype));
	printf("Enter value to be inserted:");
	scanf("%d", &p->data);
	if(n==1){
    	p->next = *L;
    	*L=p;
	}
	else{
    	nodetype *left = *L;
    	while(--n!=1 && left->next!=NULL){
        	left=left->next;
    	}
    	nodetype *temp = NULL;
   	 
    	temp = left->next;
    	left->next = p;
    	p->next = temp;
	}
}
//to display the linked list
void display(nodetype *L, nodetype *R){
	while(L!=R){
    	printf("%d, ", L->data);
    	L = L->next;
	}
	printf("%d\n", L->data);
}
//To delete at left hand side of a linked list
void deleteLeft(nodetype **L){
	nodetype *p = *L;
	*L = (*L)->next;
	free(p);
}
//To delete at right hand side of a linked list
void deleteRight(nodetype *L, nodetype **R){
	nodetype *p = *R;
	while(L->next!=*R){
    	L = L->next;
	}
	*R = L;
	(*R)->next = NULL;
	free(p);
}
//To delete at nth position of a linked list
void deleteAt(nodetype *L, int n){
    while(--n!=1){
        L=L->next;
    }
    nodetype *p = L->next;
    L->next = L->next->next;
    free(p);
}

int main()
{
	int ch;
	nodetype *L=NULL, *R=NULL;
	printf("Insertion Menu:\n");
	printf("Enter your choice\n1 for insertion at left\n2 for insertion at right\n3 for insertion at nth\n4 to display\n");
	do{
    	printf("choice:");
    	scanf("%d", &ch);
    	switch(ch){
        	case 1:
                	insertLeft(&L); //inserting at left
                	if(R==NULL){
                    	R=L;
                	}
                	break;
        	case 2:
                	insertRight(&R); //insert at Right
                	if(L==NULL){
                    	L=R;
                	}
                	break;
        	case 3:
                	if(L==R)
                    	printf("Cannot insert in empty or single node list\n");
                	else{
                    	int n;
                    	printf("enter position:");
                    	scanf("%d", &n);
                    	insertAt(&L, n);
                	}
                	break;
        	case 4: if(R==NULL || L==NULL)
                    	printf("list empty\n");
                	else
                    	display(L, R);
                	break;
    	}
	}while(ch>0 && ch<5);
    
	printf("Deletion Menu:\n");
	printf("Enter your choice\n1 for Deletion at left\n2 for Deletion at right\n3 for Deletion at nth\n4 to display\n");
	do{
    	printf("choice:");
    	scanf("%d", &ch);
    	switch(ch){
        	case 1:
                	if(L==NULL)
                    	printf("list is empty\n");
                	else if(L==R)
                    	L=R=NULL;
                	else
                    	deleteLeft(&L);
                	break;
        	case 2:
                	if(R==NULL)
                    	printf("list is empty\n");
                	else if(L==R)
                    	L=R=NULL;
                	else
                    	deleteRight(L, &R);
                	break;
        	case 3:
                	;//empty statement
                	int n;
                	printf("enter position:");
                	scanf("%d", &n);
                	if(L==NULL && R==NULL)
                    	printf("list is empty\n");
                	else if(L==R && n==1)
                    	L=R=NULL;
                	else
                    	deleteAt(L, n);
                	break;
        	case 4:
                	if(R==NULL || L==NULL)
                    	printf("list empty\n");
                	else
                    	display(L, R);
                	break;
    	}
	}while(ch>0 && ch<5);

    
	return 0;
}
