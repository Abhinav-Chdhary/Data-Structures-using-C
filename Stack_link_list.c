//implement stack using link list
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}nodetype;

void push(nodetype **head){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    printf("Enter data:");
    scanf("%d", &p->data);
    p->next = *head;
    *head = p;
}

void pop(nodetype **head){
    nodetype *p = *head;
    printf("popped:%d", p->data);
    *head = (*head)->next;
    free(p);
}
void display(nodetype *head){
    while(head->next!=NULL){
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("%d", head->data);
}

int main()
{
    nodetype *head=NULL;
    int ch;
    printf("Enter ur choice:\n1 for insert\n2 for delete\n3 for display\n");
    do{
        printf("\nYour choice:");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                    push(&head);
                    break;
            case 2:
                    if(head==NULL)
                        printf("!stack is empty!\n");
                    else
                        pop(&head);
                    break;
            case 3: 
                    if(head==NULL)
                        printf("!stack is empty!\n");
                    else
                        display(head);
                    break;
        }
        
    }while(ch>0 && ch<4);

    return 0;
}
