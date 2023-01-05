#define max 20
#include <stdio.h>
#include <string.h>

void swap(char a[max], char b[max]){
    char temp[max];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int fpivot(char words[][max], int l, int r){
    char pivot[max];
    strcpy(pivot, words[r]);
    int strt = l;
    for(int i=strt; i<r; i++){
        if(strcmp(words[i], pivot)<0){
            swap(words[strt], words[i]);
            strt++;
        }
    }
    swap(words[strt], words[r]);
    return strt;
}

void quickSort(char words[][max], int l, int r){
    if(l<r){
        int pivot = fpivot(words, l, r);
        quickSort(words, l, pivot-1);
        quickSort(words, pivot+1, r);
    }
}

int main(){
    int n;
    printf("Enter the number of words: ");
    scanf("%d", &n);

    char words[n][max];
    printf("Enter the words:\n");
    for(int i=0; i<n; i++){
        scanf("%s", words[i]);
    }
    quickSort(words, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%s ", words[i]);
    }
    return 0;
}