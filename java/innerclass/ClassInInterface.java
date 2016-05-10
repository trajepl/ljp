public interface ClassInInterface {
	void howdy();
	class Test implements ClassInInterface {
		public void howdy() {
			System.out.println("Howdy!");
		}
		/* 生成的main函数要在ClassInInterface$Test中通过java命令运行*/
		public static void main(String[] args) {
			new Test().howdy();
		}
	}
}
