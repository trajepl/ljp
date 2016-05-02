class Bowl {

	Bowl(int market) {
		System.out.println("Bowl(" + market + ")");
	}

	void f1(int marker) {
		System.out.println("f1(" + marker + ")");
	}

}

class Table {
	static Bowl bowl1 = new Bowl(1);

	Table() {
		System.out.println("Table()");
		bowl2.f1(1);
	}

	void f2(int marker) {
		System.out.println("f2(" + marker + ")");
	}

	static Bowl bowl2 = new Bowl(2);
}

class Cupboard {
	Bowl bowl3 = new Bowl(3);
	static Bowl bowl4 = new Bowl(4);

	Cupboard() {
		System.out.println("Cupboard()");
		bowl4.f1(2); 
	} 

	void f3(int marker) { 
		System.out.println("f3(" + marker + ")"); 
	}

	static Bowl bowl5 = new Bowl(5);
}

public class StaticInit {

	public static void main(String[] args) {
		Table.bowl1.f1(2);
		System.out.println("Creating new Cupboard() in main");
		new Cupboard();
		System.out.println("Creating new Cupboard()2 in main");
		new Cupboard();
		cup.f3(1);
	}

	static Cupboard cup = new Cupboard();
}
