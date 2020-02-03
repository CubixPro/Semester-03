#include<iostream>
#include<vector>
#define MAX_STUDENTS 5 

using namespace std;

class Student{
	int roll;
	string name;
	double score;
	public:
    ~Student(){
        
        //cout << name << " has been destroyed :) \n";
    }
	friend istream& operator>>(istream& i, Student& s){
        //cout >> "Name  : ";
        i >> s.name;
        //cout >> "Roll : ";
        i >> s.roll;
        //cout >> "Score : ";
        i >> s.score;
        return i;
    }
	string getName(){
		return name;
	}
    friend ostream& operator<<(ostream& t, Student& s){
        t << "Student Details\n----------------\n";
        t << "Name: \t" << s.name << '\n';
        t << "Roll: \t" << s.roll << '\n';
        t << "Score: \t" << s.score << '\n';
        return t;
    }
	double getScore()
	{
	return score;
	}
	bool operator==( Student &s){
		if(roll == s.roll && name == s.name & score == s.score)
			return true;
		return false;
	}

	
};

class StudentList{
    Student students[MAX_STUDENTS];
    int curr;

    public:
    class ArrayIndexOutOfBoundsException{};
    StudentList(){
        curr = 0;
    }
    void addStudent(){
        if(curr == MAX_STUDENTS){
            throw ArrayIndexOutOfBoundsException();
        }
        cin >> students[curr];
        curr++;
    }
    Student& operator[](int k){
        if(k >= curr)
            throw ArrayIndexOutOfBoundsException();
        return students[k];
    }
    void printStudent(int k){
       cout << (*this)[k]; 
    }

};

int main(){
    StudentList std;
        restart:
    try{
         while(true){
             cout << "1. Add Student \n2. Print a particular student\nChoice:";
            int ch;
            scanf("%d", &ch);
            if(ch == 1){
                std.addStudent();
            }
            else if(ch == 2){
                int k;
                scanf("%d", &k);
                std.printStudent(k);
            }
            else{
                break;
            }
        }
    }
    catch(StudentList::ArrayIndexOutOfBoundsException i){
        printf("You accessed an array index that's out of bounds\n");
        goto restart;
    }
}
