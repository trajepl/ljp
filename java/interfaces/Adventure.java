interface CanFight {
	void fight();
}

interface CanSwim {
	void swim();
}

interface CanFly {
	void fly();
}

class ActionCharacter {
	public void fight() {}
}

class Hero extends ActionCharacter 	
	implements CanFight, CanSwim, CanFly {

	public void swim() {}
	public void fly() {}
}

public class Adventure {
	public static void f(CanFight x) { x.fight(); }
	public static void s(CanSwim x) { x.swim(); }
	public static void fy(CanFly x) { x.fly(); }
	public static void ac(ActionCharacter x) { x.fight(); }

	public static void main(String[] args) {
		Hero h = new Hero();
		f(h);
		s(h);
		fy(h);
		ac(h);
	}
}
