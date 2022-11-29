// string reverse representation of stack using array
#include<stdio.h>
#define max 10
char stack[max],top=-1;
void push(char c){
    if(top==max){
        printf("stack is full");
    }
    else{
        top++;
        stack[top]=c;
    }
}
char pop(){
    if(top==-1){
        printf("stack is empty");
    }
    else{
        char d=stack[top];
        top--;
        return d;
    }
}
int main(){
    char ch[max];
    printf("Enter your String\n");
    for(int i=0;i<max;i++){
        scanf("%c",&ch[i]);
    }
    for(int i=0;i<sizeof(ch);i++){
        push(ch[i]);
    }
    
    for(int i=0;i<sizeof(ch);i++){
            printf("%c",pop());
        
    }
    
}
