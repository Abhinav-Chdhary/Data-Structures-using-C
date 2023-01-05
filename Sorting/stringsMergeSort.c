#include <stdio.h>
#include <string.h>
#define max 20

void merge(char words[][max], int l, int m, int r)
{
    int i, j, k=l;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    char L[n1][max], R[n2][max];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        strcpy(L[i], words[k++]);
        
    for (j = 0; j < n2; j++)
        strcpy(R[j], words[k++]);
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; j = 0; k = l; 
    
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[i])<0) {
            strcpy(words[k], L[i]);
            i++;
        }
        else {
            strcpy(words[k], R[j]);
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        strcpy(words[k++], L[i++]);
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        strcpy(words[k++], R[j++]);
    }
}
 
//merge sort function
void mergeSort(char words[][max], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(words, l, m);
        mergeSort(words, m + 1, r);
        merge(words, l, m, r);
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
        printf("%s ", words[i]);
    }
    return 0;
}
