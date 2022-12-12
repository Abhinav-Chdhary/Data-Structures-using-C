//Program to print missing term from AP
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
    int i, t;
    t=*(p+1)-*(p);
    for(i=0; i<n-1; i++){
        if(*(p+i+1)-*(p+i)!=t){
            printf("not an AP\n");
            printf("the missing term is %d\n", *(p+i)+t);
            break;
        }
    }
    if(i==n-1)
        printf("yes it is AP\n");
        
    return 0;
}
