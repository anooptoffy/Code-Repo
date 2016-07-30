
import java.util.*;
public class taxi {
	int type;
	float efficiecny, remainging;
	
	taxi(){
		
	}
	
	public void add(int type,float efficiecny, float remainging){
		this.type = type;
		this.efficiecny = efficiecny;
		this.remainging = remainging;
	}
	
	public static void main(String[] args) {
		int a;
		Scanner c = new Scanner(System.in);
		a = c.nextInt();
		taxi[] t = new taxi[100];
		for(int i = 0; i < a; i++){
			t[i] = new taxi();
			t[i].type = c.nextInt();
			t[i].efficiecny = c.nextFloat();
			t[i].remainging = c.nextFloat();		
		}
		
		for(int i = 0; i < a; i++){
			//System.out.println(t[i].type +" " +  t[i].efficiecny + " " + t[i].remainging);
			if(t[i].type == 1) //diesel
				System.out.println("Car " + (i+1) + ": range = " + t[i].efficiecny * t[i].remainging);
			else
				System.out.println("Car " + (i+1) + ": range = " + ((t[i].remainging / 100 ) * 100000) / t[i].efficiecny);
			
		}
		c.close();
	}

}
