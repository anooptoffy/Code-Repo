import java.util.Scanner;

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


	public void push(T obj) {
		this.slist.append(obj);
	}
	
	public void pop() {
		this.slist.remove(this.slist.getPos() -  1);
	}

	public T top(){
		return this.slist.get(this.slist.getPos());
	}
	
	public boolean isEmpty() {
		if(this.slist.getPos() == 0){
			return true;
		}
		return false;
	}
	
	public boolean isMatching(Character st1, Character st2){
		
		if(st1.equals('{') && st2.equals('}'))
			return true;
		else if(st1.equals('}') && st2.equals('{'))
			return true;
		else if(st1.equals('(') && st2.equals(')'))
			return true;
		else if(st1.equals(')') && st2.equals('('))
			return true;
		else if(st1.equals('[') && st2.equals(']'))
			return true;
		else if(st1.equals(']') && st2.equals('['))
			return true;
		else
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
		
		Stack<Character> stack =  new Stack<Character>();
		StringBuilder str= new StringBuilder();
		Scanner scan = new Scanner(System.in);
		str.append(scan.nextLine());
		
		//System.out.println("Hello");
		
		for(int i = 0 ; i < str.length(); i++){
			Character st =  str.charAt(i);
			
			//System.out.println(stack);
			//System.out.println(st);
			
			if(st.equals('{') || st.equals('[') || st.equals('(')){
				stack.push(st);
				//System.out.println(stack);
				if(stack.isEmpty()){
					System.out.println("Not balanced");
					return;
				}
				continue;
			}
			else if(st.equals('}') || st.equals(']') || st.equals(')')){
				
				if(stack.isEmpty()){
					System.out.println("Not balanced");
					return;
				}
				
				if(!stack.isMatching(st, stack.top())){
					System.out.println("Not balanced");
					return;
				}else{
					stack.pop();
				}
			}
		}
		if(stack.isEmpty()){
			System.out.println("Balanced");
			}
		else{
			System.out.println("Not balanced");
		}
		
		
		//System.out.println(str);
		
	}

}
