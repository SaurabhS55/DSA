// circular queue implementation using array
#include <stdio.h>
#include <stdlib.h>
#define max 10
int q[max], r = -1, f = -1;
void enque()
{
    if ((r==max-1 && f==0)||(r == (f-1)%max))
    {
        printf("\n Queue overflow");
    }
    else {
    if (f == -1 && r==-1)
    {
        f = 0;
        r=0;
    }
    else
    {
       
    r = (r + 1) % max;
        
    }
    printf("\n Enter element\n");
    int ele;
    scanf("%d", &ele);
    q[r] = ele;
    }
}
void deque()
{
    if (f == -1)
    {
        printf("\n Queue underflow");
    }
    else
    {
        int d;
        d = q[f];
        if (f == r)
        {
            r = -1;
            f = -1;
        }
        else
        {
            f = (f + 1) % max;
        }
        printf("%d is deleted from queue..", d);
    }
}
void traverse()
{
    if (f == -1)
    {
        printf("\n queue underflow");
    }
    else if (f <= r)
    {
        for (int i = f; i <= r; i++)
        {
            printf("%d ", q[i]);
        }
    }
    else
    {
        for (int i = f; i < max; i++)
        {
            printf("%d ", q[i]);
        }
        for (int i = 0; i <= r; i++)
        {
            printf("%d ", q[i]);
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
