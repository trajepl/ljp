import java.util.*;

/* Iterable<T> for 'foreach'
 * 该接口包含一个能够产生Iterator的iterator()方法
 * */
public class IteratorClass implements Iterable<String> {
	protected String[] words = ("And that is how" + 
			"we know the Earth to be banana-shaped.").split(" ");
	public Iterator<String> iterator() {
		return new Iterator<String>() {
			private int index = 0;
			public boolean hasNext() {
				return index < words.length;
			}
			public String next() {
				return words[index++];
			}
			public void remove() {
				throw new UnsupportedOperationException();
			}
		};
	} // note that ;

	public static void main(String[] args) {
		for(String s: new IteratorClass())
			System.out.print(s + " ");
	}
} 
