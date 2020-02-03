#include<iostream>
#include<stdio.h>
#define STUDENT_SIZE 20
#define SUBJECT_SIZE 5


using namespace std;

class Student;
class Subject{
	int sub_code;
	string subject;
	int student_count;
	
	
	public:
	void inpSubject(int code, string subject)
	{
		sub_code = code;
		this->subject = subject;
		student_count = 0;
	}
	void addStudent(int roll, int code, string name)
	{
		if(code == sub_code && subject == name)
		{
			printf("hi");
			student_count++;
		}
	}
	void printStudents()
	{
		printf("%d", student_count);
	}
	
};

Subject allSubs[SUBJECT_SIZE];

class Student{
	int roll;
	string name;
	string ph_no;
	int sub_count;
	int subjects[SUBJECT_SIZE];
	string subjects_name[SUBJECT_SIZE];
	
	public:
	void getData()
	{
		printf("Enter student roll : ");
		cin >> roll;
		printf("Enter student name : ");
		cin >> name;
		printf("Enter phone number : ");
		cin >> ph_no;
		printf("Enter the number of subjects you want to take : ");
		cin >> sub_count;
		for(int i = 0 ;  i < sub_count ; i++)
		{
			printf("Enter the subject code : ");
			cin >> subjects[i];
			printf("Enter the subject name : ");
			cin >> subjects_name[i];
			for(int j = 0 ; j < SUBJECT_SIZE ; j++)
			{
				allSubs[j].addStudent(roll, subjects[i], subjects_name[i]);
			}
		}
	}
	void printDetails()
	{
		cout << "Name : " << name << '\n' ;
		for(int i = 0 ; i < sub_count ; i++)
		{
			cout << "Code : " << subjects[i] << '\n';
			cout << "Subject : " << subjects_name[i] << '\n';
		}
	}
	
};

int main()
{
	string a = "a";
	Subject s1, s2, s3, s4, s5;
	/*Subject s2(2, a);
	Subject s3(3, a);
	Subject s4(4, a);
	Subject s5(5, a);
	allSubs[0] = s1;
	allSubs[1] = s2;
	allSubs[2] = s3;
	allSubs[3] = s4;
	allSubs[4] = s5;
	
	Student st1, st2;
	st1.getData();
	st2.getData();
	st1.printDetails();
	st2.printDetails();

	allSubs[0].printStudents();*/
	s1.inpSubject(1, "a");
	s2.inpSubject(2, "b");
	s3.inpSubject(3, "c");
	s4.inpSubject(4, "d");
	s5.inpSubject(5, "e");
	
	allSubs[0] = s1;
	allSubs[1] = s2;
	allSubs[2] = s3;
	allSubs[3] = s4;
	allSubs[4] = s5;
	
	Student st1, st2;
	st1.getData();
	st2.getData();
	st1.printDetails();
	st2.printDetails();

	allSubs[0].printStudents();
	
	
}


