#include<iostream>

using namespace std;

struct node{
    char str[31];
    //int x;
};

class x{
    string hello;
    //int x;
};

class y{

};

int main(){
    cout << sizeof(y) << ' ' << sizeof(x);
}