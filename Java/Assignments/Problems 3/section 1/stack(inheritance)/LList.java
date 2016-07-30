class LList {

	Node head; // head of the list

	public Node getHead() {
		return head;
	}

	public void setHead(Node head) {
		this.head = head;
	}

	private int pos; // position where insertion or deletion happens
	private Node last;

	public LList() {
		this.setHead(null);
		this.setHead(null);
		this.pos = 0;
	}

	// Structure of a linked list node.
	class Node {
		private Object data;
		private Node next;

		Node(Object value) {
			this.setData(value);
			this.setNext(null);
		}

		public Object getData() {
			return data;
		}

		public void setData(Object value) {
			this.data = value;
		}

		public Node getNext() {
			return next;
		}

		public void setNext(Node next) {
			this.next = next;
		}

	}

	// pos specifies the location in the list where the operation
	// needs to be performed
	public void insert(int pos, Object obj) {
		Node temp, prev;
		int p = 0;

		temp = head;
		prev = null;

		while (p != pos) {
			prev = temp;
			temp = temp.getNext();
			p++;
		}
		Node appendNode = new Node(obj);
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
		Node temp, prev;

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
			prev.setNext(temp.getNext());
			// head = prev; // buggy , No needs to pull the strings here.

		}
		if (p == this.pos) {
			this.last = prev;
		}
		this.pos--;
	}

	public Object get(int pos) {
		Node temp,prev = null;
		temp = head;
		int p = 0;
		while (p != pos) {
			prev = temp;
			temp = temp.getNext();
			p++;
		}
		return temp.getData();
	}

	public int find(Object obj) {
		int pos = 0;
		Node temp;
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

	public void append(Object obj) { // add to the end O(1) implementation
		Node temp;
		temp = head;
		if (temp == null) {
			Node newNode = new Node(obj);
			temp = newNode;
			head = temp;
			last = temp;
			this.pos++;
		} else {
			Node newNode = new Node(obj);
			last.setNext(newNode);
			last = newNode;
			this.pos++;
		}
	}

	@Override
	public String toString() {
		StringBuilder str = new StringBuilder();
		str.append("Head->");
		Node temp = this.head;
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

	public Node getLast() {
		return last;
	}

	public void setLast(Node last) {
		this.last = last;
	}
}
