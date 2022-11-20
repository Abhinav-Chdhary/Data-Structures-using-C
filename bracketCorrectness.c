//Check the mathematical correctness of brackets using stack
//Assuming the brackets are of type () or [] or <> or {}.
#include <string.h>
#include <stdio.h>

int push(char st[], int *top, char ch){
    st[++(*top)]=ch;
}
void pop(char st[], int *top){
    printf("poped: %c\n", st[(*top)--]);
}

int main(){
    printf("- - - - - - -INPUT- - - - - - -\n");
    char str[100];
    fgets(str, sizeof(str), stdin);
    const int max=strlen(str);
    char stack[max];
    int top=-1;
    
    for(int i=0; i<strlen(str)-1; i++){
        if(str[i]!=')' && str[i]!='>' && str[i]!=']' && str[i]!='}')
            push(stack, &top, str[i]);
        else{
            if(str[i]==')')
                str[i]--;
            else
                str[i]-=2;
            if(stack[top]==str[i])
                pop(stack, &top);
        }
    }
    printf("OUTPUT:\n");
    if(top==-1)
        printf("yes valid\n");
    else
        printf("not valid\n");
    
    return 0;
}
