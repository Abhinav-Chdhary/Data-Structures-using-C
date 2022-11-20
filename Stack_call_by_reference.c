//implement stack using call by reference ARRAY IMPLEMENTAION
#define MAX 5
#include <stdio.h>

void push(int st[], int *top){
    scanf("%d", &st[++(*top)]);
}
void pop(int st[], int *top){
    printf("%d\n", st[(*top)--]);
}
void display(int st[], int top){
    while(top!=-1){
        printf("%d\n", st[top--]);
    }
}
void peak(int st[], int top){
    printf("%d\n", st[top]);
}

int main(){
    int stack[MAX], top=-1, ch;
    do{
        printf("- - - - - - -Enter- - - - - - -\n");
        printf("1 for push\n2 for pop\n3 for display\n4 for peek\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:if(top==MAX-1){
                        printf("FULL\n");
                    }
                    else{
                        push(stack, &top);
                    }
                    break;
                    
            case 2:if(top==-1){
                        printf("EMPTY\n");
                    }
                    else{
                        pop(stack, &top);
                    }
                    break;
                    
            case 3:if(top==-1){
                       printf("EMPTY\n"); 
                    }
                    else{
                        display(stack, top);
                    }
                    break;
                    
            case 4:if(top==-1){
                        printf("EMPTY\n");
                    }
                    else{
                        peak(stack, top);
                    }
                    break;
            default:printf("- - - - - -Terminated- - - - - -");
        }
    }while(ch>=1 && ch<=4);
    return 0;
}
