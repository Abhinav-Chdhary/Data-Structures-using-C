//insertion, deletion in a circular link list
typedef struct node{
	int data;
	struct node *next;
}nodetype;

#include <stdio.h>
#include <stdlib.h>

//insert at start
void insertStart(nodetype **Strt){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    printf("Enter data to be inserted:");
    scanf("%d", &p->data);
    p->next=*Strt;
    *Strt = p;
}
//insert at end
void insertEnd(nodetype **End){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    printf("Enter data to be inserted:");
    scanf("%d", &p->data);
    if(*End!=NULL){
        p->next=(*End)->next;
        (*End)->next=p;
    }
    *End = p;
}
//insert at nth position
void *insertAt(nodetype *Strt, int n){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    printf("Enter data to be inserted:");
    scanf("%d", &p->data);
    while(--n!=1){
        Strt=Strt->next;
    }
    nodetype *temp = Strt->next;
    Strt->next = p;
    p->next = temp;
}
//delete at start
void deleteStart(nodetype **Strt){
    nodetype *p = *Strt;
    if((*Strt)->next==*Strt)
        *Strt = NULL; 
    else
        *Strt=(*Strt)->next;
    free(p);
}
//delete at end
void deleteEnd(nodetype **Strt, nodetype **End){
    nodetype *p = *End;
    nodetype *temp = *Strt;
    if(*Strt==*End){
        free(p);
        *End = NULL;
    }
    else{
        while(temp->next!=p){
            temp=temp->next;
        }
        *End = temp;
        (*End)->next = *Strt;
        free(p);
    }
}
//delete at nth position
void deleteAt(nodetype *Strt, int n){
    while(--n!=1){
        Strt=Strt->next;
    }
    nodetype *p = Strt->next;
    Strt->next = Strt->next->next;
    free(p);
}

void display(nodetype *Strt){
    nodetype *temp=Strt;
    do{
        printf("%d, ", temp->data);
        temp=temp->next;
    }while(temp!=Strt);
}


int main()
{
	int ch;
	nodetype *Strt=NULL, *End=NULL;
	printf("Insertion Menu:\n");
	printf("Enter your choice\n1 for insertion at start\n2 for insertion at end\n3 for insertion at nth\n4 to display\n");
	do{
    	printf("\nchoice:");
    	scanf("%d", &ch);
    	switch(ch){
        	case 1:
                	insertStart(&Strt); //inserting at left
                    if(End==NULL)
                        End = Strt;
                    End->next=Strt;
                	break;
        	case 2:
                	insertEnd(&End); //insert at Right
                	if(Strt==NULL){
                    	Strt=End;
                    	End->next=Strt;
                	}
                	break;
        	case 3:
                	if(Strt==NULL)
                    	printf("Cannot insert in empty list\n");
                	else{
                    	int n;
                    	printf("enter position:");
                    	scanf("%d", &n);
                    	if(n==1){
                    	    insertStart(&Strt);
                    	    End->next=Strt;
                    	}
                    	else
                    	    insertAt(Strt, n);
                	}
                	break;
        	case 4: 
        	        if(Strt==NULL || End==NULL)
                    	printf("list empty\n");
                	else
                    	display(Strt);
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
                	if(Strt==NULL)
                    	printf("list is empty\n");
                	else{
                    	deleteStart(&Strt);
                    	End->next = Strt;
                	}
                	break;
        	case 2:
                	if(Strt==NULL)
                    	printf("list is empty\n");
                	else
                    	deleteEnd(&Strt, &End);
                	break;
        	case 3:
                	;//empty statement
                	int n;
                	printf("enter position:");
                	scanf("%d", &n);
                	if(Strt==NULL && End==NULL)
                    	printf("list is empty\n");
                	else if(Strt==End && n==1)
                    	Strt=End=NULL;
                	else
                    	deleteAt(Strt, n);
                	break;
        	case 4:
                	if(Strt==NULL || End==NULL)
                    	printf("list empty\n");
                	else
                    	display(Strt);
                	break;
    	}
	}while(ch>0 && ch<5);

    
	return 0;
}
