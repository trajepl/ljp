import java.util.Date;
/**The first Thinking in java example program:
 * Display a string and today's data/
 * @author ljp
 * @author trajepl@gmail.com
 * @version 1.0
 */

public class test {
	/**Entry point ro class and application
	 * @param args array of string arguments
	 */
	public static void main (String[] args) {
		
		System.getProperties().list(System.out);
		System.out.println("****************");
		System.out.println(System.getProperty("user.name"));
		System.out.println("****************");
		System.out.println(System.getProperty("java.library.path"));
		System.out.println("****************");
		System.out.println(new Date());
	}
} /* Output: (55% match)
Hello it's
web oct 05 14:39 mdt 2005
*///:~

