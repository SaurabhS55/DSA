#include<stdio.h>
int a[4],top=-1;
void push(int r){
    if(top==sizeof(a)){
        printf("stack is full");
    }
        ++top;
        a[top]=r;
}
int pop(){
    if(top==-1){
        printf("stack is empty");
    }
    int r=a[top];
    --top;
    return r;
}
    
int main(){
    printf("Enter any decimal number\n");
    int d;
    scanf("%d",&d);
    int p;
    printf("%d decimal to binary is ",d);
    int t=d;
    while(d!=0){
        int r=d%2;
        push(r);
        d=d/2;
    }
    while(t!=0){
        printf("%d",pop());
        t=t/2;
    }
    return 0;
}