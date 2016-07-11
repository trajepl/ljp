/*
 * 欧几里德算法
 * */
public class Gcd {
	static int gcd(int q, int p) {
		if(q > p) {
			int temp = q;
			q = p;
			p = temp;
		}

		if(q == 0) return p;
		int r = p % q;
		return gcd(q, r);
	}

	public static void main(String[] args) {
		int a = 100;
		int b = 256;
		System.out.println(gcd(b,a));
	}
}
