import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Main {
	public static void main(String[] args)
	{
		int N = StdIn.readInt();
		StdOut.println(ln_fact(N));
	}

	public static double ln_fact(int N)
	{
		double m = fact(N);
		return Math.log(m);
	}

	public static double fact(int N)
	{
		double result = 1;
		for (int i = N; i > 1; i--) {
			result *= i;
		}
		return result;
	}
}