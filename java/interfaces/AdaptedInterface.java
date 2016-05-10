import java.util.*;
import java.nio.*;

class RandomDoubles {
	private static Random rand = new Random(47);
	public double next() { return rand.nextDouble(); }
}


public class AdaptedInterface extends RandomDoubles 
	implements Readable {
	
	private int count;
	public AdaptedInterface(int count) {
		this.count = count;
	}

	public int read(CharBuffer cb) {
		if(count-- == 0) return -1;
		String result = Double.toString(next()) + " ";
		cb.append(result);
		return result.length();
	}

	public static void main(String[] args) {
		Scanner s = new Scanner( new AdaptedInterface(7) );
		while(s.hasNextDouble())
			System.out.print(s.nextDouble() + " ");
	}
}
