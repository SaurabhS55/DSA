// #include<stdio.h>
// #include<string.h>
// #include<math.h>
// #include<stdlib.h>
// #include<ctype.h>
// #define max 50
// int st[max],top=-1;
// void push(int);
// int pop();
// int main(){
//    char ch[max],c;
//    int result,o1,o2;
//     printf("\n use '_' if you want space ' ' ");
//    printf("\n Enter postfix expression");
//    gets(ch);
//    for(int i=0;ch[i]!='\0';++i){
//       c=ch[i];
//       if(isdigit(c)){
//          push(c-'0');
//       }
//       else if(c=='_'){
//          continue;
//       }
//       else{
//          int temp;
//          o2=pop();
//          o1=pop();
//          switch(c){
//             case '+':temp=o1+o2;
//                      break;
//             case '*':temp=o1*o2;
//                      break;
//             case '-':temp=o1-o2;
//                      break;
//             case '/':temp=o1/o2;
//                      break;
//             case '^':
//             case '$':temp=pow(o1,o2);
//                      break;
//          }
//          push(temp);

//       }

//    }
//    result=pop();
//    printf("Evaluation of %s expression = %d",ch,result);
//    return 0;
// }
// void push(int c){
//       ++top;
//       st[top]=c;
// }
// int pop(){
//       top--;
//       return st[top];
// }


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 40

int pop();
void push(int);

char postfix[SIZE];
int stack[SIZE], top = -1;

int main()
{
	int i, a, b, result, pEval;
	char ch;
	
	for(i=0; i<SIZE; i++)
	{
		stack[i] = -1;
	}
	printf("\nEnter a postfix expression: ");
	scanf("%s",postfix);

	for(i=0; postfix[i] != '\0'; i++)
	{
		ch = postfix[i];

		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			b = pop();
			a = pop();
			
			switch(ch)
			{
				case '+': result = a+b;
					  break;
				case '-': result = a-b;
					  break;
				case '*': result = a*b;
					  break;
				case '/': result = a/b;
					  break;
				case '%':result = a%b;
					  break;
			}
			
			push(result);
		}		
	
	}

	pEval = pop();
	
	printf("\nThe postfix evaluation is: %d\n",pEval);
	
	return 0;
}

void push(int n)
{
	if (top < SIZE -1)
	{
		stack[++top] = n;
	}
	else
	{
		printf("Stack is full!\n");
		exit(-1);
	}
}
int pop()
{	
	int n;
	if (top > -1)
	{
		n = stack[top];
		stack[top--] = -1;
		return n;
	}
	else
	{
		printf("Stack is empty!\n");
		exit(-1);
	}
}	