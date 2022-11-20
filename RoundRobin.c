//program to simulate process scheduling algorithm known as ROUND ROBIN
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    int id;
    struct node *next;
}processtype;

//function to create process list
void createList(processtype** tail, int i){
    processtype* p = (processtype*)malloc(sizeof(processtype));
    printf("enter time taken by process:");
    scanf("%d", &p->data);
    p->id = i;
    if(*tail==NULL){
        (*tail) = p;
        (*tail)->next = p;
        return;
    }
        
    p->next = (*tail)->next;
    (*tail)->next = p;
    (*tail) = p;
}

//function to displayList
void displayList(processtype* tail){
    if(tail==NULL){
        printf("All processes completed\n");
        return;
    }
    processtype* p = tail->next;
    do{
        printf("%d for %d\n", p->data, p->id);
        p = p->next;
    }while(p!=tail->next);
    printf("\n");
}

//function to simulate multiprocessing schedule
void simulate(processtype** tail, int slot, int n){
    int i=0;
    processtype* current = (*tail)->next;
    processtype* prev = (*tail);
    while((*tail)!=NULL){
        if(current->data>0){
            current->data -= slot;
            prev=current;
            current = current->next;
        }
        else{
            printf("process %d completed after %d cycles\n", current->id, i);
            processtype* temp = current;
            if(current==current->next)
                (*tail)=NULL;
            else{
                prev->next = temp->next;
                if(temp==(*tail))
                    (*tail) = prev;
            }
            current = current->next;
            free(temp);
            printf("time left for other processes:\n");
            displayList(*tail);
        }
        if(current==(*tail)) ++i;
    }
}

int main()
{
    int n, slot;
    printf("Enter number of processes:");
    scanf("%d", &n);
    
    processtype* tail=NULL;
    printf("create process list\n");
    for(int i=1; i<=n; i++){
        createList(&tail, i);
    }
    displayList(tail);
    
    printf("Enter CPU time slot:");
    scanf("%d", &slot);
    
    simulate(&tail, slot, n);

    return 0;
}
