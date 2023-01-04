#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
} typedef TreeNode;

TreeNode *createNode(int data)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode *InsertNode(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = InsertNode(root->left, data);
    }
    else
    {
        root->right = InsertNode(root->right, data);
    }
    return root;
}

void search(TreeNode *root, int key)
{
    if (root == NULL)
    {
        printf("\nKey Not Found!!");
    }
    else if (root->data == key)
    {
        printf("\nKey Found!!");
    }
    else
    {
        if (key < root->data)
        {
            search(root->left, key);
        }
        else
        {
            search(root->right, key);
        }
    }
    return;
}

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("  %d  ", root->data);
        inorder(root->right);
    }
}

int FindMin(TreeNode *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return (root->data);
}
int FindMax(TreeNode *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return (root->data);
}
int main()
{
    TreeNode *root = NULL;
    root = InsertNode(root, 25);
    root = InsertNode(root, 20);
    root = InsertNode(root, 40);
    root = InsertNode(root, 32);
    root = InsertNode(root, 54);
    root = InsertNode(root, 28);
    root = InsertNode(root, 35);

    inorder(root);
    search(root, 32);
    search(root, 56);
    search(root, 20);
    printf("\nMinimum : %d", FindMin(root));
    printf("\nMaximum : %d", FindMax(root));
    return 0;
}