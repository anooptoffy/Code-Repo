/*
 * Doubly Linked List
 * @Author : Anoop Toffy
 */

public class DoublyLList {

	private Node head; //  for head prev pointer will be null
	private Node tail; // for tail next pointer will be null
	private int pos;
	
	DoublyLList(){
		this.head = null;
		this.tail = null;
		this.setPos(0);
	}
	
	// Structure of a linked list node.
	class Node {
		private Object data;
		private Node next;
		private Node prev;

		Node(Object value) {
			this.setData(value);
			this.setNext(null);
			this.setPrev(null);
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

		public Node getPrev() {
			return prev;
		}

		public void setPrev(Node prev) {
			this.prev = prev;
		}

	}
	
	public void insert(int pos, Object obj) {
		Node temp, prev = null;
		int p = 0;
		
		temp = head;
		Node newNode = new Node(obj);
		while(p != pos){
			prev = temp;
			temp = temp.getNext();
			p++;
		}
		
		if(prev == null){
			this.append(obj);
		}
		else{
			prev.next = newNode;
			newNode.prev = prev;
			newNode.next = temp;
			temp.prev = newNode;
		}
		
	}
	
	public void remove(int pos) {
		Node temp, prev = null;
		int p= 0;
		temp = head;
		while(p != pos){
			prev = temp;
			temp = temp.getNext();
			p++;
		}
		
		if(prev == null){
			prev = head;
			head = head.getNext();
			head.prev = null;
		}
		else{
			prev.setNext(temp.getNext());
			temp.setPrev(prev);			
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
		Node newNode = new Node(obj);
		if(temp == null){ // which means list is empty
			newNode.prev = null;
			head = newNode;
			tail = newNode;
			tail.next = null;
		}
		else{
			newNode.next = head;
			head.prev = newNode;
			head = newNode;
		}
		this.pos++;
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
		str.append("TAIL");
		return str.toString();
	}



	public static void main(String[] args) {
		
		DoublyLList bookList = new DoublyLList();
		System.out.println(bookList);
		bookList.append("Harry Potter I");
		System.out.println(bookList);
		bookList.append("Harry Potter II");
		System.out.println(bookList);
		bookList.append("Harry Potter III");
		System.out.println(bookList);
		bookList.insert(0, "Hamlet");
		System.out.println(bookList);
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
	
	public Node getHead() {
		return head;
	}
	public void setHead(Node head) {
		this.head.next = head;
		this.head.prev = null;
	}
	public int getPos() {
		return pos;
	}
	public void setPos(int pos) {
		this.pos = pos;
	}

	public Node getTail() {
		return tail;
	}

	public void setTail(Node tail) {
		this.tail.prev = tail;
		this.tail.next = null;
	}

}
