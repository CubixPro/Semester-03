#include<iostream>
using namespace std;
void f(int){
    printf("inside f(int)");
}
void f(float){
    printf("inside f(float)");
}

int main()
{
    f(5);
    f('a');
    f(0.6f);
    f(0.6);
}
