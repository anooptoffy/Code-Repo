import java.util.LinkedList;
import java.util.ListIterator;

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
	private Token tkn;
	
	public Parser(LinkedList<Token> tk) {
		this.tokens = tk;
		// TODO Auto-generated constructor stub
	}
	
	static private ListIterator<Token> lexeme;
	private boolean alreadyExecuted = false;

	public Token getNextToken() {
		if (!alreadyExecuted) {
			lexeme = (ListIterator<Token>) tokens.listIterator();
			alreadyExecuted = true;
		}
		try {
			return lexeme.next();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}
	
	public void PrintTokens(){
		for (Token tok : this.tokens) {
		    System.out.println("" + tok.token + " " + tok.sequence);			    
		    
		  }
	}
	
	public JsonObject run(){
		// Begin Parsing
		JsonObject ob = object();
		return ob;
	}

	private JsonObject object() {
		// TODO Auto-generated method stub
		JsonObject obj = null;
		tkn = getNextToken();
		if(tkn.token != Token.OpenBrace){
			throw new ParserException("Out of order {");
		}
		
		obj = members();
		
		tkn = getNextToken();
		if(tkn.token != Token.CloseBrace){
			throw new ParserException("Out of order }");
		}
		
		return obj;
	}

	private JsonObject members() {
		// TODO Auto-generated method stub
		tkn = getNextToken();
		return null;
	}

	public Token getTkn() {
		return tkn;
	}

	public void setTkn(Token tkn) {
		this.tkn = tkn;
	}
	
	
	
	

}
