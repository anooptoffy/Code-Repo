import java.util.Scanner;
import java.math.BigInteger;
class Main {
// standard Java class name in UVa OJ
	public static void main(String[] args) {
		BigInteger fac = BigInteger.ONE, sum = BigInteger.ZERO;
		Double f1 = 2.7182818284;
		Scanner reader = new Scanner(System.in);
		int n = reader.nextInt();

		for (int i = 1; i <= n; i++)
			sum = sum.add(fac.multiply(BigInteger.doubleValue(f1)));
			fac = fac.add(BigInteger.ONE);
		// it is in the library!
		System.out.println(sum);
	}
}