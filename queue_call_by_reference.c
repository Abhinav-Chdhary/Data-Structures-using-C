//implement simple queue using array using call by reference
//USING STATIC ARRAY
#define max 5
#include <stdio.h>

void enque(int sq[], int *r){
	scanf("%d", &sq[++(*r)]);
	printf("-------x-------\n");
}
void deque(int sq[], int *f, int *r){
	if(*f==*r)
    	*f=-1;
	printf("%d\n", sq[++(*f)]);
	printf("-------x-------\n");
}
void display(int sq[], int f, int r){
	while(f<=r){
    	printf("%d\n", sq[f++]);
	}
	printf("-------x-------\n");
}

int main()
{
	int sq[max], f=-1, r=-1, ch;
	do{
    	printf("MENU:\n");
    	printf("1 for enque\n2 for deque\n3 for display\n0 to exit\n");
    	scanf("%d", &ch);
    	switch(ch){
        	case 1://enque
                	if(r==max-1)
                    	printf("queue is full\n");
                	else
                    	enque(sq, &r);
                	if(f==-1)
                    	f=0;
                	break;
        	case 2://deque
                	if(f==-1)
                    	printf("queue is empty\n");
                	else
                    	deque(sq, &f, &r);
                	if(f==-1)
                    	r=-1;
                	break;
        	case 3://display
                	if(f==-1 || f==max-1){
                    	printf("empty");
                	}
                	else{
                    	display(sq, f, r);
                	}
                	break;
        	default:printf("wrong choice\n");
    	}
	}while(ch!=0);
    
	return 0;
}
