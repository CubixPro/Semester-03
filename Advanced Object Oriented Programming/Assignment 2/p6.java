import java.util.*;

class Test{
	public static void main(String args[]){
		int i;
		Scanner sc = new Scanner(System.in);
		i = sc.nextInt();
		Integer wrap  = i;
		int x = wrap;
		System.out.println(x);
		String str = String.valueOf(x);
		Integer y = Integer.parseInt(str);
		str = wrap.toString();
		
	}
}
