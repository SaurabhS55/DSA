// Representation of stack using Array
// #include<stdio.h>
// int a[10];
// int top=-1,max=sizeof(a);
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
//     if(top<max){
//         return 1;
//     }
//     else{
//         return 0;
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
// }
// void pop(){
//     if(isEmpty()){
//         int d;
//         d=a[top];
//         top--;
//         printf("%d is deleted from stack\n");
//     }
// }
// void traverse(){
//     if(isEmpty()){
//         for(int i=top;i>=0;i--){
//             printf("\n%d",a[i]);
//         }
//     }
// }
#include<stdio.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* top,*temp;
void push(){
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter number ");
    int ele;
    scanf("%d",&ele);
    temp->data=ele;
    temp->next=NULL;
    temp->prev=NULL;
    if(top==NULL){
        top=temp;
    }
    else{
        while(top->next!=NULL){
            top=top->next;
        }
        top->next=temp;
        temp->prev=top;
        top=temp;
    }
    printf("element inserted...");
    
}
void pop(){
    if(top==NULL){
        printf("List is empty...");
    }
    else{
        struct node* q=top;
        int d=q->data;
        top=top->prev;
        free(q);
        
    printf("%d element deleted...",d);
    }

}
void traverse(){
    if(top==NULL){
        printf("Element deleted...");
    }
    else{
        struct node* q=top;
        while(q!=NULL){
            printf("%d\n",q->data);
            q=q->prev;
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
