// stack representation using singly linked representation

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *top;
void push()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int ele;
    printf("Enter element\n");
    scanf("%d", &ele);
    temp->data = ele;
    temp->next = NULL;
    temp->next = top;
    top = temp;
    printf("%d pushed on stack", ele);
}
void pop()
{
    if (top == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        struct node *q = top;
        int d = q->data;
        top = top->next;
        printf("%d is deleted from stack...", d);
        free(q);
    }
}
void traverse()
{
    if (top == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        struct node *q = top;
        while (q != NULL)
        {
            printf("\n%d", q->data);
            q = q->next;
        }
    }
}
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
    return 0;
}