import java.util.LinkedList;

public class Parser {
	public LinkedList<Tokenizer.Token> tokens;
	
	
	public Parser(LinkedList<Tokenizer.Token> tk) {
		this.tokens = tk;
		// TODO Auto-generated constructor stub
	}
	
	public void PrintTokens(){
		for (Tokenizer.Token tok : this.tokens) {
		    System.out.println("" + tok.token + " " + tok.sequence);			    
		    
		  }
	}
	
	public JsonObject run(){

				JsonObject jobj =  new JsonObject();
				if(this.tokens.getFirst().token == Tokenizer.Token.OpenBrace){
					//System.out.println("Hai");
					this.tokens.pop(); // popping {
					if(this.tokens.getFirst().token == Tokenizer.Token.Qutoes){
						//System.out.println("Hai");
						this.tokens.pop(); // popping quotes
						String key =  this.tokens.getFirst().sequence;
						System.out.println("The key is " + key);
						//System.out.println("Hai");
						//System.out.println("what0 " + this.tokens.getFirst().sequence);
						this.tokens.pop();  // popping key
						//System.out.println("what1 " + this.tokens.getFirst().sequence);
						this.tokens.pop(); // popping quotes
						//System.out.println(this.tokens.getFirst().sequence);
						if(this.tokens.getFirst().token == Tokenizer.Token.SemiColon){
							//System.out.println("Hai");
							this.tokens.pop(); // popping semicolon
							switch(this.tokens.getFirst().token){
							case Tokenizer.Token.Qutoes: // indicate it is JSON String
								this.tokens.pop();  // popping quotes
								String value = this.tokens.getFirst().sequence;								
								//System.out.println("The value " + value + "The Key " + key);
								JsonObject.JsonValue jv = jobj.setValue(value);
								jobj.add(key, jv);
								this.tokens.pop(); // popping values
								this.tokens.pop(); // popping quotes
								if(this.tokens.getFirst().token == Tokenizer.Token.Comma){
									//
									//System.out.println("Next");
									this.tokens.pop(); // popping comma
									//System.out.println(this.tokens.getFirst().sequence);
									jobj.obj = this.run();																	   
								}else{
									// done
								}
								break;
							case Tokenizer.Token.OpenBracket: //  indicate it is a JSON Array
								System.out.println("Array found");
								break;
							case Tokenizer.Token.OpenBrace: // indicate it another JSON Object
								jobj.obj =  this.run();
								break;
								default :
									System.out.println("Invalid JSON!!!");
									break;
							}
						}
						
					}
					else{
						System.out.println("Empty!");
					}
				}
				else if(this.tokens.getFirst().token == Tokenizer.Token.Qutoes){
					//System.out.println("Hai");
					this.tokens.pop(); // popping quotes
					String key =  this.tokens.getFirst().sequence;
					System.out.println("The key is " + key);
					//System.out.println("Hai");
					//System.out.println("what0 " + this.tokens.getFirst().sequence);
					this.tokens.pop();  // popping key
					//System.out.println("what1 " + this.tokens.getFirst().sequence);
					this.tokens.pop(); // popping quotes
					//System.out.println(this.tokens.getFirst().sequence);
					if(this.tokens.getFirst().token == Tokenizer.Token.SemiColon){
						//System.out.println("Hai");
						this.tokens.pop(); // popping semicolon
						switch(this.tokens.getFirst().token){
						case Tokenizer.Token.Qutoes: // indicate it is JSON String
							this.tokens.pop();  // popping quotes
							String value = this.tokens.getFirst().sequence;								
							//System.out.println("The value " + value + "The Key " + key);
							JsonObject.JsonValue jv = jobj.setValue(value);
							jobj.add(key, jv);
							this.tokens.pop(); // popping values
							this.tokens.pop(); // popping quotes
							if(this.tokens.getFirst().token == Tokenizer.Token.Comma){
								//
								//System.out.println("Next");
								this.tokens.pop();
								//System.out.println(this.tokens.getFirst().sequence);
								jobj.obj = this.run();																	   
							}else{
								// done
							}
							break;
						case Tokenizer.Token.OpenBracket: //  indicate it is a JSON Array
							System.out.println("Array found");
							this.tokens.pop();
							while(this.tokens.getFirst().token != Tokenizer.Token.CloseBracket){
								if(this.tokens.getFirst().token == Tokenizer.Token.Strings){
									//System.out.println(this.tokens.getFirst().sequence);
								}
								else if(this.tokens.getFirst().token == Tokenizer.Token.OpenBrace){
									jobj.obj = this.run();
								}
								System.out.println(this.tokens.getFirst().sequence);
								this.tokens.pop();
							}
							this.tokens.pop();
							if(this.tokens.getFirst().token == Tokenizer.Token.Qutoes){
								//
								//System.out.println("Next");
								//this.tokens.pop();
								//System.out.println(this.tokens.getFirst().sequence);
								jobj.obj = this.run();																	   
							}else{
								// done
							}
							System.out.println("Value" + this.tokens.getFirst().sequence);
							break;
						case Tokenizer.Token.OpenBrace: // indicate it another JSON Object
							//System.out.println("Neternisgsdgsd");
							jobj.obj =  this.run();
							break;
							default :
								System.out.println("Invalid JSON!!!");
								break;
						}
					}
					
				}
				else{
					System.out.println("Done Parsing");
				}
				return jobj;
	}
	
	

}
