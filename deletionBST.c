//program to insert and delete in a binary tree
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
    //find minimum in right subtree
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
                        	int n;
                        	printf("enter the key to be deleted:");
                        	scanf("%d", &n);
                        	deleteNode(root, n);
                    	}
                    	break;
        	}
    	}while(ch>0 && ch<4);
    
    	return 0;
    }
