//program to perform basic operations of a binary search tree
#include <stdio.h>
#include <stdlib.h>

typedef struct bst{
    struct bst* left;
    int data;
    struct bst* right;
}bsttype;

//function to create a node
bsttype* createNode(){
    bsttype* p = (bsttype*)malloc(sizeof(bsttype));
    printf("Enter the data to be inserted:");
    scanf("%d", &p->data);
    p->left = p->right = NULL;
    return p;
}
//function to insert a node in the tree
void insert(bsttype** root, bsttype* p){
    if((*root)==NULL)
        *root = p;
    else if(p->data < (*root)->data)
        insert(&(*root)->left, p);
    else
        insert(&(*root)->right, p);
}
//function to display in tree INORDER
void display(bsttype* root){
    if(root==NULL)
        return;
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}
//function to count total nodes in the tree
void countNodes(bsttype* root, int* n){
    if(root==NULL){
        return;
    }
    countNodes(root->left, n);
    countNodes(root->right, n);
    ++(*n);
}
//function to count number of leaf nodes
void countLeafNodes(bsttype* root, int* n){
    if(root==NULL)
        return;
    countLeafNodes(root->left, n);
    countLeafNodes(root->right, n);
    if(root->left==NULL && root->right==NULL)
        ++(*n);
}
//function to count number of nodes with only one child
void countOneChildNodes(bsttype* root, int* n){
    if(root==NULL)
        return;
    countOneChildNodes(root->left, n);
    countOneChildNodes(root->right, n);
    if(root->left==NULL && root->right!=NULL)
        ++(*n);
    else if(root->left!=NULL && root->right==NULL)
        ++(*n);
}

int main() {
    int ch;
    bsttype* root = NULL;
    printf("Enter 1 to insert node\n2 to display\n3 to count no.nodes\n4 to count leaf nodes\n5 to count one child nodes");
    do{
        printf("\nchoice:");
        scanf("%d", &ch);
        switch(ch){
            case 1: ;
                    bsttype* p = createNode();
                    insert(&root, p);
                    break;
            case 2: 
                    if(root==NULL)
                        printf("Tree is empty\n");
                    else
                        display(root);
                    break;
            case 3:
                    if(root==NULL)
                        printf("Tree is empty\n");
                    else{
                        int n=0;
                        countNodes(root, &n);
                        printf("%d nodes\n", n);
                    }
                    break;
            case 4:
                    if(root==NULL)
                        printf("Tree is empty\n");
                    else{
                        int n=0;
                        countLeafNodes(root, &n);
                        printf("%d nodes\n", n);
                    }
                    break;
            case 5:
                    if(root==NULL)
                        printf("Tree is empty\n");
                    else{
                        int n=0;
                        countOneChildNodes(root, &n);
                        printf("%d nodes\n", n);
                    }
                    break;
        }
    }while(ch>0 && ch<6);

    return 0;
}
