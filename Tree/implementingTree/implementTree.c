#include<stdio.h>
#include<malloc.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* create(){
    int x;
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    printf("Enter data and -1 is for no node\n");
    scanf("%d", &x);
    if(x == -1){
        return 0;
    }
    newnode->data = x;
    printf("Enter left child of %d\n", x);
    scanf("%d", &x);
    newnode->left = create();
    printf("Enter the right node of %d\n", x);
    scanf("%d", &x);
    newnode->right = create();
    return newnode;
}
void preOrder(struct node* root){
    if(root!=NULL){
        printf("*%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    struct node *root;
    root = 0;
    root = create();
    preOrder(root);
}