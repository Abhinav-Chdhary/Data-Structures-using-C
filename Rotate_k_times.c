//program to rotate array of n elements k times
//assuming k is not larger than n
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    //take input
    scanf("%d %d", &n, &k);
    int *p = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",(p+i));
    }
    //performing right shift
    for(int i=0; i<k; i++){
        int t=*(p+n-1);
        for(int j=n-1;j>0;j--){
            *(p+j) = *(p+j-1);
        }
        *p=t;
    }
    //printing
    for(int i=0; i<n; i++){
        printf("%d ", *(p+i));
    }
    return 0;
}
