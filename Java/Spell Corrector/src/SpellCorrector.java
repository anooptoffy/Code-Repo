import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.*;;

/*
 * 
 * My First ML related work! Feels Awesome for the knowledge gained.
 * https://en.wikipedia.org/wiki/Spell_checker
 * https://en.wikipedia.org/wiki/Edit_distance
 * http://www-01.sil.org/linguistics/wordlists/english/wordlist/wordsEn.txt
 * 
 * 1. Parse the corpus file
 * 2. Tokenize the corpus to form dictionary and add the frequency
 * 3. Case 1:
 * 		Find the exact match. Use containsKey()
 * 	  Case 2:
 * 		Using https://en.wikipedia.org/wiki/Levenshtein_distance 
 * 		1. Do for Edit Distance 1
 * 		2. Do for Edit Distance 2
 * 4. Expand to next level. 	
 * 5. To Optimize :
 * 			the word with edit distance 1 is much probable
 * 			Baye's Theorem incorporated
 * 	NLP 03 : Spell Check Algorithm : --- https://www.youtube.com/watch?v=3qHx1VCcobY
 * 	http://norvig.com/spell-correct.html
 * 
 * Micro blogs that helped:
 * 1. http://blog.notdot.net/2010/07/Damn-Cool-Algorithms-Levenshtein-Automata
 * 
 * TODO Incorporte thre removal of stop words
 * 
 * Time line:
 * 
 * Day 2 : Check the Algorithm in Peter Norvig's blogs.
 * 			Read the File. Tokenized it. Stored into HashMap with key as the word and Value as frequency of its occurrences.
 * Day 3 : Checked the Levenshtein Algorithms and implelented the Dynamic programming approach of it as EditDistance.
 * 			Add the final logic of predicting the most suitable words that is taken as the output of the Edit Distance.
 * 			And checked against the training data.
 *  
 */

public class SpellCorrector {

