/**
 * Generic Stack Implementation  
 * Using Composition
 * 
 * @author Anoop
 */

public class Stack<T> {

	private LList<T> slist; // having an instance of LList class and thus having a Has-A relationship or Composition
	
	/**
	 * Using composition
	 */

	public Stack() {
		//super();
		slist = new LList<T>();
	}

	void push(T obj) {
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
		
		// Creating a Integer Stack
		Stack<Integer> st = new Stack<Integer>();
		System.out.println("Is Stack empty ? " + st.isEmpty());
		st.push(1);
		System.out.println(st);
		st.push(2);
		st.push(4);
		st.push(10);
		System.out.println(st);
		st.pop();
		System.out.println(st);
		System.out.println("Is Stack empty ? " + st.isEmpty());
		
		// Creating a String Stack
		
		Stack<String> str = new Stack<String>();
		System.out.println("Is Stack Empty ? " + str.isEmpty());
		str.push("Anoop");
		str.push("Anshul");
		str.push("Ayush");
		str.push("Ankit");
		str.push("Mandeep");
		str.push("Prajwal");
		str.pop();
		System.out.println(str);
		System.out.println("Is Stack Empty ? " + str.isEmpty());
		
		// Creating a Car Stack
		
		Stack<Car> cStack = new Stack<Car>();
		Car car1= new Car(1, "Maruti");
		cStack.push(car1);
		Car car2= new Car(1, "Audi");
		cStack.push(car2);
		System.out.println(cStack);
		cStack.pop();
		System.out.println(cStack);
		
	}

}
