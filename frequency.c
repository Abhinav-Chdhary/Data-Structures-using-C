//Program to check frequency of each element in an array
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, m=0, n=0, o=0;
    printf("INPUT:\n");
    scanf("%d", &x);
    int *p   = (int*)malloc(x*sizeof(int));
    
    for(int i=0; i<x; i++){
        scanf("%d",(p+i));
    }
    printf("OUTPUT:\n");
    for(int i=0; i<x; i++){
        int n=*(p+i), count=1;
        for(int j=i+1;j<x;j++){
            if(*(p+j)==n){
                *(p+j)='\0';
                count++;
            }
        }
        if(count>0 && n!='\0')
            printf("%d occurs %d times\n", n, count);
    }
    
    return 0;
}
