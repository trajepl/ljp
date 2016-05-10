
public class DotNewThis {
	
	class DotThis {
		void f() { System.out.println("DotThis.f()"); }

		public class Inner {	
			public DotThis outer() {
				return DotThis.this;
			}

			void f() { System.out.println("Inner.f()"); }
		}

		public Inner inner() { return new Inner(); }
	}

	public static void main(String[] args) {
		DotNewThis dnt = new DotNewThis();
		DotNewThis.DotThis dt = dnt.new DotThis();
		DotNewThis.DotThis.Inner dt1 = dt.inner();
		dt.f();
		dt1.f();
	}
}
