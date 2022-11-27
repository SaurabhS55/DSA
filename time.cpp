#include <iostream>
using namespace std;
class time
{
public:
    int h, m, s;
    void input()
    {
        cout << "Enter time {hh:mm:ss}" << endl;
        cin >> h >> m >> s;
    }
    time operator+(time t2)
    {
        time t4;
        int hour = h + t2.h;
        int min = m + t2.m;
        int sec = s + t2.s;
        while (sec >= 60)
        {
            sec -= 60;
            ++min;
        }
        while (min >= 60)
        {
            min -= 60;
            ++hour;
        }
        t4.h = hour;
        t4.m = min;
        t4.s = sec;
        return t4;
    }
    void display()
    {
        cout << h << ":" << m << ":" << s << endl;
    }
};
int main()
{
    time t1, t2, t3;
    t1.input();
    t2.input();
    t3 = t1 + t2;
    t3.display();
    return 0;
}