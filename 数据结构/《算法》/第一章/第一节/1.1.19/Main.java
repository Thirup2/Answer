import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Main {
	public static void main(String[] args)
	{
		int M = StdIn.readInt();
		int fibonacci[] = new int[M];
		fibonacci[0] = 0;
		fibonacci[1] = 1;
		for (int i = 2; i < M; i++) {
			fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
		}
		for (int N = 0; N < M; N++)
			StdOut.println(N + " " + fibonacci[N]);
	}
}