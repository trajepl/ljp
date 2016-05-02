import java.util.Arrays;
import java.util.Random;

class ArrayNew {
	public static void main(String[] args) {
		int[] a;
		Random rand = new Random();
		a = new int[rand.nextInt(10)];
		/*
		 * Integer a = new Integer[rand.nextInt(10)]
		 * */
		System.out.println("length of a = " + a.length);
		System.out.println(Arrays.toString(a));
	}
}
