#include<iostream>

using namespace std;


class A{
    public:
    class divide_by_zero{
        public:
        int num;
        divide_by_zero(int num = 1){
            this->num = num;
        }
    };
    public:
    int divide(int a, int b){
        if(b == 0)
        {
            throw divide_by_zero(a);
        }
        return a/b;
    }
};

int main(){
    try{
        A a;
        a.divide(2, 0);
    }
    catch(A::divide_by_zero i)
    {
        cout << "you tried dividing " << i.num << " by zero -_- \n";
    }
    return 0;
}