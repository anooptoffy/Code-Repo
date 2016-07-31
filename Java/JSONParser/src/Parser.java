import java.util.LinkedList;

/*
 * json grammmar
 * 
 * http://www.json.org/
 * 
   object
		{}
		{ members }
   members
		pair
		pair , members
   pair
		string : value
   array
		[]
		[ elements ]
   elements
		value 
		value , elements
   value
		string
		number
		object
		array
		true
		false
		null
 *
 *
 */

public class Parser {
	public LinkedList<Token> tokens; // contains the list of tokens to parse
	
	
	public Parser(LinkedList<Token> tk) {
		this.tokens = tk;
		// TODO Auto-generated constructor stub
	}
	
	public void PrintTokens(){
		for (Token tok : this.tokens) {
		    System.out.println("" + tok.token + " " + tok.sequence);			    
		    
		  }
	}
	
	public JsonObject run(){

		
		return null;
	}
	
	

}
