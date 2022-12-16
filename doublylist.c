#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
}*start;
struct node* create(int ele){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
void insertatbeg(struct node* temp){
    if(start==NULL){
        start=temp;
    }
    else{
        temp->next=start;
        start->prev=temp;
        start=temp;
    }
}
void insertatend(struct node* temp){
    if(start==NULL){
        start=temp;
    }
    else{
        struct node* q=start;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=temp;
        temp->prev=q;
    }
}
void insertatpos(struct node* temp,int pos){
    if(start==NULL){
        start=temp;
    }
    else{
        struct node* q=start;
        for(int i=0;i<pos-1;++i){
            q=q->next;
        }
        q->next->prev=temp;
        temp->next=q->next;
        q->next=temp;
        temp->prev=q;
    }
}
void deleteatbeg(){
    if(start==NULL){
        printf("\n List is empty..");
    }
    else{
        struct node *q=start;
        int d=q->data;
        start=start->next;
        start->prev=NULL;
        free(q);
        printf("\n %d is deleted from list..",d);
    }
}
void deleteatend(){
    if(start==NULL){
        printf("\n List is empty..");
    }
    else{
        struct node *q=start;
        // struct node *r=q->next;
        while(q->next!=NULL){
            q=q->next;
            // r=r->next;
        }
        int d=q->data;
        q->prev->next=NULL;
        free(q);
        printf("\n %d is deleted from list..",d);
    }
}
void deleteatpos(int pos){
    if(start==NULL){
        printf("\n List is empty..");
    }
    else{
        struct node *q=start;
        struct node *r=q->next;
        for (int i=0;i<pos-1;++i){
            q=q->next;
            r=r->next;
        }
        int d=r->data;
        q->next=r->next;
        r->next->prev=q;
        free(r);
        printf("\n %d is deleted from list..",d);
    }
}
void traverse(){
    if(start==NULL){
        printf("\n List is empty..");
    }
    else{
        struct node* q=start;
        while (q!=NULL)
        {
            printf("%d ",q->data);
            q=q->next;
        }
        
    }
}
int main()
{
    // node n;
    int choice = 0, pos,ele;
    struct node *temp;
    do
    {
        printf("\nselect which operation you want to perform on list:-\n1.Insertion\n2.Deletion\n3.Travering\n4.exit");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nyou have selected insertion operation\n\nwhat do you want?\n1.insert at beginning\n2.insert at end\n3.insert at given position\n");
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
            default:
                printf("\nwrong choice\n");
            }
            break;
        case 2:
            printf("\nyou have selected deletion operation\n\nwhat do you want?\n1.delete at beginning\n2.delete at end\n3.delete at given position\n");
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
            default:
                printf("\nwrong choice\n");
            }
            break;
        case 3:
            printf("\nYou have selected travesing operation\n");
            traverse();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nwrong choice\n");
        }
    } while (choice != 4);
    return 0;
}