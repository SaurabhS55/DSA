#include <stdio.h>
#include <conio.h>
struct node
{
    int data;
    struct node *next;
} *start;
void insertatbeg()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int ele;
    printf("\nEnter data\n");
    scanf("%d", &ele);
    temp->data = ele;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}
void insertatend()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int ele;
    printf("\nEnter data");
    scanf("%d", &ele);
    temp->data = ele;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node *q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = temp;
    }
}
void insertatpos()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int ele;
    printf("\nEnter data");
    scanf("%d", &ele);
    temp->data = ele;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        printf("\nEnter position");
        int pos;
        scanf("%d", &pos);
        struct node *q = start;
        for (int i = 0; i < pos - 1; i++)
        {
            q = q->next;
        }
        temp->next = q->next;
        q->next = temp;
    }
}
void insertafternode()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int ele;
    printf("\nEnter data");
    scanf("%d", &ele);
    temp->data = ele;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        int val;
        printf("Enter node value");
        scanf("%d", &val);
        struct node *q = start;
        while (q->data != val)
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
        printf("List is empty");
    }
    else
    {
        struct node *q = start;
        int data = q->data;
        printf("%d is deleted from list", data);
        free(q);
    }
}
void deleteatend()
{
    if (start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct node *q = start;
        struct node *r = q->next;
        while (r->next != NULL)
        {
            q = q->next;
            r = r->next;
        }
        int data = r->data;
        q->next = NULL;
        printf("%d is deleted from list", data);
        free(r);
    }
}
void deleteatpos()
{
    if (start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("\nEnter position");
        int pos;
        scanf("%d", &pos);
        struct node *q = start;
        struct node *r = q->next;
        for (int i = 0; i < pos - 1; i++)
        {
            q = q->next;
            r = r->next;
        }
        int data = r->data;
        q->next = r->next;
        r->next = NULL;
        printf("%d is deleted from list", data);
        free(r);
    }
}
void deleteafternode()
{
    if (start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("\nEnter value");
        int val;
        scanf("%d", &val);
        struct node *q = start;
        struct node *r = q->next;
        while (r->data != val)
        {
            q = q->next;
            r = r->next;
        }
        q->next = r->next;
        r->next = NULL;
        int data = r->data;
        printf("%d is deleted from list", data);
        free(r);
    }
}
void traverse()
{
    if (start == NULL)
    {
        printf("list is empty");
    }
    else
    {
        struct node *q = start;
        do
        {
            printf("%d\t", q->data);
            q = q->next;
        }while (q!= NULL);
    }
}
void count()
{
    if (start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        int c = 0;
        struct node *q = start;
        while (q != NULL)
        {
            c++;
            q = q->next;
        }
        printf("list has %d elements", c);
    }
}
void search()
{
    if (start == NULL)
    {
        printf("list is empty");
    }
    else
    {
        int key, f = 0, pos = 0;
        printf("Enter key");
        scanf("%d", &key);
        struct node *q = start;
        while (q != NULL)
        {
            if (key == q->data)
            {
                f = 1;
                break;
            }
            ++pos;
            q = q->next;
        }
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
    int choice = 0;
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
                insertatbeg();
                break;
            case 2:
                insertatend();
                break;
            case 3:
                insertatpos();
                break;
            case 4:
                insertafternode();
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
                deleteatpos();
                break;
            case 4:
                deleteafternode();
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
            search();
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
    // insertatbeg();
    // insertatbeg();
    // insertatend();
    // insertatpos();
    // traverse();
    // search();
    // count();
    return 0;
}