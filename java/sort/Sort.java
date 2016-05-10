import java.util.*;

public class Sort {
	int[] list = {5,6,1,2,8,4,9,3,0};

	/* Seclect sort */
	void selectSort() {
		if(list == null || list.length == 0) 
			return ;
		int min = 0;
		int temp = 0;
		for(int i = 0; i < list.length - 1; ++i) {
			min = i;
			for(int j = i + 1; j < list.length; ++j) 
				if(list[j] < list[min]) 
					min = j;
			
			if(min != i) {
				temp = list[i];
				list[i] = list[min];
				list[min] = temp;
			}
		}
	}

	void heapSort() {

	}

	/* Insert sort */
	void insertSort() {
		if(list == null || list.length == 0)
			return ;
		int temp = 0;
		for(int i = 1; i < list.length; i++) {
			int j = i - 1;
			temp = list[i];
			while( j >= 0 && list[j] > temp ) {
				list[j + 1] = list[j];
				j -= 1;
			}
			list[j+1] = temp;
		}
	}

	void shellSort() {
		double d1 = list.length;
		int temp = 0;
		while(true) {
			d1 = Math.ceil(d1/2);
			int d = (int)d1;
			for(int x = 0; x < d; x++) {
				for(int i = x + d; i < list.length; i+=d) {
					int j = i - d;
					temp = list[i];
					while( j >= 0 && temp < list[j]) {
						list[j+d] = list[j];
						j -= d;
					}
					list[j+d] = temp;
				}
			}
			if(d==1) break;
		}
	}

	/*bubbleSort*/
	void bubbleSort() {
		int temp = 0;
		for(int i = 0; i < list.length; i++) {
			for(int j = 0; j < list.length - 1 - i; j++) {
				if(list[j] > list[j+1]) {
					temp = list[j];
					list[j] = list[j+1];
					list[j+1] = temp;
				}
			}
		}
	}

	void swap(int i, int j) {
		int t = list[i];
		list[i] = list[j];
		list[j] = t;
	}

	void quickSort(int start, int end) {
		if(start >= end) return ;
		Random rand = new Random();
		int flag = rand.nextInt(end-start+1) + start;
		swap(start, flag);

		int m = start;
		for(int i = start + 1; i <= end; i++) {
			if(list[i] < list[start])
				swap(++m, i);
		}
		swap(start, m);
		quickSort(start, m-1);
		quickSort(m+1, end);
	}

	public static void main(String[] args) {
		Sort sort = new Sort();
		sort.quickSort(0, sort.list.length-1);
		for(int i = 0; i < sort.list.length; i++) {
			System.out.print(sort.list[i] + " ");
		}
		System.out.println("");
	}
}
