#include<iostream>
using namespace std;
class Exception{
    public: 
    double a,b;
    void get(){
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;        
    }
    void divide(){
        try{
            if(cin.fail()){
                throw "wrong input";
            }
            if(b==0.0){
                throw b;
            }
            else{
                cout<<"Division="<<a/b<<endl;
            }
        }
        catch(double e){
            cout<<"Divide by zero "<<e<<endl;
        }
        catch(char const* f){
                cout<<"you enter string as a input "<<endl;
        }
    }
    
};
int main()
{
    Exception e;
    e.get();
    e.divide();
    return 0;
}