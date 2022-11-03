import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Main {
	public static void main(String[] args)
	{
		String[] name = new String[10];
		int[] num1 = new int[10];
		int[] num2 = new int[10];
		for (int i = 0; i < 10; i++) {
			name[i] = StdIn.readString();
			num1[i] = StdIn.readInt();
			num2[i] = StdIn.readInt();
		}
		StdOut.printf("%-10s|%-10s|%-10s|%-10s\n", "name", "num1", "num2", "num1/num2");
		for (int i = 0; i < 10; i++) {
			StdOut.printf("----------|----------|----------|----------\n");
			StdOut.printf("%-10s|%-10d|%-10d|%-10.3f\n", name[i], num1[i], num2[i], (double)num1[i] / num2[i]);
		}
	}
}