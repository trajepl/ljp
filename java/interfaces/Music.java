abstract class Instrument {
	private int i;
	public abstract void play(String s);
	public abstract void adjust();
	public String what() { return "Instrument"; }
}

class Wind extends Instrument {
	public void play(String n) { 
		System.out.println("Wind play() " + n);
	}

	public void adjust() {}

	public String what() { return "Wind"; }
}

class Percussion extends Instrument {
	public void play(String n) {
		System.out.println("Percussion play " + n);
	}

	public void adjust() {}

	public String what() { return "Percussion"; }
}

public class Music {
	static void tune(Instrument i) {
		i.play("ling");
	}

	static void tuneAll(Instrument[] e) {
		for (Instrument i: e)
			tune(i);
	}

	public static void main(String[] args) {
		Instrument[] orchestra = {
			new Wind(),
			new Percussion()
		};

		tuneAll(orchestra);
	}
}
