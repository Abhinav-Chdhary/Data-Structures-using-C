//Program to store N elements in 1 D array (including positive ,negative and zero)
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, m=0, n=0, o=0;
    printf("INPUT:\n");
    scanf("%d", &x);
    int *p   = (int*)malloc(x*sizeof(int));
    int *pos = (int*)malloc(x*sizeof(int));
    int *neg = (int*)malloc(x*sizeof(int));
    int *zer = (int*)malloc(x*sizeof(int));
    
    for(int i=0; i<x; i++){
        scanf("%d",(p+i));
        if(*(p+i)>0)
            *(pos+m++)=*(p+i);
        else if(*(p+i)<0)
            *(neg+n++)=*(p+i);
        else
            *(zer+o++)=*(p+i);
    }
    printf("OUTPUT:\n");
    printf("the positives\n");
    for(int i=0; i<m; i++){
        printf("%d ",*(pos+i));
    }
    printf("\nthe negatives\n");
    for(int i=0; i<n; i++){
        printf("%d ",*(neg+i));
    }
    printf("\nthe zeroes\n");
    for(int i=0; i<o; i++){
        printf("%d ",*(zer+i));
    }
    
    return 0;
}
