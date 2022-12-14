/*
Abhinav Choudhary
B.tech CST
3rd Sem
uni roll: 21021726
class roll: 49
 Write a C program to create a binary search tree and perform
 following operations:
 1) Search a particular key. 
 2) Delete a node from the tree.
 3) Find total number of leaf nodes 
 4) Find height of a binary search tree
 5) Count total numbers of nodes from right hand side of root node*/
//program to perform basic operations of a binary search tree
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
//simple math function to return max
int max(int a, int b){
    return a>=b? a: b;
}
//1.function to search a particular key
void searchTree(bsttype* root, int target){
    if(root==NULL)
        return;
    else if(root->data==target){
        printf("%d was found!\n", target);
        return;
    }
    searchTree(root->left, target);
    searchTree(root->right, target);
}
//2. Deletion in a BST
//function to find minimum in right subtree
bsttype* smallest(bsttype* root){
    if(root->left==NULL)
      	return root;
    return smallest(root->left);
}
//function to delete a node
bsttype* deleteNode(bsttype* root, int key){
   	if(root == NULL)
       	return root;
   	else if(key<root->data){
       	root->left = deleteNode(root->left, key);
   	}
   	else if(key>root->data){
       	root->right = deleteNode(root->right, key);
   	}
   	else{
       	if(root->left==NULL && root->right==NULL){
           	return NULL;
       	}
       	else if(root->left==NULL){
           	bsttype* temp = root->right;
           	free(root);
           	return temp;
       	}
       	else if(root->right==NULL){
           	bsttype* temp = root->left;
           	free(root);
           	return temp;
       	}
       	//delete node with 2 children
       	bsttype* temp = smallest(root->right);
       	root->data = temp->data;
       	root->right=deleteNode(root->right, root->data);
    }
    return root;
}

//3.function to count number of leaf nodes
void countLeafNodes(bsttype* root, int* n){
    if(root==NULL)
        return;
    countLeafNodes(root->left, n);
    countLeafNodes(root->right, n);
    if(root->left==NULL && root->right==NULL)
        ++(*n);
}
//4.function to find height of a binary tree
int findHeightOfBST(bsttype* root){
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return 0;
    return max(findHeightOfBST(root->left), findHeightOfBST(root->right))+1;
}
//5.funtion to calculate total number of nodes from right hand side
int rightCount(bsttype* root){
    if(root==NULL)
        return 0;
    return rightCount(root->right)+rightCount(root->left)+1;
}

int main() {
    int ch;
    bsttype* root = NULL;
    printf("Enter 1 to insert node\n2 to display\n3 to search a key");
    printf("\n4 to delete a Node from the tree\n5 to count leaf nodes");
    printf("\n6 to find height of the tree\n7 to count total nodes in right subtree");
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
                        int x;
                        printf("Enter key to be searched\n");
                        scanf("%d", &x);
                        searchTree(root, x);
                    }
                    break;
            case 4:
                    if(root==NULL)
                        printf("Tree is empty\n");
                    else{
                        int x;
                        printf("Enter key to be deleted\n");
                        scanf("%d", &x);
                        deleteNode(root, x);
                    }
                    break;
            case 5:
                    if(root==NULL)
                        printf("Tree is empty\n");
                    else{
                        int n=0;
                        countLeafNodes(root, &n);
                        printf("%d nodes\n", n);
                    }
                    break;
            case 6:
                    if(root==NULL)
                        printf("Tree is empty\n");
                    else{
                        printf("height: %d\n", findHeightOfBST(root));
                    }
                    break;
            case 7: if(root==NULL)
                        printf("Tree is empty\n");
                    else{
                        printf("num of Nodes: %d\n", rightCount(root->right));
                    }
                    break;
        }
    }while(ch>0 && ch<8);

    return 0;
}
