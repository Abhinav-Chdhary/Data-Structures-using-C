//Program to return 4th repeating element
/*CAUTION this program is not working for some test cases*/
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
    	for(int j=i+1; j<n; j++){
   		 if(*(p+i)==*(p+j))
   			 flag=1;
    	}
    	if(flag==1)
   		 count++;
    	if(count==4)
   			 printf("%d is the fourth repeating element\n", *(p+i));
	}
   	 
	return 0;
}
