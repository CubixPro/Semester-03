#include<iostream>
using namespace std;

class STRING{
    char* str;
    int size;
    int *ref;

public:
    STRING(int size)
    {
        this->size = size;
        str = new char[size];
        ref = new int;
        *ref = 1;
    }
    ~STRING()
    {
       *ref = *ref - 1;
       if(ref <= 0)
       {
           *ref = 0;
           if(str != NULL)
              delete(str);
       }
    }
    friend ostream & operator<<(ostream &t, STRING &s)
    {
        for(int i = 0 ; i < s.size ; i++)
        {
            t << s.str[i];
        }
        return t;
    }
    friend istream & operator>>(istream &t, STRING &s)
    {
        string str;
        t >> str;
        for(int i = 0 ; i < s.size ; i++)
        {
            s.str[i] = str[i];
        }
        return t;
    }
    friend STRING operator+(STRING const a, STRING const b)
    {
        STRING c(a.size + b.size);
        for(int i = 0 ; i < a.size ; i++)
        {
            c.str[i] = a.str[i];
        }
        for(int i = a.size ; i < c.size ; i++)
        {
            c.str[i] = b.str[i - a.size];
        }
        return c;
    }
    void operator=(STRING const str)
    {
       this->str = str.str; 
       this->size = str.size;
       *ref++;
    }
    STRING(STRING const &str)
    {
       this->str = str.str; 
       this->size = str.size;
       *ref++;
    }
};
int main()
{
    STRING str(5); 
    cin >> str;
    STRING str2(5);
    cin >> str2;
    STRING str3(10);
    str3 = str + str2;
    cout << str3;
}