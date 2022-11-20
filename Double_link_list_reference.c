//doubly link list using call by reference
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}nodetype;

void insertLeft(nodetype **L){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    printf("Enter data to be inserted:");
    scanf("%d", &p->data);
    if(*L!=NULL){
        (*L)->prev = p;
    }
    p->next = *L;
    p->prev = NULL;
    *L = p;
}
void insertRight(nodetype **R){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    printf("Enter data to be inserted:");
    scanf("%d", &p->data);
    if(*R!=NULL){
        (*R)->next = p;
    }
    p->prev = *R;
    p->next = NULL;
    *R=p;
}
void insertAt(nodetype *L, int n){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    printf("Enter data to be inserted:");
    scanf("%d", &p->data);
    while(--n!=1){
        L = L->next;
    }
    nodetype *temp = L->next;
    L->next = p;
    p->prev = L;
    p->next = temp;
    temp->prev = p;
}
void deleteLeft(nodetype **L){
    nodetype *p = *L;
    if((*L)->next==NULL)
        *L=NULL;
    else{
        *L = (*L)->next;
        (*L)->prev = NULL;
    }
    free(p);
}
void deleteRight(nodetype **R){
    nodetype *p = *R;
    if((*R)->prev==NULL)
        *R=NULL;
    else{
        *R = (*R)->prev;
        (*R)->next = NULL;
    }
    free(p);
}
void deleteAt(nodetype *L, int n){
    while(--n!=1){
        L=L->next;
    }
    nodetype *p = L->next;
    L->next = p->next;
    p->next->prev = L;
    free(p);
}

void display(nodetype *L){
    while(L->next!=NULL){
        printf("%d, ", L->data );
        L = L->next;
    }
    printf("%d\n", L->data);
}

int main()
{
	int ch;
	nodetype *L=NULL, *R=NULL;
	printf("Insertion Menu:\n");
	printf("Enter your choice\n1 for insertion at start\n2 for insertion at end\n3 for insertion at nth\n4 to display\n");
	do{
    	printf("\nchoice:");
    	scanf("%d", &ch);
    	switch(ch){
        	case 1: 
                	insertLeft(&L);
                	if(R==NULL)
                	    R = L;
                	break;
        	case 2:
                	insertRight(&R);
                	if(L==NULL)
                	    L = R;
                	break;
        	case 3:
                	;//
                	int n;
                	printf("Enter position: ");
                	scanf("%d", &n);
                	if(n==1)
                	    insertLeft(&L);
                	else
                	    insertAt(L, n);
                	break;
        	case 4: 
        	        if(L==NULL && R==NULL)
        	            printf("!list is empty!\n");
        	        else
        	            display(L);
                	break;
    	}
	}while(ch>0 && ch<5);
    
	printf("Deletion Menu:\n");
	printf("Enter your choice\n1 for Deletion at start\n2 for Deletion at end\n3 for Deletion at nth\n4 to display\n");
	do{
    	printf("\nchoice:");
    	scanf("%d", &ch);
    	switch(ch){
        	case 1:
                	if(L==NULL)
                	    printf("!list is empty!");
                	else{
                	    deleteLeft(&L);
                	    if(L==NULL){
                	        L=R=NULL;
                	    }
                	}
                	break;
        	case 2:
                	if(L==NULL)
                	    printf("!list is empty!");
                	else{
                	    deleteRight(&R);
                	    if(R==NULL){
                	        L=R=NULL;
                	    }
                	}
                	break;
        	case 3:
                    ;//
                	int n;
                	printf("Enter position: ");
                	scanf("%d", &n);
                	if(n==1)
                	    deleteLeft(&L);
                	else
                	    deleteAt(L, n);
                	break;
        	case 4:
        	        if(L==NULL && R==NULL)
        	            printf("!list is empty!");
                	else
                	    display(L);
                	break;
    	}
	}while(ch>0 && ch<5);

    
	return 0;
}
