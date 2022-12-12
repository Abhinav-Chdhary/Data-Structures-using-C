//program to test if elements of an array are in arithmetic progression
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //taking input
    int n;
    scanf("%d", &n);
    int *p = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",(p+i));
    }
    int i, t;
    t=*(p+1)-*(p);//difference of two elements
    //checking if elements are in arithmetic progression
    for(i=0; i<n-1; i++){
        if(*(p+i+1)-*(p+i)!=t){
            printf("not an AP\n");
            break;
        }
    }
    if(i==n-1)
        printf("yes it is AP\n");
        
    return 0;
}//main close
