#include<iostream>
#define MAX_STRING_SIZE 1000
using namespace std;

class String{
    string str;

    public:
    String(){
        str = "";
    }
    String(string s){
        str = s;
    }
    String(int val){
        str = val;
    }
    String(const String& s){
        str = s.str;
    }
    friend istream& operator>>(istream& t, String& s)
    {
        t>>s.str;
        return t;
    }
    friend ostream& operator<<(ostream& t, String& s)
    {
        t << s.str;
        return t;
    } 
    String operator+(String s)
    {
        String newstr;
        newstr.str = str + s.str;
        return newstr;
    }
    String operator=( String s){
        str = s.str;
        return *this;
    }
    String operator+=( String s)
    {
        String newstr = *this + s;
        *this = newstr;
        return *this;
    }
    ~String(){
        //cout << *this << " has called the destructor \n"; 
    } 
     operator int(){
        return (str[0]);
    }
    
};

int main(){
    String str1("hello_world"), str2(6);
    int x = 5;
    x = str2;
    cout << x;
    cout << str1 << '\n';
    //str2 += str1;
    //cout << str2 << '\n';
    String str3;
    str3 = str2 += str1;
    cout << str2;
    cout << str3;


}