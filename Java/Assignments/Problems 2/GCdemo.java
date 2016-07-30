public class GCdemo {
private class Blob {
	int[] space = new int[10000];
	
	protected void finalize(){
		System.out.println("Deallocating");
	}
}
public static void main(String[] args) {
// run this with increasing values of n.
// How large can n be?
	int n = 1000000;
	GCdemo gc = new GCdemo();
	Blob blobStore[] = new Blob[n];
	//Runtime r = Runtime.getRuntime();
	//System.out.println("Available Free Memory : " + r.freeMemory());
	for(int i=0;i<n;i++) {
		//System.out.println("Available Free Memory : " + r.freeMemory());
		System.out.println(i);
		Blob b = gc.new Blob();
		// what happens if you comment the following
		blobStore[i] = b;
		
	}
	//gc = null;
	/*System.runFinalization();
	System.gc();*/
	}
}
