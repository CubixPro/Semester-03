import java.util.*;

abstract class Customer{
	int id;
	String name;
	double loan;
	long phno;
	
	
	
	Customer(int i, String n, double l, long ph){
		id  = i;
		name = n;
		loan = l;
		phno = ph;
	}
	
	void change_name(){
		Scanner sc = new Scanner(System.in);
		name = sc.next();
	}
	
	void change_phNo(){
		Scanner sc = new Scanner(System.in);
		phno = sc.nextLong();
	}
	
	abstract boolean takeLoan();
	
	abstract void findDetails();
	
	
	
}

class Priviledged_Customer extends Customer{
static double credit_limit;
	Priviledged_Customer(int i, String n, double l, long ph){
		super(i, n, l, ph);
		credit_limit = 20000;
	}
	
	boolean takeLoan(){
		Scanner sc = new Scanner(System.in);
		double val =  sc.nextDouble();
		System.out.println(val+loan + " " + credit_limit);
		if((val + loan) <= credit_limit){
			loan += val;
			return true;
		}
		return false;
	}
	void findDetails(){
		System.out.println("Name : " + name + "\nLoan Value : " + loan + "\n");
	}
}

class Normal_Customer extends Customer{
static double credit_limit;
	Normal_Customer(int i, String n, double l, long ph){
		super(i, n, l, ph);
		credit_limit = 10000;
	}
	
	boolean takeLoan(){
		Scanner sc = new Scanner(System.in);
		double val =  sc.nextDouble();
		if((val + loan) <= credit_limit){
			loan += val;
			return true;
		}
		return false;
	}
	void findDetails(){
		System.out.println("Name : " + name + "\nLoan Value : " + loan + "\n");
	}
}

class Test{
	public static void main(String args[]){
		Priviledged_Customer c1 = new Priviledged_Customer(1010, "Titir", 0, 8017);
		Normal_Customer c2 = new Normal_Customer(1011, "Normie", 0, 1234);
		System.out.println(c1.takeLoan());
		c1.findDetails();
		System.out.println(c2.takeLoan());
		c2.findDetails();
	
	}
}

