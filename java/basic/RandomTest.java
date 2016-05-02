import java.util.Random;
import java.lang.Math;

public class RandomTest{
	public static void main (String[] args) {
		Random rand = new Random();
		for (int i = 0; i < 10; ++i) {
			System.out.println(Integer.toBinaryString(rand.nextInt(100) + 1));
		}
	}
}
