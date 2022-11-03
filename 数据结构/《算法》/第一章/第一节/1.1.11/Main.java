import edu.princeton.cs.algs4.StdOut;

public class Main {
	public static void main(String[] args)
	{
		boolean b[][] = new boolean[10][10];
		StdOut.printf("  1 2 3 4 5 6 7 8 9 10\n");
		b[1][2] = true;
		b[5][4] = true;
		for (int i = 0; i < 10; i++) {
			StdOut.print(i + 1);
			for (int j = 0; j < 10; j++) {
				if (b[i][j] == true)
					StdOut.print(" *");
				else {
					StdOut.print("  ");
				}
			}
			StdOut.println();
		}
	}
}