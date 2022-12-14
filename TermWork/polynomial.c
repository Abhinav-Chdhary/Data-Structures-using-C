/*
Abhinav Choudhary
B.tech CST
3rd Sem
uni roll: 21021726
class roll: 49

Write a C program to add of two polynomials
 of degree n, using linked list
 p1 = first polynomial 
 p2 = second polynomial
 Find out p3= p1+p2

*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node{
    int data;
    struct node *next;
}nodetype;

void insert(nodetype **head, int total){
	nodetype* p = (nodetype*)malloc(sizeof(nodetype));
	p->data = total;
	p->next = NULL;
    
    if((*head)==NULL){
    	*head = p;
    	return;
    }
    nodetype* temp = (*head);
    while(temp->next!=NULL){
    	temp=temp->next;
    }
    temp->next = p;
}
void createLinkList(nodetype **head, int x){
	int con;
	for(int i=0; i<=x; i++){
        printf("Enter value of coefficient: ");
	    scanf("%d", &con);
    	insert(head, con);
	}
}
void addLinkList(nodetype *p1, nodetype *p2, nodetype **p3, int x){
	while(x-- >= 0){
    	int total = p1->data + p2->data;
    	insert(p3, total);
    	p1=p1->next;
    	p2=p2->next;
	}
}
void display(nodetype *head){
    while(head->next!=NULL){
   	 printf("%d, ", head->data);
   	 head = head->next;
    }
    printf("%d\n", head->data);
}
int main(){
	nodetype *p1, *p2, *p3;
	p1=p2=p3=NULL;
    
	int x;
	printf("Enter the degree of polynomial: ");
	scanf("%d", &x);
	printf("Create first polynomial:\n");
	createLinkList(&p1, x);
	display(p1);
	printf("Create second polynomial:\n");
	createLinkList(&p2, x);
	display(p2);
	printf("Adding to create 3rd polynomial:\n");
	addLinkList(p1, p2, &p3, x);
	display(p3);
    
	return 0;   
}
