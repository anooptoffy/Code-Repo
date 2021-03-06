import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;

public class JsonObject {
	
	public String key;
	public JsonValue value;
	public JsonObject obj;
	private Map<String, JsonValue> valuePair;
	
	public JsonObject() {
		
	}

	// add a name/value pair to the object
	public void add(String name, JsonValue value) {
		valuePair.put(name, value);
	}
	
	// return the value corresponding to a name.
	// return null if the name does not exist
	public JsonValue get(String name) {
		return null;
	}
	
	public JsonValue setValue(String name){
		JsonValue js =  new JsonValue(name);
		return js;
	}
	

	// prints out the JsonObject
	public String toString() {
		
		if(this.key != null)
		{
			System.out.print("\"" + this.key + "\"" + ":" + "\"" + this.value.getString() + "\"");
			if(this.obj != null){
				System.out.println(",");
				System.out.println(this.obj);
			}
		}
		
		return "";
	}
	
	
	public static void main(String[] args) throws IOException {
		
		// The main program should read the json file. Parse it and store it in the JsonObject Object and then
		// print the Json Object
		
		//Token tks;
		Tokenizer tokenizer = new Tokenizer();
		tokenizer.add("\\{", 1); 
		tokenizer.add("\\}", 2); 
		tokenizer.add(",", 3);
		tokenizer.add("\\:", 4);
		tokenizer.add("\"", 5);
		tokenizer.add("\\[", 6);
		tokenizer.add("\\]", 7);
		tokenizer.add("[a-zA-Z][a-zA-Z0-9_ ]*", 8);
		tokenizer.add("[0-9]+", 9);
		
		
		
		try {
			// Step 1 : Reading the file(data.json) that contains the valid JSON.
			// Assumptions made. No invalid JSON provided.
			BufferedReader bf = new BufferedReader(new FileReader("data.json"));
								
			// Step 2 : Building up the JSON Object JsonObject.
			// Read each character in the file and build the JsonObject from it.
			
			//String st = fp.readUTF();
			//System.out.println(st);
			String st;
			while((st = bf.readLine()) != null){
				try {
					  tokenizer.tokenize(st);					  
					}
					catch (ParserException e) {
					  System.out.println(e.getMessage());
					}
				
			}
						
			
			/*for (Tokenizer.Token tok : tokenizer.getTokens()) {
			    System.out.println("" + tok.token + " " + tok.sequence);			    
			    
			  }*/
			
			Parser parse = new Parser(tokenizer.getTokens());
			parse.PrintTokens();
			
			// Implemeted getNextToken()
			//System.out.println(tokenizer.getNextToken().sequence);
			//System.out.println(tokenizer.getNextToken().sequence);
			// Moded getNextToken() to parser class
			
			// Doing parser Implementation
			
//			JsonObject jobj;
//			jobj = parse.run();
			
//			System.out.println("{");
//			System.out.println(jobj);
//			System.out.println("}");
			// Step 3 : Output the JsonObject to the Console.
			
			// Step 4 : Get a value for a give Key in the Object.
			
			// Step 5 : Add JSON Validation.
			
			try {
				bf.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
						
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}