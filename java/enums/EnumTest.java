enum Currency {
	PENNEY, DIME, DOLLAR
}

public class EnumTest {
	public static void main(String[] args) {
		Currency cur = Currency.PENNEY;
		System.out.println(cur);

		for (Currency c: Currency.values())
			System.out.print(c + " ");
		System.out.println();

		Burrito
			penney = new Burrito(Currency.PENNEY),
			dime = new Burrito(Currency.DIME),
			dollar = new Burrito(Currency.DOLLAR);

		penney.describe();
		dime.describe();
		dollar.describe();
	}
}

class Burrito {
	Currency cur;
	Burrito(Currency cur) {
		this.cur = cur;
	}

	public void describe() {
		System.out.println("This describe is:");
		switch(cur) {
			case PENNEY: System.out.println("一分钱");break;
			case DIME:	 System.out.println("一角钱");break;
			default: 	 System.out.println("一元钱");
		}
	}
}


