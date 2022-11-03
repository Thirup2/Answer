import edu.princeton.cs.algs4.StdOut;

public class Main {
	public static void main(String[] args)
	{
		int a[][] = new int[10][10];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				a[i][j] = i - j;
			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				StdOut.print(a[j][i] + " ");
			}
			StdOut.println();
		}
	}
}