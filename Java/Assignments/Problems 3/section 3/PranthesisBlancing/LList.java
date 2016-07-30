class LList<T> {

	Node<T> head; // head of the list

	public Node<T> getHead() {
		return head;
	}

	public void setHead(Node<T> head) {
		this.head = head;
	}

	private int pos; // position where insertion or deletion happens
	private Node<T> last;

	public LList() {
		this.setHead(null);
		this.setHead(null);
		this.pos = 0;
	}

	// Structure of a linked list node.
	@SuppressWarnings("hiding")
	class Node<T> {
		private T data;
		private Node<T> next;

		Node(T value) {
			this.setData(value);
			this.setNext(null);
		}

		public T getData() {
			return data;
		}

		public void setData(T value) {
			this.data = value;
		}

		public Node<T> getNext() {
			return next;
		}

		public void setNext(Node<T> next) {
			this.next = next;
		}

	}

	// pos specifies the location in the list where the operation
	// needs to be performed
	public void insert(int pos, T obj) {
		Node<T> temp, prev;
		int p = 0;

		temp = head;
		prev = null;

		while (p != pos) {
			prev = temp;
			temp = temp.getNext();
			p++;
		}
		Node<T> appendNode = new Node<T>(obj);
		if (prev == null) {
			prev = appendNode;
			head = prev;
		} else {
			prev.setNext(appendNode);
		}
		appendNode.setNext(temp);
		if (p == this.pos) {
			this.last = appendNode;
		}
		this.pos++;

	}

	public void remove(int pos) {
		Node<T> temp, prev;

		temp = head;
		prev = null;
		int p = 0;
		while (p != pos) {
			prev = temp;
			temp = temp.getNext();
			p++;
		}
		if (prev == null) {
			prev = head;
			prev = prev.getNext();
			head = prev;

		} else {
			prev.setNext(prev.getNext());
			// head = prev; // buggy , No needs to pull the strings here.

		}
		if (p == this.pos) {
			this.last = prev;
		}
		this.pos--;
	}

	public T get(int pos) {
		Node<T> temp,prev = null;
		temp = head;
		int p = 0;
		while (p != pos) {
			prev = temp;
			temp = temp.getNext();
			p++;
		}
		return prev.getData();
	}

	public int find(T obj) {
		int pos = 0;
		Node<T> temp;
		temp = head;
		while (!temp.data.equals(obj)) {
			temp = temp.getNext();
			pos++;
		}

		return pos; // return the position of obj
	}

	public int size() {
		return this.pos;
	}

	public void clear() {
		this.head = null;
		this.last = null;
		this.pos = 0;
	}

	public void append(T obj) { // add to the end O(1) implementation
		Node<T> temp;
		temp = head;
		Node<T> newNode = new Node<T>(obj);
		if (temp == null) {
			
			temp = newNode;
			head = temp;
			last = temp;
			
		} else {
			
			last.setNext(newNode);
			last = newNode;
		}
		this.pos++;
	}

	@Override
	public String toString() {
		StringBuilder str = new StringBuilder();
		str.append("Head->");
		Node<T> temp = this.head;
		// System.out.println("Hello");
		while (temp != null) {
			// System.out.println("Hello");
			str.append(temp.data + "->");
			temp = temp.next;
		}
		str.append("NULL");
		return str.toString();
	}

	public int getPos() {
		return pos;
	}

	public void setPos(int pos) {
		this.pos = pos;
	}

	public Node<T> getLast() {
		return last;
	}

	public void setLast(Node<T> last) {
		this.last = last;
	}
}
