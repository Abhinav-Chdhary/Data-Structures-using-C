/*
Write a C program to sort an unsorted sequence of strings
 given by user in an array, using 
 Merge sort technique*/
//CAUTION program is not complete!
#define max 10
#include <stdio.h>
#include <string.h>

void merge(char words[][max], int l, int mid, int r){
    mid = mid+1;
    int i=0, j=0, k=l, m=mid-l, n=r-mid+1;
         
    char arr1[mid-l][max];
    char arr2[r-mid][max];
    //copy first half to arr1
    for(int x=0; x<m; x++){
        strcpy(arr1[x], words[k]);
        k++;
    }
    //copy second half to arr2
    for(int x=0; x<n; x++){
        strcpy(arr2[x], words[k]);
        k++;
    }
    k=l;
    //comparing and putting in
    while(i<m && j<n){
        if(strcmp(arr1[i], arr2[j])<0){
            strcpy(words[k], arr1[i]);
            i++;
        }
        else{
            strcpy(words[k], arr2[i]);
            j++;
        }
        k++;
    }
    //left over elements of first half
    while(i<m){
        strcpy(words[k], arr1[i]);
        i++; k++;
    }
    //left over elements of second half
    while(j<n){
        strcpy(words[k], arr2[j]);
        j++; k++;
    }
}

void mergeSort(char words[][max], int l, int r){
    if(l<r){
        int mid = l+(r-l)/2;
        mergeSort(words, l, mid);
        mergeSort(words, mid+1, r);
        merge(words, l, mid, r);
    }
}

int main(){
    int n;
    printf("Enter the no. of strings: ");
    scanf("%d", &n);

    char dump;
    char words[n][max];
    for(int i=0; i<n; i++){
        scanf("%s", words[i]);
    }
    mergeSort(words, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%s\n", words[i]);
    }
    return 0;
}