	public SpellCorrector() {
		// TODO Auto-generated constructor stub
	}
	
	
	// Levenshtein_distance
	public int EditDistance(char[] strOne, char[] strTwo){
	        int dp[][] = new int[strOne.length+1][strTwo.length+1];
	        
	        for(int i=0; i < dp[0].length; i++){
	            dp[0][i] = i;
	        }
	        
	        for(int i=0; i < dp.length; i++){
	            dp[i][0] = i;
	        }
	        
	        for(int i=1;i <=strOne.length; i++){
	            for(int j=1; j <= strTwo.length; j++){
	            	//System.out.println(strOne[i-1]+ " " +strTwo[j-1]);
	                if(strOne[i-1] == strTwo[j-1]){
	                	//System.out.println("Inside1 " + dp[i-1][j-1]);
	                    dp[i][j] = dp[i-1][j-1];
	                }else{
	                	//System.out.println("Inside2" + Math.min(Math.min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]));
	                    dp[i][j] = Math.min(Math.min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
	                }
	            }
	        }
//	        for(int i = 0;i <= strOne.length;i++){
//	        	for(int j= 0;j <= strTwo.length; j++){
//	        		System.out.print(dp[i][j] + " ");
//	        	}
//	        	System.out.println();
//	        }
	        		
	        return dp[strOne.length][strTwo.length];
	        
	    }

	public static void main(String[] args) throws IOException {
		
		Map<String, Integer> HMap = new HashMap<>();
		Map<String, Integer> HStop =  new HashMap<>();
		HashSet<String> HDict = new HashSet<>();
		
		// Read the training data
		BufferedReader in = new BufferedReader(new FileReader("data.txt"));
		
		BufferedReader stop = new BufferedReader(new FileReader("stopwords.txt"));
		BufferedReader dict =  new BufferedReader(new FileReader("dictionary.txt"));
		
		// Read the commonly occuring english words
		// https://raw.githubusercontent.com/dwyl/english-words/master/words.txt
		String lineR;
		while((lineR = dict.readLine()) != null){
			HDict.add(lineR);
		}
		dict.close();
		
		String lRead;
		while((lRead =  stop.readLine()) != null){
			Scanner scan = new Scanner(lRead);
			String Str;
			while(scan.hasNext()){
				Str= scan.next().toLowerCase();
				HStop.put(Str, Str.hashCode());
			}
			scan.close();
		}
		
		String lineRead;
		// KT :  https://docs.oracle.com/javase/7/docs/api/java/util/regex/Pattern.html
		//Pattern p = Pattern.compile("\\w+");
		while((lineRead = in.readLine()) != null){
			
			// TODO match only strings from each line, remove stops words and punctuation 
			String[] nstr =  lineRead.split("\\s+");
			for(String s:nstr){
				//System.out.println(s);
				s = s.replaceAll("[^a-zA-Z]", "").toLowerCase();
				if(HMap.containsKey(s))
				{
					HMap.put(s,HMap.get(s) + 1 );
				}
				else
					HMap.put(s, 1);
			}
			
			//System.out.println(lineRead);
			/*Scanner scan = new Scanner(lineRead);
			String str;
			while(scan.hasNext()){
				str = scan.next();
				str.toLowerCase();
				System.out.println(str);
				HMap.put(str, str.hashCode());
				
			}*/
			
		}
	
		FileWriter fw = new FileWriter("out.txt");
//		Iterator<Map.Entry<String, Integer>> HLine = HMap.entrySet().iterator();
//		
//		while(HLine.hasNext()){
//			fw.write(HLine.next().getKey());
//			fw.write("\n");
//			//System.out.println(HLine.next());
//			
//		}
		
		// Remove unwanted symbols
		ArrayList<String> junk =  new ArrayList<>();		
		String key;
		int nCount = 0; // Stores the count of all words appearing in the training file
		for (Map.Entry<String, Integer> entry : HMap.entrySet()) {
			key = entry.getKey();
			if(key.length() == 1 || key.length() == 0){
					junk.add(key);
			}
		}
		
		// Removing alphabets only and spaces
		for(String en: junk){
			HMap.remove(en);
		}
		
		for (Map.Entry<String, Integer> entry : HMap.entrySet()) {
		    //System.out.println(entry.getKey()+" : "+entry.getValue());
//			key = entry.getKey();
//			if(key.length() == 1 || key.length() == 0){
//				HMap.remove(key);
//				continue;
//			}
			nCount++;
		    fw.write(entry.getKey()+" : "+entry.getValue());
		    fw.write("\n");
		}
		
		fw.close();
		
		// Reading user input
		System.out.print("Miss spelled word : ");
		Scanner sn = new Scanner(System.in);
		String word = sn.next();
		
		if(HMap.containsKey(word)){
			System.out.println("Spelled Correctly");
		}else{
			SpellCorrector sp =  new SpellCorrector();
			int dis;
			ArrayList<String> matches = new ArrayList<>();
			System.out.println("Words List :");
			
			// The below program uses the dictionary taken from the training data.
			// But I feel doing it with a real dictionary that has more correct words than
			// randomly extracted wordss from the train data since it can contain mistakes!! :D
			/*for (Map.Entry<String, Integer> entry : HMap.entrySet()) {
			    //System.out.println(entry.getKey()+" : "+entry.getValue());
				String dic = entry.getKey();
			    dis = sp.EditDistance(word.toCharArray(), dic.toCharArray());
			    // 	Finding all matched for edit distance 1
			    
			    if(dis == 1){
			    	matches.add(dic);
			    	System.out.println(" " + dic);
			    }
			    else if(dis == 2){	
			    	matches.add(dic);
					System.out.println(" " + dic);
			    }else if(dis == 3)
			    {
			    	matches.add(dic);
					System.out.println(" " + dic);
			    }
			}
			*/
			
			// Find the possible matches from dictionary having edit distance 1,2,3
			for(String entry : HDict){
				dis = sp.EditDistance(word.toCharArray(), entry.toCharArray());
				// 	Finding all matched for edit distance 1
			    
			    if(dis == 1){
			    	matches.add(entry);
			    	System.out.println(" " + entry);
			    }
			    /*else if(dis == 2){	
			    	matches.add(entry);
					System.out.println(" " + entry);
			    }
			    else if(dis == 3)
			    {
			    	matches.add(entry);
					System.out.println(" " + entry);
			    }*/
				
			}
			
			// Train the data.
			// Find the probability that the correction appears in the training data.
			
			// By Baye's theorem
			// P(c|w) = ((P(w|c)*P(c))/P(w)
			// P(w) = 1
			// P(w|c) is the error model we need to form, I think it is the part that requires ML
			// Since The model should improve from time to time based on user responses.
			// 
			//System.out.println("The cumulative frequency : " + nCount);
			double pc = 0;
			double largest = 0.0;
			String matched=  null;
			for(int y = 0 ; y < matches.size(); y++){
				if(HMap.containsKey(matches.get(y))){
					pc = HMap.get(matches.get(y));
					if(pc > largest)
					{
						largest = pc;
						matched = matches.get(y);
					}
				}
				else
					pc = 0;
				//System.out.println("Probability " + pc/nCount);
			}
			
			System.out.println("The word closest : " + matched);
		}
		
		// TODO Find other ways of matching the edit distance like recursive.
		// Also there are other alogirthms for edit distance existing in the wikipedia
		
		in.close();
		stop.close();						
		
	}

}
