#include<iostream>
using namespace std;
class Shape{
    public :
    virtual void draw(){
        cout<<"draw a shape..."<<endl;
    }
};
class Circle:public Shape{
    public:
    double r;
    void draw(){
        cout<<"Enter radius"<<endl;
        cin>>r;
        cout<<3.14*r*r<<endl;
    }
};
class Square:public Shape{
    public:
    double s;
    void draw(){
        cout<<"Enter side of square"<<endl;
        cin>>s;
        cout<<s*s<<endl;
    }
};
class Triangle:public Shape{
    public:
    double w,h;
    void draw(){
        cout<<"Enter width and height of triangle"<<endl;
        cin>>w>>h;
        cout<<0.5*w*h<<endl;
    }
};
int main()
{
    Shape *ptr[2],obj;
    Circle c;
    Square s;
    Triangle t;
    for(int i=0;i<2;i++){
        ptr[i]=&obj;
        ptr[i]->draw();
    }
    for(int i=0;i<2;i++){
        ptr[i]=&c;
        ptr[i]->draw();
    }
    for(int i=0;i<2;i++){
        ptr[i]=&s;
        ptr[i]->draw();
    }
    for(int i=0;i<2;i++){
        ptr[i]=&t;
        ptr[i]->draw();
    }
    return 0;
}