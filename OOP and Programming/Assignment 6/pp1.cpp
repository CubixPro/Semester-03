#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

class Student{
	int roll;
	string name;
	double score;
	public:
    ~Student(){
        
        //cout << name << " has been destroyed :) \n";
    }
    int getRoll()const{
        return roll;
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

class FileOperations{
        
        public:
        /*void openFile(){
             f.open("student.dat", ios::app|ios::in|ios::out|ios::binary);
        }
        void openFileForRead(){
            f.open("student.dat", ios::out|ios::binary);
        }*/
        void write(Student s){
            ofstream f1("student.dat", ios::app|ios::binary);
            f1.write((char*)&s, sizeof(Student));
            f1.close();
        }/*
        void readNextStudent(Student s){
            openFile();
            f.read((char*)&s, sizeof(Student));
            closeFile();
        }
        int searchStudent(int r){
            openFile();
            f.seekg(ios::beg);
            bool val = false;
            Student s;
            int count = 0;
            //while(f.read((char*)&s, sizeof(Student))){
            while(f.eof()){
                if(s.getRoll() == r){
                    closeFile();
                    return count; 
                }
                count++;

            }
            closeFile();
            return -1;
        }
        void modifyStudent(int oldRoll, Student newStudent){

            openFile();
            int x = searchStudent(oldRoll);
            f.seekp(sizeof(Student) * (x), ios::beg);
            f.write((char*)&newStudent, sizeof(Student));
            closeFile();
        }*/
        void outputFile(){
            //openFileForRead();
            ifstream f1("student.dat", ios::in|ios::binary);
            Student s;
            //f.seekg(0, ios::beg);
            //while(f.read((char*)&s, sizeof(Student))){
            while(!f1.eof()){

                f1.read((char*)&s, sizeof(Student));
                cout << s;
            }
            //closeFile();
            f1.close();
        }/*
        void closeFile(){
            f.close();
        }*/

};

int main(){
    FileOperations file;
    int choice;
    do{
        cout << "Enter your choice.\n 1. Input Student deets\n 2. Print whole file\n 3. Modify a particular roll number\n 4. View a particular record\n";
        cin >> choice;
        Student s;
        switch(choice){
            case 1: 
                cin >> s;
                file.write(s);
                break;
            case 2: 
                file.outputFile();
                break;
            case 3: 
                int x;
                Student s;
                cin >> x;
                cin >> s;
                //file.modifyStudent(x, s);
                break;
        }

    }while(choice != -1); 
}