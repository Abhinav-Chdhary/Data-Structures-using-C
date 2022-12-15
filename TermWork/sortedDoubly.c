/*
.Write a C program to create a double linked list by inserting
 nodes in such a way that the resultant linked list remains
 in ascending order.(do not use any sorting technique).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}nodetype;

//function to compare and insert
void insert(nodetype **head, int x){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    p->data = x;
    p->prev = p->next = NULL;
    if(*head==NULL){
        *head = p;
        return;
    }
    else if((*head)->data > p->data){
        p->next = *head;
        *head = p;
        return;
    }
    nodetype* temp = (*head)->next;
    nodetype* last = *head;
    while (temp!=NULL)
    {
        if(temp->data>p->data){
            last->next = p;
            temp->prev = p;
            p->next = temp;
            p->prev = last;
            return;
        }
        last = temp;
        temp = temp->next;
    }
       last->next = p;
       p->prev = last;
}
//display function
void display(nodetype *head){
    while(head->next!=NULL){
        printf("%d, ", head->data );
        head = head->next;
    }
    printf("%d\n", head->data);
}
//main function
int main(){
    int n;
    printf("Enter num of nodes: ");
    scanf("%d", &n);
    nodetype *head = NULL;
    printf("Enter linked list elements: \n");
    while (n!=0)
    {
        int x;
        scanf("%d", &x);
        insert(&head, x);
        n--;
    }

    //display function
    printf("sorted: ");
    display(head);
    
    return 0;
}