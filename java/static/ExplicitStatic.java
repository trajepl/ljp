class Cup {

	Cup(int marker) {
		System.out.println("Cup(" + marker + ")");
	}
	
	void f(int marker) {
		System.out.println("f(" + marker + ")");
	}

}

class Cups {
	static Cup cup1 = new Cup(1);
	static Cup cup2;
	/* For none static var, explicit is also OK
	 * int a, b;
	 * {
	 *     a = 1;
	 *     b = 2;
	 * }
	 * 在匿名内部类中这是必须的
	 * */
	static {
		cup1 = new Cup(3);
		cup2 = new Cup(4);
	}

	Cups() {
		System.out.println("Cups()");
	}
}

public class ExplicitStatic {
	public static void main(String[] args) {
		System.out.println("Inside main()");
		Cups.cup2.f(99);
	}
}
