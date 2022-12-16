#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    int c;
    int p;
    struct node* next;
};
void create(int c,int p,struct node** temp){
    struct node *r,*z;
    z=*temp;
    if(z==NULL){
        r=(struct node*)malloc(sizeof(struct node));
        r->c=c;
        r->p=p;
        *temp=r;
        r->next=(struct node*)malloc(sizeof(struct node));
        r=r->next;
        r->next=NULL;
    }
    else{
        r->c=c;
        r->p=p;
        r->next=(struct node*)malloc(sizeof(struct node));
        r=r->next;
        r->next=NULL;
    }
}
void eval(struct node* poly,int x){
    int e=0;
    while(poly->next!=NULL){
        e+=poly->c*pow(x,poly->p);
        poly=poly->next;
    }
    printf("value of polynomial= %d",e);
}
void show(struct node* temp){
    while(temp->next!=NULL){
        printf("%dx^%d",temp->c,temp->p);
        temp=temp->next;
        if(temp->c>0){
            if(temp->next!=NULL){
                printf("+");
            }
        }
    }
}
int main(){
    struct node* poly=NULL;
    int x;
    create(5,3,&poly);
    create(10,2,&poly);
    create(7,0,&poly);
    printf("\n Polynomial = ");
    show(poly);
    printf("\n Enter value of x: ");
    scanf("%d",&x);
    eval(poly,x);
    return 0;
}