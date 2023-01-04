#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    
}*start;
void insertatbeg(){
    node *temp;
    temp=new node();
    int ele;
    cout<<"Enter data"<<endl;
    cin>>ele;
    temp->data=ele;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }
    else{
        temp->next=start;
        start=temp;
    }
}
void insertatend(){
    node *temp;
    temp=new node();
    int ele;
    cout<<"Enter data"<<endl;
    cin>>ele;
    temp->data=ele;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }
    else{
        node* q=start;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=temp;
    }
}
void insertatpos(){
    node *temp;
    temp=new node();
    int ele;
    cout<<"Enter data"<<endl;
    cin>>ele;
    temp->data=ele;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }
    else{
        int p;
        cout<<"Enter position on which you want to insert node"<<endl;
        cin>>p;
        node* q=start;
        for(int i=0;i<p-2;i++){
            q=q->next;
        }
        temp->next=q;
        q->next=temp;
    }
}
void insertafternode(){
    node *temp=new node();
    int ele;
    cout<<"Enter data"<<endl;
    cin>>ele;
    temp->data=ele;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }
    else{
        int d;
        cout<<"Enter node value after which you want to insert node"<<endl;
        cin>>d;
        node* q=start;
        while(q->data!=d){
            q=q->next;
        }
        temp->next=q->next;
        q->next=temp;
    }
}
void deleteatbeg(){
    node* temp=new node();
    if(start==NULL){
        cout<<"List is empty";
    }
    else{
        node* q=start;
        int data=q->data;
        start=start->next;
        q->next=NULL;
        cout<<q->data<<" removed from list";
        delete(q);

    }
}
void deleteatend(){
    node* temp=new node();
    if(start==NULL){
        cout<<"List is empty";
    }
    else{
        node* q=start;
        node* r=q->next;
        while(r->next!=NULL){
            q=q->next;
            r=r->next;
        }
        int data=r->data;
        q->next=NULL;
        cout<<r->data<<" removed from list";
        delete(r);

    }
}
void deleteatpos(){
    node* temp=new node();
    if(start==NULL){
        cout<<"List is empty";
    }
    else{
        node* q=start;
        node* r=q->next;
        int pos;
        cout<<"\n Enter pos of node which you want to delete"<<endl;
        cin>>pos;
        for(int i=0;i<pos-2;i++){
            q=q->next;
            r=r->next;
        }
        int data=r->data;
        q->next=r->next;
        r->next=NULL;
        cout<<r->data<<" removed from list";
        delete(r);

    }
}
void deleteafternode(){
    node* temp=new node();
    if(start==NULL){
        cout<<"List is empty";
    }
    else{
        node* q=start;
        node* r=q->next;
        int d;
        cout<<"\n Enter node value"<<endl;
        cin>>d;
        while(r->data!=d){
            q=q->next;
            r=r->next;
        }
        int data=r->data;
        q->next=r->next;
        r->next=NULL;
        cout<<r->data<<" removed from list";
        delete(q);

    }
}
void search(){
    node* temp=new node();
    if(start==NULL){
        cout<<"List is empty";
    }
    else{
        int key,f=0,pos=0;
        cout<<"Enter a key which you want to search"<<endl;
        cin>>key;
        node *q=start;
        while(q->next!=NULL){
            if(q->data==key){
                f=1;
                break;
            }
            q=q->next;
            ++pos;
        }
        if(f==1){
            cout<<"element "<<key<<" found at position "<<pos;
        }
        else{
            cout<<"element "<<key<<" not found ";
        }
    }
}
void count(){
    node* temp=new node();
    if(start==NULL){
        cout<<"List is empty";
    }
    else{
        int c=0;
        node* q=start;
        while(q->next!=NULL){
            ++c;
            q=q->next;
        }
        cout<<"List has"<<c<<" nodes";
    }
}
void traverse(){
    node *temp;
    temp=new node();
    if(start==NULL){
        cout<<"List is empty";
    
    }
    else{
        node* q=start;
        while(q!=NULL){
            cout<<q->data<<"\t";
            q=q->next;
        }
    }
}

int main(){
    // node n;
    int choice=0;
    do{
        cout<<"\nselect which operation you want to perform on list:-\n1.Insertion\n2.Deletion\n3.Travering\n4.serching node\n5.counting nodes\n6.exit";
        cout<<"\nEnter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:cout<<"\nyou have selected insertion operation\n\nwhat do you want?\n1.insert at beginning\n2.insert at end\n3.insert at given position\n4.insert after node"<<endl;
                    int ch;
                    cin>>ch;
                    switch(ch){
                        case 1:insertatbeg();
                        break;
                        case 2:insertatend();
                        break;
                        case 3:insertatpos();
                        break;
                        case 4:insertafternode();
                        break;
                        default:cout<<"\nwrong choice";
                    }
                    break;
            case 2:cout<<"\nyou have selected deletion operation\n\nwhat do you want?\n1.delete at beginning\n2.delete at end\n3.delete at given position\n4.delete after node"<<endl;
                    // int ch;
                    cin>>ch;
                    switch(ch){
                        case 1:deleteatbeg();
                        break;
                        case 2:deleteatend();
                        break;
                        case 3:deleteatpos();
                        break;
                        case 4:deleteafternode();
                        break;
                        default:cout<<"\nwrong choice";
                    }
                    break;
            case 3:cout<<"\nYou have selected travesing operation"<<endl;
                    traverse();
                    break;
            case 4:cout<<"\nYou have selected searching node operation";
                    search();
                    break;
            case 5:cout<<"\nYou have selected counting node operation";
                    count();
                    break;
            case 6:
                    exit(0);
                    break;
            default:cout<<"\nwrong choice";
        }
    }while(choice!=6);
    // insertatbeg();
    // insertatbeg();
    // insertatend();
    // insertatpos();
    // traverse();
    // search();
    // count();
    return 0;
}

