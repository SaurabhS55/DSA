#include<stdio.h>
#include<stdlib.h>
#define max 20
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* st[max];

struct node* create(int data){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}
void inorder(struct node *root)
{
    int top=-1;
    struct node* cur=root;
    while(top>-1 || cur!=NULL){
        if(cur!=NULL){
            st[++top]=cur;
            cur=cur->left;
        }
        else{
            cur=st[top--];
            printf("%d ",cur->data);
            cur=cur->right;
        }
    }    
}
void preorder(struct node* root){
    int top=-1;
    
    struct node* cur=root;
    st[++top]=root;
    while(top>-1){
        cur=st[top--];
        printf("%d ",cur->data);
        if(cur->right!=NULL){
            st[++top]=cur->right;
        }
        if(cur->left!=NULL){
            st[++top]=cur->left;
        }
    }
}
void postorder(struct node* root){
    int top=-1;
    struct node* cur=root;
    do{
        while(cur!=NULL){
            if(cur->right!=NULL){
                st[++top]=cur->right;
            }
            st[++top]=cur;
            cur=cur->left;
        }
        cur=st[top--];
        if(cur->right!=NULL && st[top]==cur->right){
            --top;
            st[++top]=cur;
            cur=cur->right;
        }
        else{
            printf("%d ",cur->data);
            cur=NULL;
        }
    }while(top!=-1);
}
int main(){
    struct node* root;
    root=create(1);
    root->left=create(2);
    root->right=create(3);
    root->left->left=create(4);
    root->left->right=create(5);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;


}