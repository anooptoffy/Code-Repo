
public class JsonValue {
	private String str; // null, string, true, false, string, numbers
	private JsonObject jObj;
	private JsonValue[] jArray;

	/*
	 * Implement 3 constructors each of which takes one of String, JsonObject or
	 * array of JsonValues as argument, and assigns it to the appropriate field.
	 * Only one of these three fields should be non-null
	 */
	// ... the constructors
	public JsonValue(String str) {
		this.str = str;
	}

	public String getStr() {
		return str;
	}

	public void setStr(String str) {
		this.str = str;
	}

	public JsonObject getjObj() {
		return jObj;
	}

	public void setjObj(JsonObject jObj) {
		this.jObj = jObj;
	}

	public JsonValue[] getjArray() {
		return jArray;
	}

	public void setjArray(JsonValue[] jArray) {
		this.jArray = jArray;
	}

	public JsonValue(JsonObject obj) {
		this.jObj = obj;
	}

	public JsonValue(JsonValue[] values) {
		this.jArray = values;
	}

	// we will need 3 different methods for accessing the appropriate fields.
	// Note that this helps with strong-typing
	String getString() {
		return str;
	}

	JsonObject getObj() {
		return jObj;
	}

	JsonValue[] getArray() {
		return jArray;
	}
}
