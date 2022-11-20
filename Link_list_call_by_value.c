//insertion, deletion at left, right, n th of a link list
typedef struct node{
    int data;
    struct node *next;
}nodetype;
#include <stdio.h>
#include <stdlib.h>
//insert at the left hand side of a link list
nodetype *insertLeft(nodetype *L){
    nodetype *p=(nodetype*)malloc(sizeof(nodetype));
    printf("Enter value to be inserted:");
    scanf("%d", &p->data);
    p->next = L;
    L = p;
    return L;
}
//insert at the left right side of a link list
nodetype *insertRight(nodetype *R){
    nodetype *p=(nodetype*)malloc(sizeof(nodetype));
    printf("Enter value to be inserted:");
    scanf("%d", &p->data);
    if(R!=NULL)
        R->next = p;
    p->next = NULL;
    R = p;
    return R;
}
//insert at the nth position of a link list
void insertAt(nodetype *F, int n){
    nodetype *p=(nodetype*)malloc(sizeof(nodetype));
    printf("Enter value to be inserted:");
    scanf("%d", &p->data);
    while(--n){
        F = F->next;
    }
    nodetype *temp = NULL;
    
    temp = F->next;
    F->next = p;
    p->next = temp;
}
//to display the link list
void display(nodetype *L, nodetype *R){
    while(L!=R){
        printf("%d, ", L->data);
        L = L->next;
    }
    printf("%d\n", L->data);
}
//delete at the left hand side of a link list
nodetype *deleteLeft(nodetype *L){
    nodetype* p = L;
    L = L->next;
    free(p);
    return L;
}
//delete at the right hand side of a link list
nodetype *deleteRight(nodetype *L, nodetype *R){
    while(L->next!=R){
        L = L->next;
    }
    R = L;
    nodetype* p = R->next;
    R->next = NULL;
    free(p);
    return R;
}
//delete at nth position of a linked list
void deleteAt(nodetype *L, int n){
    while(--n){
        L=L->next;
    }
    nodetype* p = L->next;
    L->next = L->next->next;
    free(p);
}

int main()
{
    int ch;
    nodetype *L=NULL, *R=NULL;
    //INSERTION
    printf("Insertion Menu:\n");
    printf("Enter your choice\n1 for insertion at left\n2 for insertion at right\n3 for insertion at nth\n4 to display\n");
    do{
        printf("choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1: 
                    L = insertLeft(L); //inserting at left
                    if(R==NULL){
                        R=L;
                    }
                    break;
            case 2:
                    R=insertRight(R); //insert at Right
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
                        insertAt(L, n);
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
                        L = deleteLeft(L);
                    break;
            case 2:
                    if(R==NULL)
                        printf("list is empty\n");
                    else if(L==R)
                        L=R=NULL;
                    else
                        R = deleteRight(L, R);
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
