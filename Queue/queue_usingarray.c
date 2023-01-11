// using array

#include <stdio.h>
#include <stdlib.h>
#define max 10
int queue[max], front = -1, rear = -1;
void enque()
{
    if (rear == max - 1)
    {
        printf("Queue overflow...");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            ++rear;
        }

        printf("\nEnter element\n");
        int ele;
        scanf("%d", &ele);
        queue[rear] = ele;
    }
}
void deque()
{
    if (front == -1)
    {
        printf("Queue underflow...");
    }
    else
    {
        int d = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            ++front;
        }
        // front++;
        printf("%d is deleted from queue..\n", d);
    }
}
void traverse()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty..");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
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
