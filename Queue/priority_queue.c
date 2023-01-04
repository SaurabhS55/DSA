#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define max 10
struct item
{
	int value;
	int priority;
};
struct item pr[max];
int size = -1;
void enque()
{
	if (size == max - 1)
	{
		printf("\n Queue is overflow");
	}
	else
	{
		int ele, p;
		printf("\n Enter data ");
		scanf("%d", &ele);
		printf("\n Enter priority ");
		scanf("%d", &p);
		size++;
		pr[size].value = ele;
		pr[size].priority = p;
	}
}
int peek()
{
	if (size == -1)
	{
		printf("\n Queue is underflow");
	}
	else
	{
		int highestPriority = INT_MIN;
		int ind = -1;
		for (int i = 0; i <= size; i++)
		{
			if (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value)
			{
				highestPriority = pr[i].priority;
				ind = i;
			}
			else if (highestPriority < pr[i].priority)
			{
				highestPriority = pr[i].priority;
				ind = i;
			}
		}
		return ind;
	}
}
void deque()
{
	if (size == -1)
	{
		printf("\n Queue is underflow");
	}
	else
	{
		int ind = peek();
		printf("(%d,%d) is deleted... ", pr[ind].value, pr[ind].priority);
		for (int i = ind; i < size; i++)
		{
			pr[i] = pr[i + 1];
		}
		size--;
	}
}
void display()
{
	if (size == -1)
	{
		printf("\n Queue is underflow");
	}
	else
	{
		for (int i = 0; i <= size; i++)
		{
			printf("(%d, %d) ", pr[i].value, pr[i].priority);
		}
	}
}
int main()
{
	int ch;
	do
	{
		printf("\n 1.enque \n 2.deque \n 3.display \n 4.exit\n");
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
			display();
			break;
		case 4:
			exit(-1);
			break;

		default:
			printf("wrong choice");
			break;
		}
	} while (ch != 4);
	return 0;
}
