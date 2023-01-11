// // Representation of stack using Array
#include <stdio.h>
#include <stdlib.h>
#define max 10
int a[10];
int top = -1;
void push();
void pop();
void traverse();
int main()
{
    int ch;
    do
    {
        printf("\n 1.push \n 2.pop \n 3.travese \n 4.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("wrong choice");
            break;
        }
    } while (ch != 4);
}
int isFull()
{
    if (top == max - 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int isEmpty()
{
    if (top == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void push()
{
    if (isFull())
    {
        int e;
        printf("Enter element\n");
        scanf("%d", &e);
        ++top;
        a[top] = e;
        printf("Element inserted...\n");
    }
    else
    {

        printf("stack full");
    }
}
void pop()
{
    if (isEmpty())
    {
        int d;
        d = a[top];
        top--;
        printf("%d is deleted from stack\n", d);
    }
    else
    {

        printf("stack is empty");
    }
}
void traverse()
{
    if (isEmpty())
    {
        for (int i = top; i >= 0; i--)
        {
            printf("\n%d", a[i]);
        }
    }
    else
    {

        printf("satck is empty");
    }
}
