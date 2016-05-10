interface Incrementable {
	void increment();
}

/* Very sample to just implement the interface*/
class Callee1 implements Incrementable {
	private int i = 0;
	public void increment() {
		i++;
		System.out.println(i);
	}
}

class MyIncrement {
	public void increment() {
		System.out.println("Other operation.");
	}
	static void f(MyIncrement mi) {
		mi.increment();
	}
}
/* If your calss must implement increment() 
 * in some other way, you must use an inner class: 
 * */
class Callee2 extends MyIncrement {
	private int i = 0;
	public void increment() {
		super.increment();
		i++;
		System.out.println(i);
	}

	private class Closure implements Incrementable {
		public void increment() {
			Callee2.this.increment();
		}
	}

	Incrementable getCallBackReference() {
		return new Closure();
	}
}

class Caller {
	private Incrementable callBackReference;
	Caller(Incrementable cbh) {
		callBackReference = cbh;
	}
	void go() {
		callBackReference.increment();
	}
}

public class Callbacks {
	public static void main(String[] args) {
		Callee1 c1 = new Callee1();
		Callee2 c2 = new Callee2();
		MyIncrement.f(c2);
		Caller caller1 = new Caller(c1);
		Caller caller2 = new Caller(c2.getCallBackReference());
		caller1.go();
		caller1.go();
		caller2.go();
		caller2.go();
	}
}
