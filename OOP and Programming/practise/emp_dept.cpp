#include<iostream>
#include"classes.hpp"

using namespace std;


int Employee::counter = 0;

int main()
{
    FILE* fp;
    fp = fopen("emp.dat", "a");
    Employee e1;
    e1.input();
    FILE* fdept;
    fdept = fopen("dept.dat", "r");
    Department d;
    bool check = false;
    while(fread(&d, sizeof(Department), 1, fdept) != 0)
    {
        if(d.getID() == e1.getDeptID())
        {
            check = true;
            break;
        }
    }
    if(check == false)
    {
        cout << "Invalic Department ID";
    }
    else
    {
        cout << "Employee added to database";
    }
    cout << '\n';
    
    fclose(fp);
    fclose(fdept);
}