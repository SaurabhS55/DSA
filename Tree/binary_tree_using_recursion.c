#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
void inorder(struct node *root)
{
    if (root == NULL){
        return;
    }
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL){
        return;
    }
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL){
        return;
    }
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
}

int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    inorder(root);//4 2 5 1 3
    printf("\n");
    preorder(root);//1 2 4 5 3
    printf("\n");
    postorder(root);//4 5 2 3 1
    return 0;
}

