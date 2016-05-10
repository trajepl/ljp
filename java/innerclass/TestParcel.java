interface Destination {
	String readLabel();
}

interface Contents {
	int value();
}

class Parcel {
	private class PContents implements Contents {
		private int i = 11;
		public int value() { return i; }
	}

	protected class PDestination implements Destination {
		private String label;
		private PDestination(String whereTo) {
			label = whereTo;
		}
		public String readLabel() {	return label; }
	}

	public Destination destination(String s) {
		return new PDestination(s);
	}
	public Contents contents() {
		return new PContents();
	}
}

public class TestParcel {
	public static void main(String[] args) {
		Parcel p = new Parcel();
		Contents c =  p.contents();
		Destination d = p.destination("Tasmania");

		// Illegal -- cannot access private class;
		// ! Parcel.PContents pc = p.new PContents();
	}
}
