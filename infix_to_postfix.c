// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// struct Stack{
//     int top;
//     unsigned capacity;
//     int *array;
// };
// struct Stack* createStack(unsigned capacity){
//     struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
//     if(!stack)
//         return NULL;
//     else{
//         stack->top=-1;
//         stack->capacity=capacity;
//         stack->array=(int*)malloc(stack->capacity*sizeof(int));
//         return stack;
//     }
// }
// int isempty(){
//     return t1==-1;
// }
// char pop1(){
//     if(!isempty()){
//         char c=st1[t1];
//         --t1;
//         return c;
//     }
// }
// void push1(char c){
//     if(t1!=max){
//         ++t1;
//         st1[t1]=c;
//     }
// }
// void push2(char c){
//     if(t2!=max){
//         ++t2;
//         st2[t2]=c;
//     }
// }
// char peep(){
//     if(!isempty()){
//         return st1[t1];
//     }
// }
// int prec(char c){
//     switch (c)
//     {
//     case '^':
//     case '$':return 3;
//     case '+':
//     case '-':return 1;
//     case '*':
//     case '/':return 2;
//     default:
//         return -1;
//     }
// }
// void topostfix(){
//     char s[]="a+b*c";
//     // printf("\n Enter expression:\n");
//     // gets(s);
//     int i,j;
//     char r[strlen(s)];
//     struct Stack* stack=createStack(strlen(s));
//     printf("Infix :%s\n",s);
//     for(i=0;i<strlen(s);i++){
//         char c=s[i];
//         if(c>='a'&&c<='z'||c>='A'&&c<='Z'||c>=0&&c<=9){
//             r[i]+=c;
//         }
//         else if(c=='('){
//             stack->array[++stack->top]=c;
//         }
//         else if(c==')'){
//             while(stack->top!='('){
//                 r[i]+=stack->array[stack->top];
//                 --stack->top;
//             }
//             --stack->top;
//         }
//         else if(c=='^'||c=='+'||c=='-'||c=='*'||c=='/'||c=='$'){
//             while(stack->top!=-1 && prec(s[i])<=prec(stack->array[stack->top])){
//                 r[i]+=stack->array[stack->top];
//                 --stack->top;
//             }
//             stack->array[++stack->top]=c;
//         }
//         else{
//             while(stack->top!=-1){
//                 r[i]+=stack->array[stack->top];
//                 --stack->top;
//     }
//         }
//     }

//     printf("postfix :%s",r);

// }
// int main(){
//     // char *s;

//     // s=ch;
//     topostfix();
//     return 0;
// }

// C program to convert infix expression to postfix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack type
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

// Stack Operations
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (int *)malloc(stack->capacity * sizeof(int));

    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack *stack, char op)
{
    stack->array[++stack->top] = op;
}

// A utility function to check if
// the given character is operand
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// A utility function to return
// precedence of a given operator
// Higher returned value means
// higher precedence
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

// The main function that
// converts given infix expression
// to postfix expression.
int infixToPostfix(char *exp)
{
    int i, k;

    // Create a stack of capacity
    // equal to expression size
    struct Stack *stack = createStack(strlen(exp));
    if (!stack) // See if stack was created successfully
        return -1;
    printf("\nInfix:%s", exp);
    for (i = 0, k = -1; exp[i]; ++i)
    {

        // If the scanned character is
        // an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (exp[i] == '(')
            push(stack, exp[i]);

        // If the scanned character is an ‘)’,
        // pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; // invalid expression
            else
                pop(stack);
        }

        else // an operator is encountered
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }

    // pop all the operators from the stack
    while (!isEmpty(stack))
        exp[++k] = pop(stack);

    exp[++k] = '\0';
    printf("\nPostfix:%s", exp);
}
int infixToPrefix(char *exp)
{
    int i, k;

    // Create a stack of capacity
    // equal to expression size

    struct Stack *stack = createStack(strlen(exp));
    if (!stack) // See if stack was created successfully
        return -1;
    // printf("\nInfix:%s", strrev(exp));
    for (i = 0, k = -1; exp[i]; ++i)
    {

        // If the scanned character is
        // an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (exp[i] == ')')
            push(stack, exp[i]);

        // If the scanned character is an ‘)’,
        // pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (exp[i] == '(')
        {
            while (!isEmpty(stack) && peek(stack) != ')')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != ')')
                return -1; // invalid expression
            else
                pop(stack);
        }

        else // an operator is encountered
        {
            while (!isEmpty(stack) && Prec(exp[i]) < Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }

    // pop all the operators from the stack
    while (!isEmpty(stack))
        exp[++k] = pop(stack);

    exp[++k] = '\0';
    printf("\nPrefix:%s", strrev(exp));
}

// Driver's code
int main()
{
    char exp[25];
    printf("Enter Expression:");
    gets(exp);

    // Function call
    infixToPostfix(exp);
    infixToPrefix(strrev(exp));
    return 0;
}
