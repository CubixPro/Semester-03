#include<iostream>

using namespace std;

class Employee{
    string name;
    double basic;
    int dept_id;
    int emp_id;
    public:
    static int counter;
    Employee()
    {
        counter++;
        emp_id = counter;
    }  
    void input()
    {
        cout << "Name : ";
        cin >> name;
        cout << "Basic Pay : ";
        cin >> basic;
        cout << "Department ID : ";
        cin >> dept_id;

    } 
    int getDeptID()
    {
        return dept_id;
    }
};

class Department{
    string course;
    int dept_id;

    public:
    int getID()
    {
        return dept_id;
    }
    void getInput()
    {
        cout << "Department Name : ";
        cin >> course;
        cout << "Department ID : ";
        cin >> dept_id;
    }
};