import java.util.*;
class InvalidScoreException extends Throwable{
}
class Student{
	int roll;
	String name;
	double score;
	
	Student(int r, String n, double s){
		roll = r;
		name = n;
		score = s;
	}
	Student(){
		roll = 1;
		name = "John Doe";
		score = 80;
	}
	
	void setScore() throws InvalidScoreException{
		Scanner sc = new Scanner(System.in);
		double val = sc.nextDouble();
		if(val < 0 || val >100)
		{
			InvalidScoreException e = new InvalidScoreException();
			throw e;
		}
	}
}

class Test{
	public static void main(String args[]){
		try{
			Student s = new Student();
			s.setScore();
		}
		catch(InvalidScoreException e){
			System.out.println("Invalid Score");
		}
	}
}
