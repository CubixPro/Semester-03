#include<iostream>
using namespace std;
class A{
    public:
        int x;
    
    A(int a = 0):x(a){}

    A(const A& a){
        x = a.x;
    }
    virtual void print(){
         cout << "base " << 8 << "\n";
     } 
     void printx(){
         cout << x << "\n";
     }
     
};

class B : virtual public A{
    public:
        int y;
    B(int a = 0, int b = 0):A(a){
        y = b;
    }
    B(const B& b):A(b){
        y = b.y;
    }
    void print(){
        cout << "Derived in B \n";
    }
    void f(){
         cout << "f of B\n";
     }

};
class C :  public A{
    public:
        int y;
    C(int a = 0, int b = 0):A(a){
        y = b;
    }
    C(const C& c):A(c){
        y = c.y;
    }
    void print(){
        cout << "Derived in C \n";
    }

};

class D : public B, public C{
    int d;
    public:
    D(int p = -1): C(), B(), A(){

    }
    void print(){
        cout << "Derived in D" << "\n";
    }
    void f(int y){
        cout << "f of D";
    }
};
int main(){
    int x = 2, y = 3;
    B b(4, 3);
    C c;
    A a(4);
    B b2 = b; 
    b2.print();
    D d;
    d.B::print();
    d.printx();
    cout << sizeof(d);
    //d.B::printx();
    d.B::printx();//error free as both are virtual
    //d.printx(); 
    
}