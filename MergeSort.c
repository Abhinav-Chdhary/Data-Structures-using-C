//MergeSort
#include <stdio.h>

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int l, int mid, int r){
    mid = mid+1;
    int i=0, j=0, k=l, m=mid-l, n=r-mid+1;
         
    int arr1[mid-l];
    int arr2[r-mid];
    //copy first half to arr1
    for(int x=0; x<m; x++){
        arr1[x]=arr[k++];
    }
    //copy second half to arr2
    for(int x=0; x<n; x++){
        arr2[x]=arr[k++];
    }
    k=l;
    //comparing and putting in
    while(i<m && j<n){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
                i++;
        }
        else{
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    //left over elements of first half
    while(i<m){
        arr[k]=arr1[i];
        i++; k++;
    }
    //left over elements of second half
    while(j<n){
        arr[k]=arr2[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int mid = l+(r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int n,T,i;
    
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    mergeSort(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}