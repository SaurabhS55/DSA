// using linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *rear, *front;
void enque()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int ele;
    printf("\nEnter element:\n");
    scanf("%d", &ele);
    temp->data = ele;
    temp->next = NULL;
    if (rear == NULL)
    {
        rear = temp;
        front = rear;
    }
    else
    {
        rear->next = temp;
        rear = rear->next;
    }
}
void deque()
{
    if (front == NULL)
    {
        printf("queue is empty..");
    }
    else if (front->data > rear->data)
    {
        rear->next = NULL;
        front->next = NULL;
    }
    else
    {
        int d = front->data;
        front = front->next;
        printf("\n %d is deleted from queue...", d);
    }
}
void traverse()
{
    if (front == NULL && rear == NULL)
    {
        printf("queue is empty..");
    }
    else
    {
        struct node *q = front;
        while (q != NULL)
        {
            printf("%d ", q->data);
            q = q->next;
        }
        // front->next=NULL;
        // rear->next=NULL;
    }
}
int main()
{
    int ch;
    do
    {
        printf("\n 1.enque \n 2.deque \n 3.travese \n 4.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
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
