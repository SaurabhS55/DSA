#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *start;
struct node *create(int ele)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->next = NULL;
    return temp;
}
void insertatbeg(struct node *temp)
{
    if (start == NULL)
    {
        start = temp;
        start->next = start;
    }
    else
    {
        struct node *q = start;
        while (q->next != start)
        {
            q = q->next;
        }
        temp->next = start;
        start = temp;
        q->next = start;
    }
}
void insertatend(struct node *temp)
{
    if (start == NULL)
    {
        start = temp;
        start->next = start;
    }
    else
    {
        struct node *q = start;
        while (q->next != start)
        {
            q = q->next;
        }
        q->next = temp;
        temp->next = start;
    }
}
void insertatpos(struct node *temp, int pos)
{
    if (start == NULL)
    {
        start = temp;
        start->next = start;
    }
    else
    {

        struct node *q = start;
        for (int i = 0; i < pos - 1; ++i)
        {
            q = q->next;
        }
            temp->next = q->next;
            q->next = temp;
    }
}
void insertafternode(struct node *temp, int d)
{
    if (start == NULL)
    {
        start = temp;
        start->next = start;
    }
    else
    {
        struct node *q = start;
        while (q->data != d)
        {
            q = q->next;
        }
            temp->next = q->next;
            q->next = temp;
    }
}
void deleteatbeg()
{
    if (start == NULL)
    {
        printf("\n List is empty..");
    }
    else
    {
        struct node *q = start;
        struct node *r = q;
        while (r->next != start)
        {
            r = r->next;
        }
        int d = q->data;
        start=start->next;
        r->next = start;
        printf("\n%d is deleted from list..", d);
        free(q);
    }
}
void deleteatend()
{
    if (start == NULL)
    {
        printf("\n List is empty..");
    }
    else
    {
        struct node *q = start;
        struct node *r = q->next;
        while (r->next != start)
        {
            r = r->next;
            q = q->next;
        }
        int d = r->data;
        free(r);
        q->next = start;
        printf("\n%d is deleted from list..", d);
    }
}
void deleteatpos(int pos)
{
    if (start == NULL)
    {
        printf("\n List is empty..");
    }
    else
    {
        struct node *q = start;
        struct node *r = q->next;
        for (int i = 0; i < pos - 1; ++i)
        {
            q = q->next;
            r = r->next;
        }
            int d = r->data;
            q->next = r->next;
            r->next = NULL;
            printf("\n%d is deleted from list..");
            free(r);
    }
}
void deleteafternode(int d)
{
    if (start == NULL)
    {
        printf("\n List is empty..");
    }
    else
    {
        struct node *q = start;
        struct node *r = q->next;
        while (r->data != d)
        {
            q = q->next;
            r = r->next;
        }
            int d = r->data;
            q->next = r->next;
            r->next = NULL;
            printf("\n%d is deleted from list..");
            free(r);
    }
}
void traverse()
{
    if (start == NULL)
    {
        printf("\n List is empty..");
    }
    else
    {
        struct node *q = start;
        do
        {
            printf("%d ", q->data);
            q = q->next;
        } while (q != start);
    }
}
void count()
{
    if (start == NULL)
    {
        printf("\n List is empty..");
    }
    else
    {
        struct node *q = start;
        int c = 0;
        do
        {
            ++c;
            q = q->next;
        } while (q != start);
        printf("count=%d", c);
    }
}
void search(int key)
{
    if (start == NULL)
    {
        printf("\n List is empty..");
    }
    else
    {
        struct node *q = start;
        int f = 0, pos = 0;
        do
        {
            if (key == q->data)
            {
                f = 1;
                break;
            }
            ++pos;
            q = q->next;
        } while (q != start);
        if (f == 1)
        {
            printf("element %d found at position %d", key, pos);
        }
        else
        {
            printf("element not found");
        }
    }
}
int main()
{
    // node n;
    int choice = 0, pos, d, key,ele;
    struct node *temp;
    do
    {
        printf("\nselect which operation you want to perform on list:-\n1.Insertion\n2.Deletion\n3.Travering\n4.serching node\n5.counting nodes\n6.exit");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nyou have selected insertion operation\n\nwhat do you want?\n1.insert at beginning\n2.insert at end\n3.insert at given position\n4.insert after node\n");
            int ch;
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                printf("\n Enter data\n");
                scanf("%d", &ele);
                temp = create(ele);
                insertatbeg(temp);
                break;
            case 2:
                printf("\n Enter data\n");
                scanf("%d", &ele);
                temp = create(ele);
                insertatend(temp);
                break;
            case 3:
                printf("\n Enter data\n");
                scanf("%d", &ele);
                temp = create(ele);
                printf("\n Enter position\n");
                int pos;
                scanf("%d", &pos);
                insertatpos(temp, pos);
                break;
            case 4:
                printf("\n Enter data\n");
                scanf("%d", &ele);
                temp = create(ele);
                printf("\n Enter node value\n");
                int d;
                scanf("%d", &d);
                insertafternode(temp, d);
                break;
            default:
                printf("\nwrong choice\n");
            }
            break;
        case 2:
            printf("\nyou have selected deletion operation\n\nwhat do you want?\n1.delete at beginning\n2.delete at end\n3.delete at given position\n4.delete after node\n");
            // int ch;
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                deleteatbeg();
                break;
            case 2:
                deleteatend();
                break;
            case 3:
                printf("\n Enter position\n");
                int pos;
                scanf("%d", &pos);
                deleteatpos(pos);
                break;
            case 4:
                printf("\n Enter node value\n");
                int d;
                scanf("%d", &d);
                deleteafternode(d);
                break;
            default:
                printf("\nwrong choice\n");
            }
            break;
        case 3:
            printf("\nYou have selected travesing operation\n");
            traverse();
            break;
        case 4:
            printf("\nYou have selected searching node operation\n");
            printf("Enter key");
            scanf("%d", &key);
            search(key);
            break;
        case 5:
            printf("\nYou have selected counting node operation\n");
            count();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nwrong choice\n");
        }
    } while (choice != 6);
    return 0;
}