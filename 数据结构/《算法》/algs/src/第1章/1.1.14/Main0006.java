import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Main0006 {
    public static int lg(int N) {
        int i = 1;
        int b = 2;
        int p = 0;
        while (i <= N) {
            i *= b;
            ++p;
        }
        return p - 1;
    }

    public static void main(String[] args) {
        int N;
        while (!StdIn.isEmpty()) {
            N = StdIn.readInt();
            StdOut.println(lg(N));
        }
    }
}
