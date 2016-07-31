import java.util.LinkedList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Tokenizer {
	private LinkedList<TokenInfo> tokenInfos;
	private LinkedList<Token> tokens;

	public Tokenizer() {
		tokenInfos = new LinkedList<TokenInfo>(); // set of possible tokens
		tokens = new LinkedList<Token>(); // tape
	}

	public void add(String regex, int token) {
		tokenInfos.add(new TokenInfo(Pattern.compile("^(" + regex + ")"), token));
	}

	private class TokenInfo {
		public final Pattern regex;
		public final int token;

		public TokenInfo(Pattern regex, int token) {
			super();
			this.regex = regex;
			this.token = token;
		}
	}

	public void tokenize(String str) {
		String s = new String(str);

		for (int i = 0; i < s.length(); i++) {
			Character cc = s.charAt(i);
			StringBuilder sts = new StringBuilder();
			sts.append(cc);
			if (cc.toString().matches("\\s+"))
				continue;
			if (cc.toString().matches("[a-zA-Z0-9_ ]")) {

				i++;
				cc = s.charAt(i);
				while (cc.toString().matches("[a-zA-Z0-9_ ]")) {
					sts.append(cc);
					i++;
					cc = s.charAt(i);
				}
				i--;
			}
			String ss = sts.toString();
			boolean match = false;
			for (TokenInfo info : tokenInfos) {
				Matcher m = info.regex.matcher(ss);
				// System.out.println("Matched : " + m + "Token " + ss);
				if (m.find()) {
					match = true;

					String tok = m.group().trim();
					// System.out.println("Tokens " + tok);
					tokens.add(new Token(info.token, tok));

					ss = m.replaceFirst("");
					break;
				}
			}
			if (!match)
				throw new ParserException("Unexpected character in input: " + s);

		}

	}

	public LinkedList<Token> getTokens() {
		return tokens;
	}

	
}
