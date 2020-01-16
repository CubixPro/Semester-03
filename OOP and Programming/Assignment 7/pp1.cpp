#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;



class Student{
	int roll;
	string name;
	double score;
	public:
	void input(){
		cin >> roll;
		cin >> name;
		cin >> score;
	}
	string getName(){
		return name;
	}
	void printStudent(){
		cout << roll;
		cout << name;
		cout << score;
	}
	double getScore()
	{
	return score;
	}
	bool operator==(Student s){
		if(roll == s.roll && name == s.name & score == s.score)
			return true;
		return false;
	}
	
};

bool comparator(Student s1, Student s2){
	return (s1.getScore() > s2.getScore());
}

class StudentList{
	vector<Student> students;
	public:
	void addStudent(){
		Student s1;
		s1.input();
		students.push_back(s1);
	}
	void removeStudent(){
		Student s1;
		s1.input();
		for(int i = 0 ; i < students.size() ; i++)
		{
			if(students[i] == s1)
				students.erase(students.begin() + i);
		}
	}
	void accessStudent(){
		
	}
	void findStudentWith(){
		string str;
		cin >> str;
		for(int i = 0 ; i < students.size() ; i++)
		{
			if(students[i].getName().find_first_of(str) != string::npos)
			{
				students[i].printStudent();
				cout << '\n';
			}
		}
	}
	void findStudentWithout(){
		string str;
		cin >> str;
		for(int i = 0 ; i < students.size() ; i++)
		{
			if(students[i].getName().find_first_not_of(str) != string::npos)
			{
				students[i].printStudent();
				cout << '\n';
			}
		}
	}
	void sizeOfStudents(){
			cout << students.size();
			cout << '\n';
	}
	void maxStudent(){
		double max_score = 0;
		for(int i = 0 ; i < students.size() ; i++)
		{
			if(students[i].getScore() > max_score)
			{
				max_score = students[i].getScore();
			}
		}
		cout << max_score << '\n';
	}
	void sortStudents()
	{
		sort(students.begin(), students.end(), comparator);
	}
};

int main()
{
	StudentList stdl;
		int choice;
	do{
			cout << "1. Add a student\n2. Remove student\n3. Access a student\n4. Find a student with a substring\n5. Find a student without a substring\n6. Total number of students\n7. Students with the highest score.\n8. Sort all the students\n"; 
			cout << "Enter your choice : ";
		
			cin >> choice;
			switch(choice)
			{
				case 1: stdl.addStudent(); break;
				case 2: stdl.removeStudent(); break;
				case 3: stdl.accessStudent(); break;
				case 4: stdl.findStudentWith(); break;
				case 5: stdl.findStudentWithout(); break;
				case 6: stdl.sizeOfStudents(); break;
				case 7: stdl.maxStudent(); break;
				case 8: stdl.sortStudents();break;
			}
		}while(choice != 0);
}
	
	
