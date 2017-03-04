import java.util.*;

public class ArrayAsList {
	public static void main(String[] args) {
		List<Integer> list = new ArrayList<>(Arrays.asList(1,2,3,4));
		list.add(120);
		System.out.println(list);
	}
}
