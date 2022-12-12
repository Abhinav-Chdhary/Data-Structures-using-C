//Program to return 4th non repeating element
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("INPUT:\n");
	scanf("%d", &n);
	int *p = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++){
    	scanf("%d",(p+i));
	}
	printf("OUTPUT:\n");
    
	int count=0;
	for(int i=0; i<n; i++){
   	 int flag=0;
    	for(int j=0; j<n; j++){
   		 if(*(p+i)==*(p+j) && i!=j)
   			 flag=1;
    	}
    	if(flag==0)
   		 count++;
    	if(count==4)
   			 printf("%d is the fourth non repeating element\n", *(p+i));
	}
   	 
	return 0;
}
