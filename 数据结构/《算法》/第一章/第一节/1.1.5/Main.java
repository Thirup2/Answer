import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Main {
	public static void main(String[] args)
	{
		double x, y;
		x = StdIn.readDouble();
		y = StdIn.readDouble();
		if (x >= 0 && x <= 1 && y >= 0 && y <= 1) {
			StdOut.println(true);
		} else {
			StdOut.println(false);
		}
	}
}