import java.util.*;

class myString{
	public static void main(String args[]){
		
		String str1, str2;
		Scanner sc = new Scanner(System.in);
		str1 = sc.nextLine();
		str2 = str1;
		if(str1.equals(str2)){
			System.out.println("Contents are equal");
		}
		if(str1 == str2){
			System.out.println("Addresses are equal");
		}
		String str3, atr4;
		//Scanner sc = new Scanner(System.in);
		str1 = sc.nextLine();
		str2 = sc.nextLine();
		if(str1.equals(str2)){
			System.out.println("Contents are equal");
		}
		if(str1 == str2){
			System.out.println("Addresses are equal");
		}
	}
}
