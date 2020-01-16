#include<iostream>

class B;
class A{
    friend void call(class B);
};
class B{
    friend void call(class B);
};
int main(){

}