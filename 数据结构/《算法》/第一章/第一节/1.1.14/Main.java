import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Main {
	public static void main(String[] args)
	{
		int N = StdIn.readInt();
		StdOut.println(lg(N));
	}

	public static int lg(int N)
	{
		int t = 1;
		int i = 0;
		while (t <= N) {
			i++;
			t = 1;
			for (int j = 0; j < i; j++) {
				t *= 2;
			}
		}
		return i - 1;
	}
}