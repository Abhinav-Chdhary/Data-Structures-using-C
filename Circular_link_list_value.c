//program for circular link list using call by value
typedef struct node{
	int data;
	struct node *next;
}nodetype;

#include <stdio.h>
#include <stdlib.h>

nodetype *insertStart(nodetype *Strt){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    printf("Enter data to be inserted:");
    scanf("%d", &p->data);
    p->next=Strt;
    Strt = p;
    return Strt;
}
nodetype *insertEnd(nodetype *End){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    printf("Enter data to be inserted:");
    scanf("%d", &p->data);
    if(End!=NULL){
        p->next=End->next;
        End->next=p;
    }
    End = p;
    return End;
}
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
nodetype *deleteStart(nodetype *Strt){
    nodetype *p = Strt;
    if(Strt->next==Strt)
        Strt = NULL; 
    else
        Strt=Strt->next;
    free(p);
    return Strt;
}
nodetype *deleteEnd(nodetype *Strt, nodetype *End){
    nodetype *p = End;
    nodetype *temp = Strt;
    if(Strt==End){
        free(p);
        End = NULL;
    }
    else{
        while(temp->next!=p){
            temp=temp->next;
        }
        End = temp;
        End->next = Strt;
        free(p);
    }
    return End; 
}
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
                	Strt = insertStart(Strt); //inserting at left
                    if(End==NULL)
                        End = Strt;
                    End->next=Strt;
                	break;
        	case 2:
                	End=insertEnd(End); //insert at Right
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
                    	    Strt = insertStart(Strt);
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
                    	Strt = deleteStart(Strt);
                    	End->next = Strt;
                	}
                	break;
        	case 2:
                	if(Strt==NULL)
                    	printf("list is empty\n");
                	else
                    	End = deleteEnd(Strt, End);
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
