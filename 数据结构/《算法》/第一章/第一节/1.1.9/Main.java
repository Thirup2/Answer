import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Main {
	public static void main(String[] args)
	{
		String s = "";
		int n = StdIn.readInt();
		for (; n > 0; n /= 2) {
			s = (n % 2) + s;
		}
		StdOut.println(s);
	}
}