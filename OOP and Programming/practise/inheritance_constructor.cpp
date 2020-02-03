#include<iostream>

using namespace std;

class B{
    public: int x;
    B(int val){
        x = val;
    }
};

class D:public B{
    int y;
    D(int val1 = 0, int val2 = 0):B(val2){
        y = val1;

    }
    D(D& d):B(d){
        y = d.y;
    }

};

int main(){
    ;
}