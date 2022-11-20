//program to print number of odd and even numbers in an array of n elements
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, ev=0, od=0;
    printf("INPUT:\n");
    scanf("%d", &n);
    int *p = (int*)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++){
        scanf("%d",(p+i));
        if(*(p+i)%2)
            od++;
        else
            ev++;
    }
    printf("OUTPUT:\n");
    printf("%d odd and %d even\n", od, ev);
    
    return 0;
}
