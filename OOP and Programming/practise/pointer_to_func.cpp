#include<iostream>
using namespace std;

void print(int x){
    cout << "Hi I'm int\n";
}

void print3(float f){
    cout << "Hi I'm float\n";
}

void choice(void (*func)(int)){
    int val = 2;
    func(val);
}

int main(){
    void (*p)(float);
    p = print3;
    choice(print3);

}