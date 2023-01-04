#include<stdio.h>
#include<stdlib.h>
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
void mul(struct node* poly1,struct node* poly2,struct node* poly){
    while(poly1->next&&poly2->next){
        if(poly1->p>poly2->p){
            poly->c=poly1->c;
            poly->p=poly1->p;
            poly1=poly1->next;
        }
        else if(poly1->p<poly2->p){
            poly->c=poly2->c;
            poly->p=poly2->p;
            poly2=poly2->next;
        }
        else{
            poly->c=poly1->c*poly2->c;
            poly->p=poly1->p;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        poly->next=(struct node*)malloc(sizeof(struct node));
        poly=poly->next;
        poly->next=NULL;
    }
    while(poly1->next||poly2->next){
        if(poly1->next){
            poly->c=poly1->c;
            poly->p=poly1->p;
            poly1=poly1->next;
        }
        if(poly1->next){
            poly->c=poly2->c;
            poly->p=poly2->p;
            poly2=poly2->next;
        }
        poly->next=(struct node*)malloc(sizeof(struct node));
        poly=poly->next;
        poly->next=NULL;
    }
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
    struct node* poly1=NULL,*poly2=NULL,*poly=NULL;
    create(5,3,&poly1);
    create(10,2,&poly1);
    create(7,0,&poly1);
    create(25,2,&poly2);
    create(3,1,&poly2);
    printf("\n Polynomial1= ");
    show(poly1);
    printf("\n Polynomial2= ");
    show(poly2);

    poly=(struct node*)malloc(sizeof(struct node));
    mul(poly1,poly2,poly);
    printf("\n Multiplication of two polynomials= ");
    show(poly);
    return 0;
}