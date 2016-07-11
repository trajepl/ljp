import java.util.Arrays;

public class BinarySearch {
	static int find(int[] src, int target) {
		int left = 0;
		int right = src.length-1;

		while(left <= right) {
			int middle = (left + right) / 2;
			if(src[middle] == target) return middle;
			if(src[middle] > target) right = middle-1;
			if(src[middle] < target) left = middle+1;
		}
		return -1;
	}
	public static void main(String[] args) {
		/*
		System.out.println(Math.abs(-2147483648));
		System.out.println(Double.POSITIVE_INFINITY);
		System.out.println(Double.POSITIVE_INFINITY);
		double min = Double.NEGATIVE_INFINITY;
		System.out.println(min);
		*/
		int [] src = {1,2,32,4,76,13,10,6,8};
		Arrays.sort(src);

		int i = find(src, 8);
		if(i != -1) {
			System.out.println(src[i]);
		} else {
			System.out.println("There is no target element");
		}
	}
}
