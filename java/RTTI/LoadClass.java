class Candy { 
	static { System.out.println("Loading Candy."); }
}
class Gum {
	static { System.out.println("Loading Gum."); }
}
class Cookie {
	static { System.out.println("Loading Cookie."); }
}

public class LoadClass {
	public static void main(String[] args) {
		System.out.println("Inside main:");
		new Candy();
		try{
			Class.forName("Gum");
		} catch (ClassNotFoundException e) {
			System.out.println("Could not find Gum");
		}
		System.out.println("After Class.forName(\"Gum\")");
		new Cookie();
		System.out.println("After creating Cookie.");
	}
}
