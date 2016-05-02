public class InitialValues {
	int i;

	/*void info() {
		int a;
		a++;
	}*/
	
	// 局部变量必须初始化, 而全局变量都有自己的默认值(基本类型 对象类型:null)
	public static void main(String[] args) {
		System.out.println(new InitialValues().i);
	}
}

