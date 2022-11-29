
//WAP to implement concept of virtual function: Take a class named Shape with height and width and get and area methods.Derive two classes named as Rectangle and Triangle to print their area.

#include<iostream>
using namespace std;
class Shape{
    public:
    double width,height;
    void get(){
        cout<<"Enter width and height\n";
        cin>>width>>height;
    }
    virtual void area(){
        cout<<"Area of shape"<<endl;
    }
};
class Rectangle: public Shape{
    public:
    void area(){
        cout<<"Area of Rectangle="<<width*height<<endl;
    }

};
class Triangle: public Shape{
    public:
    void area(){
        cout<<"Area of TRiangle="<<0.5*width*height<<endl;
    }

};
int main()
{
    Shape *p,s;
    Rectangle r;
    Triangle t;
    p=&s;
    p->get();
    p->area();
    p=&r;
    p->get();
    p->area();
    p=&t;
    p->get();
    p->area();
    return 0;
}