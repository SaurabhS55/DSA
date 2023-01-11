#include <stdio.h>
#include <stdlib.h>
#define max 10
int q[max], f = -1, r = -1;
void enque_r()
{
    if ((f == 0 && r == max - 1) || f == r + 1)
    {
        printf("queue overflow");
    }
    else
    {
        if (r == -1)
        {
            f = 0;
            r = 0;
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
void enque_f()
{
    if ((f == 0 && r == max - 1) || f == r + 1)
    {
        printf("queue overflow");
    }
    else
    {
        if (f == -1)
        {
            f = 0;
            r = 0;
        }
        else if (f == 0)
        {
            f = max - 1;
        }
        else
        {
            f--;
        }
        printf("\n Enter element\n");
        int ele;
        scanf("%d", &ele);
        q[f] = ele;
    }
}
void deque_r()
{
    if (f == -1 && r == -1)
    {
        printf("queue is underflow");
    }
    else
    {
        int d = q[r];
        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else if (r == 0)
        {
            r = max - 1;
        }
        else
        {
            r--;
        }
        printf("%d is deletedd from queue \n", d);
    }
}
void deque_f()
{
    if (f == -1 && r == -1)
    {
        printf("queue is underflow");
    }
    else
    {
        int d = q[f];
        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f = (f + 1) % max;
        }
        printf("%d is deletedd from queue \n", d);
    }
}
void getfront()
{
    if (f == -1 && r == -1)
    {
        printf("queue is underflow");
    }
    else
    {
        printf("\n Front=%d ", q[f]);
    }
}
void getrear()
{
    if (f == -1 && r == -1)
    {
        printf("queue is underflow");
    }
    else
    {
        printf("\n Rear=%d ", q[r]);
    }
}
void traverse()
{
    if (f == -1 && r == -1)
    {
        printf("queue is underflow");
    }
    else
    {
        for (int i = f; i != r; i++)
        {
            printf("%d ", q[i]);
        }
        printf("%d ", q[r]);
    }
}
int main()
{
    int ch;
    do
    {
        printf("\n 1.enque_r \n 2.enque_f \n 3.deque_r \n 4.deque_f \n 5.travese \n 6.getfront \n 7.getrear \n 8.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enque_r();
            break;
        case 2:
            enque_f();
            break;
        case 3:
            deque_r();
            break;
        case 4:
            deque_f();
            break;
        case 5:
            traverse();
            break;
        case 6:
            getfront();
            break;
        case 7:
            getrear();
            break;
        case 8:
            exit(-1);
            break;

        default:
            printf("wrong choice");
            break;
        }
    } while (ch != 8);
    return 0;
}
