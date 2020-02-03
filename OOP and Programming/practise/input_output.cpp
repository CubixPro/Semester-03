#include<iostream>
#include<fstream>
using namespace std;

void getCharacters(){
    char ch;
    cin.get(ch); 
    while(ch != '\n'){
        cout << ch;
        cin.get(ch);
    }
}

void file_operations(){
    ofstream f;
    f.open("abc.txt", ios::app);
    f << "Hello, is this working?";
    f.close(); 
    ifstream f1;
    f1.open("abc.txt", ios::in);
    string name;
    f1 >> name;
    cout << name << '\n';
    char c;
    while(f1.get(c) ){
        cout << c;
    }
    f1.close();
}


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


int main(){
    fstream f;
    //string file_name = "student.dat";
    f.open("student.dat", ios::out|ios::binary);
    Student s;
    s.input();
    f.write((char *)&s, sizeof(s));
    f.close();
    fstream f2;
    f2.open("student.dat", ios::in|ios::binary);
    f2.seekg(0, ios::beg) ;
    Student s2;
        cout << f2.read((char *)&s2, sizeof(s2));
        s2.printStudent();
    f2.close();
}
