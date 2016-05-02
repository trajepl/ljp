public class BitOpt {
	public static void main(String[] args) {
		int a = 10;
		int b = 10;
		System.out.println(Integer.toBinaryString(a));
		System.out.println(Integer.toBinaryString(b));
		System.out.println(Integer.toBinaryString(a & b));
		System.out.println(Integer.toBinaryString(a | b));
		System.out.println(Integer.toBinaryString(a ^ b));
	}
}
