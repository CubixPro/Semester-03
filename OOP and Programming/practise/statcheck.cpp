#include<iostream>

using namespace std;

class statFun{
    static int val_count;
    public:
    statFun(){
        val_count++;
    }
    static void printCount()
    {
        cout << val_count << '\n';
    }
    void hello(statFun st)
    {
        st.printCount();
        cout << "hello" << '\n';
    }
    statFun operator=(statFun st){
       return st; 
    }
};
int statFun::val_count = 0;
int main (){
    statFun sf;
    statFun sf2;
    statFun::printCount();
    sf2 = sf;
    statFun::printCount(); 
}