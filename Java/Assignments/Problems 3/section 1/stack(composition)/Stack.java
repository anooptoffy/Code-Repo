/**
 * Stack Implementation using linked list. 
 * Using Composition
 * 
 * @author Anoop
 */

public class Stack {

	private LList slist; // having an instance of LList class and thus having a Has-A relationship or Composition
	
	/**
	 * Using composition
	 */

	public Stack() {
		// TODO Auto-generated constructor stub
		//super();
		slist = new LList();
	}

	void push(Object obj) {
		this.slist.append(obj);
	}

	public void pop() {
		this.slist.remove(this.slist.getPos() - 1);
	}

	public boolean isEmpty() {
		if(this.slist.getPos() == 0){
			return true;
		}
		return false;
	}
	
	

	@Override
	public String toString() {
		return "Stack [slist=" + slist + "]";
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack st = new Stack();
		System.out.println("Is list empty ? " + st.isEmpty());
		st.push(1);
		System.out.println(st);
		st.push(2);
		st.push(4);
		st.push(10);
		System.out.println(st);
		st.pop();
		System.out.println(st);
		System.out.println("Is list empty ? " + st.isEmpty());
		
	}

}
