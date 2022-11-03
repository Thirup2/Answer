import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Main {
	public static void main(String[] args)
	{
		int N = StdIn.readInt();
		int M = StdIn.readInt();
		int[] a = new int[N];
		int[] b = histogram(a, M);
		for (int i = 0; i < M; i++) {
			StdOut.println(b[i]);
		}
	}

	public static int[] histogram(int[] a, int M)
	{
		int b[] = new int[M];
		for (int i = 0; i < a.length; i++) {
			if (a[i] >= 0 && a[i] <= M - 1) {
				b[a[i]]++;
			}
		}
		return b;
	}
}