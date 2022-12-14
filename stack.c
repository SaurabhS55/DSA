// // Representation of stack using Array
// #include<stdio.h>
// #include<stdlib.h>
// #define max 10
// int a[10];
// int top=-1;
// void push();
// void pop();
// void traverse();
// int main(){
//     int ch;
//     do{
//         printf("\n 1.push \n 2.pop \n 3.travese \n 4.exit\n");
//         scanf("%d",&ch);
//         switch (ch)
//         {
//         case 1:push();
//             break;
//         case 2:pop();
//             break;
//         case 3:traverse();
//             break;
//         case 4:exit(0);
//             break;
        
//         default:
//         printf("wrong choice");
//             break;
//         }
//     }while(ch!=4);
// }
// int isFull(){
//     if(top==max-1){
//         return 0;
//     }
//     else{
//         return 1;
//     }

// }
// int isEmpty(){
//     if(top==-1){
//         return 0;
//     }
//     else{
//         return 1;
//     }

// }
// void push(){
//     if(isFull()){
//         int e;
//         printf("Enter element\n");
//         scanf("%d",&e);
//         ++top;
//         a[top]=e;
//         printf("Element inserted...\n");
//     }
//     else{

//     printf("stack full");
//     }
// }
// void pop(){
//     if(isEmpty()){
//         int d;
//         d=a[top];
//         top--;
//         printf("%d is deleted from stack\n",d);
//     }
//     else{

//     printf("stack is empty");
//     }
// }
// void traverse(){
//     if(isEmpty()){
//         for(int i=top;i>=0;i--){
//             printf("\n%d",a[i]);
//         }
//     }
//     else{

//     printf("satck is empty");
//     }
// }


// stack representation using singly linked representation

#include<stdio.h>
struct node{
    int data;
    struct node* next;
}*top;
void push(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int ele;
    printf("Enter element\n");
    scanf("%d",&ele);
    temp->data=ele;
    temp->next=NULL;
    // if(top==NULL){
    //     printf("stack is full");
    // }
    
        temp->next=top;
        top=temp;
        printf("%d pushed on stack",ele);
}
void pop(){
    if(top==NULL){
        printf("stack is empty");
    }
    else{
        struct node* q=top;
        int d=q->data;
        top=top->next;
        printf("%d is deleted from stack...",d);
        free(q);
    }
}
void traverse(){
    if(top==NULL){
        printf("stack is empty");
    }
    else{
        struct node* q=top;
        while(q!=NULL){
            printf("\n%d",q->data);
            q=q->next;
        }
    }
}
int main(){
    int ch;
    do{
        printf("\n 1.push \n 2.pop \n 3.travese \n 4.exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:push();
            break;
        case 2:pop();
            break;
        case 3:traverse();
            break;
        case 4:exit(0);
            break;
        
        default:
        printf("wrong choice");
            break;
        }
    }while(ch!=4);
    return 0;
}