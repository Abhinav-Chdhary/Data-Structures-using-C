#define max 20
#include <stdio.h>
#include <string.h>

void selectionSort(char words[][max], int n){
    for(int i=0; i<n-1; i++){
        int min=i;
        for(int j=i+1; j<n; j++){
            if(strcmp(words[j], words[min])<0)
                min = j;
        }
        char temp[max];
        strcpy(temp, words[i]);
        strcpy(words[i], words[min]);
        strcpy(words[min], temp);
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
    selectionSort(words, n);
    for(int i=0; i<n; i++){
        printf("%s ", words[i]);
    }
    return 0;
}