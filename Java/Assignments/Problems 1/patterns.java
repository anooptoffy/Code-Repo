
public class patterns {

	public static void main(String[] args) {
				
		StringBuilder num = new StringBuilder("0123456789");

		StringBuilder prefix = new StringBuilder();
		StringBuilder suffix = new StringBuilder();
		for(int i = 0;i < 10; i++){
			
			System.out.println(prefix + "" + i + suffix);
			prefix.append(i);
			suffix.insert(0, i);
		}
		
		
		long value = 0;
		String space ="          ";		
		System.out.println(space.substring(0,10)+"0");
		for(int i = 1,j=9; i < 10; i++,j--){
			value = value * 10 + 1;
			System.out.println(space.substring(0,j)+"0"+value * value+"0");
		}
	}

}
