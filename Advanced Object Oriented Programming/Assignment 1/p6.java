import java.util.*;

class Overloading{
	void show(int i){
		System.out.println(i);
	}
	void show(double d){
		System.out.println(d);
	}
	public static void main(String args[]){
		short s = 8;
		double d = 8.8;
		Overloading over = new Overloading();
		
		over.show(s);
		over.show(d);
	}
}
