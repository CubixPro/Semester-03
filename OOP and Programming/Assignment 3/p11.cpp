/*11.	Design a STUDENT class to store roll, name, course, admission date and marks in 5 subjects.
 Provide methods corresponding to admission (marks are not available then),
  receiving marks and preparing mark sheet. 
  Support must be there to show the number of students who have taken admission.*/

#include<iostream>
#include<string>

using namespace std;
class date{
    int month;
    int day;
    int year;

    public:
    void getInfo()
    {
        scanf("%d/%d/%d", &day, &month, &year);
    }
    void printInfo()
    {
        printf("%d/%d/%d", day, month, year);
    }

};
class student{
    int roll;
    string name;
    string course;
    date admission;
    int marks[5];
    public:
    static int count;
    void getAdmisssion()
    {
        cout << "Roll : ";
        cin >> roll;
        cout << "Name : ";
        char ch = getchar();
        getline(cin, name);
        cout << "Course : ";
        cin >> course;
        printf("Enter the date of admission in dd/mm/yyyy format : ");
        admission.getInfo();
        count++;
    }
    void getMarks()
    {
        for(int i = 0 ; i < 5 ; i++)
        {
            cout << "Marks[" << i << "] : ";
            cin >> marks[i];
        } 
    }
    void printMarksheet()
    {
        cout << "Serial No. " << count << '\n';
        cout << "Name : " << name << '\n';
        printf("Date : ");
        admission.printInfo();
        printf("\n");
        for(int i = 0 ; i < 5 ; i++)
            cout << "Marks in subject " << i << " : " << marks[i] << '\n'; 
    }
    static void printTotal()
    {
        printf("Total number of admissions : %d", count);
    }
};

int student::count = 0;
int main()
{
    student st[3];
    for(int i = 0 ; i < 3 ; i++)
    {
        st[i].getAdmisssion();
    }
    st[2].getMarks();
    st[2].printMarksheet();
    student::printTotal();
}