#include<bits/stdc++.h>

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

class StudentQueue{
	queue<Student> students;
	
	public: 
	 	void addStudent(){
	 		Student s1;
	 		s1.input();
	 		students.push(s1);
	 	}
	 	void popStudent(){
	 		if(students.size() != 0)
	 			students.pop();
	 		else
	 			cout << "Underflow\n";
	 	}
	 	Student frontStudent(){
	 		if(students.size() != 0)
	 		return students.front();
	 		
	 	}
};

int main(){
	StudentQueue sq;
	int ch;
	do{
		cout << "1. Add student\n2. Print student\n";
		cin >> ch;
		switch(ch){
			case 1: sq.addStudent();
					break;
			case 2: Student s1 = sq.frontStudent();
					s1.printStudent();
					sq.popStudent();
					break;
		}
		}while(ch != 0);
}
