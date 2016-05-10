import java.util.*;

public class ArrayIsNotIterable {
	static <T> void test(Iterable<T> ib) {
		for(T t: ib)
			System.out.println(t + " ");
	}

	public static void main(String[] args) {
		test(Arrays.asList(1,2,3));
		String[] strings = {"a", "b", "c"};
		// test(strings); !
		test(Arrays.asList(strings));
	}
}
