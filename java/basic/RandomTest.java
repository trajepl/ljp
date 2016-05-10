import java.util.Random;
import java.lang.Math;

public class RandomTest{
	public static void main (String[] args) {
		Random rand = new Random();
		int count = 0;
		for (int i = 0; i < 10000000; ++i) {
			if(rand.nextInt(100-10 +1) + 10== 100) {
				count++;
			}
			//System.out.println(Integer.toBinaryString(rand.nextInt(100) + 1));
		}	
		System.out.println(count);
	}
}
