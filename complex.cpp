#include<iostream>
using namespace std;
class complex{
    private:
    double real;
    double imag;
    static int c;
    public:
    complex(){
        real = 0;
        imag = 1;
    }

    complex(double a){
        real = 0;
        imag = a;
    }
    complex(double a, double b){
        real = a;
        imag = b;
    }
    ~complex(){
        
        cout<<"object"<<++c<<" destroyed"<<endl;
    }

    void display(){
        cout<<real<<"+"<<imag<<"j"<<endl;
    }
};
int complex::c;
int main(){
    complex o1,o2(20),o3(5,7);
    o1.display();
    o2.display();
    o3.display();
    return 0;
}