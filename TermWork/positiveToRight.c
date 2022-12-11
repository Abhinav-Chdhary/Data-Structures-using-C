/*Write a C Program to store N elements to an array and then send
 all positive elements of the 
 array to the end without altering the original sequence.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int x;
    printf("Enter value of n: ");
    scanf("%d", &x);
    const int n = x;
    int arr[n];
    
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>=0 && arr[j+1]<0){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}
