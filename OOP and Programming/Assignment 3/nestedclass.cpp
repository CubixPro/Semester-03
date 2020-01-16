#include<iostream>

using namespace std;

class A{
     class myDate{
        public:
        void getData(){;};
        void showDate();
    }        ;
    void func()
    {
        myDate date;
        date.getData();
    }
};
int main()
{
    A a;
    
}
void A::myDate::showDate(){;}
