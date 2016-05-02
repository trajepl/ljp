class Book {
	boolean checkOut = false;
	Book(boolean checkout) {
		checkOut = checkout;
	}

	void checkIn() {
		checkOut = false;
	}

	protected void finalize() {
		if (checkOut)
			System.out.println("Error: checked out");
		// Normally, you can also di this:
		// super.finalize();
	}
}
public class Termination {
	public static void main(String[] args) {
		Book novel = new Book(true);	
		novel.checkIn();
		new Book(true);
		System.gc();
	}
}
