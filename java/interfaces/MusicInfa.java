interface Instrument {
	int VALUE = 5;

	/* public */
	void play(String n);
	void adjust();
}

class Wind implements Instrument {

	/* Must public! Cannot be delete*/
	public void play(String n) {
		System.out.println(this + ".play() " + n);
	}

	public void adjust() {
		System.out.println(this + ".adjust().");
	}

	public String toString() {
		return "Wind";
	}
}

class Brass extends Wind {
	public String toString() {
		return "Brass";
	}
}

public class MusicInfa {
	static void tune(Instrument i) {
		i.play("a happy song.");
	}

	static void tuneAll(Instrument[] e) {
		for (Instrument i : e)
			tune(i);
	}

	public static void main(String[] args) {
		Instrument[] orchetra = {
			new Wind(),
			new Brass()	
		};
		tuneAll(orchetra);
	}
	
}
