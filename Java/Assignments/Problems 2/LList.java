/*
 * LinkedList Implementation
 * @Author : Anoop Toffy
 * 
 */
public class LList {

	Node head; // head of the list
	private int pos = 0; // position where insertion or deletion happens

	public LList() {
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
		Node temp,prev;
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
		this.pos++;
	}

	public void remove(int pos) {
		Node temp,prev;

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
			this.pos--;
		} else {
			prev.setNext(temp.getNext());
			// head = prev; // buggy , No needs to pull the strings here.
			this.pos--;
		}
	}

	public Object get(int pos) {
		Node temp;
		temp = head;
		int p = 0;
		while (p != pos) {
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
		this.pos = 0;
	}

	public void append(Object obj) { // add to the end
		Node temp;
		temp = head;
		if (temp == null) {
			Node appendNode = new Node(obj);
			temp = appendNode;
			head = temp;
		} else {
			while (temp.getNext() != null) {
				temp = temp.getNext();
			}
			Node appendNode = new Node(obj);
			temp.setNext(appendNode);
		}
		this.pos++;
	}

	@Override
	public String toString() {
		StringBuilder str = new StringBuilder();
		str.append("Head->");
		Node temp = this.head;
		while (temp != null) {
			str.append(temp.data + "->");
			temp = temp.next;
		}
		str.append("NULL");
		return str.toString();
	}

	public static void main(String[] args) {

		LList bookList = new LList();
		System.out.println(bookList);

		bookList.append("Harry Potter I");
		System.out.println(bookList);
		bookList.insert(0, "Hamlet");System.out.println(bookList);
		bookList.insert(0, "Cosmos");
		System.out.println(bookList);
		bookList.insert(1, "Java");
		System.out.println(bookList);
		bookList.remove(1);
		System.out.println(bookList);
		bookList.insert(1, "C++");
		bookList.insert(2, "LISP");
		bookList.insert(2, "Calvin & Hobbes");
		System.out.println(bookList);
		int pos = bookList.find("LISP");
		bookList.remove(pos);
		System.out.println(bookList);
		// autoboxing and unboxing
		bookList.clear();
		bookList.append(1);
		bookList.append(1);
		bookList.append(2);
		bookList.append(3);
		System.out.println(bookList);
		pos = bookList.find(2);
		bookList.remove(pos);
		System.out.println(bookList);
	}

	public int getPos() {
		return pos;
	}

	public void setPos(int pos) {
		this.pos = pos;
	}
}

