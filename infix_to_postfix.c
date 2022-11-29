#include<stdio.h>
    char st[20];
    int top=-1;
void push(char c){
    top++;
    st[top]=c;
}
void pop(){
    char c=st[top];
    --top;
    
}
int prec(char c){
    if(c=='$'||c=='^'){
        return 3;
    }
    else if(c=='+'||c=="-"){
        return 1;
    }
    else if(c=="*"||c=="/"){
        return 2; 
    }
    else{
        return -1;
    }
}
void toPostfix(char s[20]){
    char r[20];
    // create_stack(sizeof(s));
    for(int i=0;s[i]!='\0';i++){
        char c=s[i];
        if(c>='a'&& c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9'){
            r[i]+=c;
        }
        else if(c=='('){
            push(c);
        }
        else if(c==")"){
            while(st[top]!='('){
                r[i]+=st[top];
                pop();
            }
            pop();
        }
        else{
            while(st[top]!=-1&&prec(s[i])<=prec(st[top])){
                r[i]+=st[top];
                pop();
            }
            push(c);
        }
    
    // int i=-1;
    while(st[top]!=-1){
        r[i]+=st[top];
        pop();
    }
    }
    for(int i=0;r[i]!='\0';i++){
        printf("%c",r[i]);
    }

}
int main(){
    char s[]="(a+b)*c";
    toPostfix(s);
    return 0;
}