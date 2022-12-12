//program to print n prime numbers
#include <stdio.h>

int main(){
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 2; count < n; i++)
    {
        int flag=1;
        for (int j = 2; j <= i/2; j++)
        {
            if(i%j==0){
                flag=0;
                break;
            }
        }
        if(flag){
            printf("%d\n", i);
            count++;
        }
    }
    
    return 0;
}
