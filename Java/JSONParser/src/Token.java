public class Token {

	public static final int OpenBrace = 1;
	public static final int CloseBrace = 2;
	public static final int Comma = 3;
	public static final int SemiColon = 4;
	public static final int Qutoes = 5;
	public static final int OpenBracket = 6;
	public static final int CloseBracket = 7;
	public static final int Strings = 8;
	public static final int Integeres = 9;

	public final int token;
	public final String sequence;

	public Token(int token, String sequence) {
		super();
		this.token = token;
		this.sequence = sequence;
	}

}