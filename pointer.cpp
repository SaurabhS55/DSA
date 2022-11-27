#include <iostream>
using namespace std;
int main()
{
    int *ptr,a;
    cout << "Enter a" << endl;
    cin >>a;
    ptr=&a;
    cout<<"\n Address of a="<<ptr;
    cout<<"\n value of a="<<*ptr;
    return 0;

}