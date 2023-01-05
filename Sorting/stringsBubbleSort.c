#define max 20
#include <stdio.h>
#include <string.h>

void bubbleSort(char words[][max], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(strcmp(words[j+1], words[j])<0){
                char temp[max];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], temp);
            }
        }
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
    bubbleSort(words, n);
    for(int i=0; i<n; i++){
        printf("%s ", words[i]);
    }
    return 0;
}