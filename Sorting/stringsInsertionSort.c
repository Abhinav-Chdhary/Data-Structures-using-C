#define max 20
#include <stdio.h>
#include <string.h>

void insertionSort(char words[][max], int n){
    for(int i=1; i<n; i++){
        int hole = i;
        char value[max];
        strcpy(value, words[i]);
        while (hole>0 && strcmp(value, words[hole-1])<0)
        {
            strcpy(words[hole], words[hole-1]);
            hole--;
        }
        strcpy(words[hole], value);
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
    insertionSort(words, n);
    for(int i=0; i<n; i++){
        printf("%s ", words[i]);
    }
    return 0;
}