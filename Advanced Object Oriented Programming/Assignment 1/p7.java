import java.util.*;

class Student{
	String name;
	int roll;
	double score;
	
	Student(String name, int roll, double score){
		this.name = name;
		this.roll = roll;
		this.score = score;
	}
	
	void setName(String name){
		this.name = name;
	}
	void setRoll(int roll){
		this.roll = roll;
	}
	void setScore(double score){
		this.score = score;
	}
	void displayStudent(){
		System.out.println("Name: " + name + "\nRoll: " + roll + "\nScore: " + score);
	}
	void copy(Student s){
		this.name = s.name;
		this.roll = s.roll;
		this.score = s.score;
	}
	public static void main(String args[]){
		Student s1 = new Student("Titir", 1, 89);
		Student s2 = new Student("Java", 2, 99);
		s1.setName("Oops");
		s2.setScore(99.9);
		s1.displayStudent();
		s2.displayStudent();
		s2.copy(s1);
		s2.displayStudent();
	}
}
