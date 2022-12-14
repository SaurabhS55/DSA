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
    scanf("%s",ch);
    for(int i=0;ch[i]!='\0';i++){
        push(ch[i]);
    }
    
    for(int i=0;i<ch[i]!='\0';i++){
            printf("%c",pop());
        
    }
    
}
