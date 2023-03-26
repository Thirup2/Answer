import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Main0010 {
    public static void main(String[] args) {
        int N = StdIn.readInt();
        String[] name = new String[N];
        int[] num1 = new int[N];
        int[] num2 = new int[N];
        for (int i = 0; i < N; i++) {
            name[i] = StdIn.readString();
            num1[i] = StdIn.readInt();
            num2[i] = StdIn.readInt();
        }
        for (int i = 0; i < N; i++) {
            StdOut.printf("%10s%3d%3d%10.3f\n", name[i], num1[i], num2[i], (double) num1[i] / num2[i]);
        }
    }
}
