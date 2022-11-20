//implement circular queue using array
#define max 5
#include <stdio.h>

void enque(int sq[], int *r){
	*r=((*r)+1)%max;
	scanf("%d", &sq[*r]);
	printf("-------x-------\n");
}
void deque(int sq[], int *f, int *r){
	printf("%d\n", sq[*f]);
	if(*f==*r){
    	*f=-1;
	}
	else{
    	*f=((*f)+1)%max;
	}
	printf("-------x-------\n");
}
void display(int sq[], int f, int r){
	while(f!=r){
    	printf("%d\n", sq[f]);
    	f=(f+1)%max;
	}
	printf("%d\n", sq[f]);
	printf("-------x-------\n");
}

int main()
{
	int sq[max], f=-1, r=-1, ch;
	printf("MENU:\n");
	printf("1 for enque\n2 for deque\n3 for display\n0 to exit\n");
	do{
    	scanf("%d", &ch);
    	switch(ch){
        	case 1://enque
                	if((r+1)%max==f)
                    	printf("queue is full\n");
                	else{
                    	enque(sq, &r);
                    	if(f==-1)
                        	f=0;
                	}
                	break;
        	case 2://deque
                	if(f==-1 && r==-1)
                    	printf("queue is empty\n");
                	else
                    	deque(sq, &f, &r);
                	break;
        	case 3://display
                	if(r==-1){
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
