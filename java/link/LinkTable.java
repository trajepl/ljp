public class LinkTable<T> {

	class Node<T> {
		public T data;
		public Node<T> next;
		public Node(T data) {
			this.data = data;
		}

		public Node() {}
	}
	
	/* Size */
	public int size;

	public Node<T> first;

	// #
	public LinkTable() {
		first = null;
		size = 0;
	}

	public void insertFirst(T value) {
		Node<T> node = new Node<T>(value);
		node.next = first;
		first = node;
		size ++;
	}

	public boolean isEmpty() {
		return size == 0;
	}
	
	public Node<T> deleteFirst() {
		Node<T> node = first;
		first = first.next;
		size--;
		return node;
	}

	public void display() {
		Node<T> curr = first;
		while(curr != null) {
			System.out.print(curr.data + " ");
			curr = curr.next;
		}
		System.out.println("");
	}

	public int size() {
		return size;
	}

	public Node<T> get(int i) {
		if(i > size - 1 || i < 0)  
			try {
				throw new Exception();
			} catch(Exception e) {
				e.printStackTrace();
			}
		Node<T> curr = first;
		for(int n = 0; n < size(); n++) {
			if(n == i)
				return curr;
			else
				curr = curr.next;
		}
		return null;
	}

	public void remove(int i) {
		if( i == 0)
			deleteFirst();
		else if(i == size() - 1)
			get(i-1).next = null;
		else {
			get(i - 1).next = get(i + 1);
		}
		size--;
	}

	public void insert(int i, T value) {
		Node<T> node = new Node<T>(value);
		if(i == 0) 
			insertFirst(value);
		else if(i == size() -1) {
			node.next = null;
			get(i).next = node
		} else {
			node.next = get(i).next;
		}		
	}

	public static void main(String[] args) {
		System.out.println(new LinkTable().new Node(1));
	}
}
