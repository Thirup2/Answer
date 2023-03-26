import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class Main0007 {
    public static int[] histogram(int[] a, int M) {
        int[] result = new int[M];
        for (int i = 0; i < M; ++i) {
            result[i] = count(a, i);
        }
        return result;
    }

    public static int count(int[] a, int val) {
        int cnt = 0;
        for (int j : a) {
            if (j == val) {
                ++cnt;
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        int M = StdIn.readInt();
        int N = StdIn.readInt();
        int[] a = new int[M];
        for (int i = 0; i < M; ++i) {
            a[i] = StdRandom.uniformInt(N);
        }
        for (int i : a) {
            StdOut.print(i + " ");
        }
        StdOut.println();
        int[] cnt_arr = histogram(a, N);
        for (int i : cnt_arr) {
            StdOut.print(i + " ");
        }
        StdOut.println();
        StdOut.print(a.length + " ");
        int sum = 0;
        for (int i : cnt_arr) {
            sum += i;
        }
        StdOut.println(sum);
    }
}
