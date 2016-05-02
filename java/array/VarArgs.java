public class VarArgs {
	static void printArray(Object... args) {
		for (Object s: args)
			System.out.print(s + " ");
		System.out.println();
	}
	/*这样做达不到重载的效果. 1 被当作字符的时候 此程序变出错了.*/

	/*
	static void f(float i, Character... args) {
		System.out.println("first");
	}

	static void f(Character... args) {
		System.out.println("second");
	}
	*/
	
	/* correct methods */
	static void f(float i, Character... args) {
		System.out.println("first");
	}

	static void f(char c, Character... args) {
		System.out.println("second");
	}

	public static void main(String... args) {
		for(String s: args)
			System.out.print(s + " ");
		printArray("sa", 1, 1.2);
		printArray(new A(), new A(), new A());

		f(1, 'a');
		f('a', 'c');
	}
}

class A{}

/*
 * 可变参数列表与自动包装机制可以和谐共处
 * 注意函数重载下的 无参数情况.
 * */
