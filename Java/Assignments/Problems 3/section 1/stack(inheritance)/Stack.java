

/*
 * Stack implementation using LList
 * using Inheritance
 * 
 * It requires one to redefine the append and remove of LList as push and pop of Stack respevtively when 
 * using Inheritance.
 * 
 */
public class Stack extends LList{

	private Node head;
	public Node getHead() {
		return head;
	}

	public void setHead(Node head) {
		this.head = head;
	}

	public Node getLast() {
		return last;
	}

	public void setLast(Node last) {
		this.last = last;
	}

	private Node last;
	private int  pos;
	
	public Stack() {
		// TODO Auto-generated constructor stub
		this.setPos(0);
		this.setHead(null);
		this.setLast(null);
	}
	
	@Override
	public void append(Object obj){
		Node newNode = new Node(obj);
		if(this.head == null){
			this.head = newNode;
			this.last =  newNode;
		}
		else{
			this.last.setNext(newNode);;
			this.last = this.last.getNext();
		}
		this.pos++;
	}
	
	public void push(Object obj)
	{
		this.append(obj);
	}
	
	@Override
	public String toString() {
		StringBuilder str = new StringBuilder();
		str.append("Head->");
		Node temp = this.head;
		// System.out.println("Hello");
		while (temp != null) {
			// System.out.println("Hello");
			str.append(temp.getData() + "->");
			temp = temp.getNext();
		}
		str.append("NULL");
		return str.toString();
	}
	
	public void pop(){
		int p = 0;
		Node temp = this.head,prev = null;
		while(p != pos - 1){
			prev = temp;
			temp = temp.getNext();
			p++;
		}
		prev.setNext(null);		
		this.pos--;
	}


	public boolean isEmpty(){
		if(this.getPos() == 0)
			return true;
		else
			return false;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack st = new Stack();
		System.out.println("Is empty ? " + st.isEmpty());
		st.push(1);
		System.out.println(st);
		st.push(2);
		st.push(100);
		st.push(200);
		System.out.println(st);
		st.pop();
		st.pop();
		System.out.println(st);

	}

	@Override
	public int getPos() {
		return pos;
	}

	@Override
	public void setPos(int pos) {
		this.pos = pos;
	}

}
