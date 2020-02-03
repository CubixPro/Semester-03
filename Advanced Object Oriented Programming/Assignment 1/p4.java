import java.util.*;

class Circle{
	public static void main(String args[]){
		final double pi = 3.14;
		double radius;
		Scanner sc = new Scanner(System.in);
		radius = sc.nextDouble();
		double area = pi * radius * radius;
		System.out.println("The Area is " + area);
}
}
