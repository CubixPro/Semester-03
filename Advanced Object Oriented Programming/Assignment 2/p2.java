import java.util.*;

class Address{
	int premises;
	String street;
	String city;
	int pin;
	String state;
	
	Address(int p, String str, String c, int pin, String s){
		premises = p;
		street = str;
		city = c;
		this.pin = pin;
		state = s;
	}
	
	void show(){
		System.out.println(premises + " " + street + " " + city + " " + pin + " " + state);
	}
	
	void changeAddress(){
		int choice;
		Scanner sc = new Scanner(System.in);
		choice = sc.nextInt();
		switch(choice){
			case 1: premises = sc.nextInt();
			break;
			case 2: street = sc.next();
			break;
			case 3: city = sc.next();
			break;
			case 4: pin = sc.nextInt();
			break;
			case 5: state = sc.next();
			break;
		}
	}
	
	void input(){
		Scanner sc = new Scanner(System.in);
		premises = sc.nextInt();
		street = sc.next();
		city = sc.next();
		pin = sc.nextInt();
		state = sc.next();
	}
}

class Person{
	String name;
	Address address;
	long phNo;
	String email;
	Person(String n, long ph, String em, int p, String str, String c, int pin, String s){
		name = n;
		phNo = ph;
		email = em;
		address = new Address(p, str, c, pin , s);
	}
	
	void viewAttributes(){
		System.out.println("Name : " + name + "\nEmail : "  + email + "\nPhone Number : " + phNo);
		System.out.print("Address : ");
		address.show();
	}
	void input(){
		Scanner sc = new Scanner(System.in);
		name = sc.next();
		address.input();
	}
	
		
}

class Student extends Person{
	long rollNo;
	String course;
	Student(String n, long ph, String em, int p, String str, String c, int pin, String s, long r, String cour){
		super(n, ph, em, p, str, c, pin, s);
		rollNo = r;
		course = cour;
	}
	void viewAttributes(){
		super.viewAttributes();
		System.out.println("Roll Number : " + rollNo + "\nCourse : " + course);
	}
}

class Faculty extends Person{
	long empId;
	String dept;
	String special;
	Faculty(String n, long ph, String em, int p, String str, String c, int pin, String s, long r, String d, String sp){
		super(n, ph, em, p, str, c, pin, s);
		empId = r;
		dept = d;
		special = sp;
	}
	void viewAttributes(){
		super.viewAttributes();
		System.out.println("Employee ID : " + empId + "\nDepartment : " + dept + "\nSpecialization : " + special);
	}
		
	
}

class Test{
public static void main(String args[]){
	Student s = new Student("Titir", 8017, "titir@mail.com", 12, "Some Road", "City", 700156, "WB", 101, "cse");
	Faculty f = new Faculty("faculty Titir", 98017, "ftitir@mail.com", 12, "Some Road", "City", 700156, "WB", 101, "cse", "ai");
	s.viewAttributes();
	f.viewAttributes();
	}
}
	
