import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class Main0004 {
    public static void main(String[] args) {
        int i = StdIn.readInt(), j = StdIn.readInt();
        boolean[][] matrix = new boolean[i][j];
        for (int m = 0; m < i; m++) {
            for (int n = 0; n < j; n++) {
                matrix[m][n] = StdRandom.bernoulli();
            }
        }
        StdOut.print(" ");
        for (int m = 0; m < j; m++) {
            StdOut.print(" " + (m + 1));
        }
        StdOut.println();
        for (int m = 0; m < i; m++) {
            StdOut.print(m + 1);
            for (int n = 0; n < j; n++) {
                StdOut.print(" " + (matrix[m][n] ? "*" : " "));
            }
            StdOut.println();
        }
    }
}
