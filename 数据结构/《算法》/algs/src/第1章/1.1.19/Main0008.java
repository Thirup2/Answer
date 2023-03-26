import edu.princeton.cs.algs4.StdOut;

public class Main0008 {

    public static long F(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;
        return F(N - 1) + F(N - 2);
    }

    public static long F(long[] a, int N) {
        if (N == 0) return a[0];
        if (N == 1) return a[1];
        return a[N - 1] + a[N - 2];
    }

    public static long[] resize(long[] a, int N) {
        if (N <= a.length) return a;
        long[] temp = new long[N];
        for (int i = 0; i < a.length; i++) {
            temp[i] = a[i];
        }
        for (int i = a.length; i < N; i++) {
            temp[i] = a[i - 1] + a[i - 2];
        }
        return temp;
    }

    public static void main(String[] args) {
        long[] fibonacci = {0, 1};
        for (int N = 0; N < 100; N++) {
            fibonacci = resize(fibonacci, N);
            StdOut.println(N + " " + F(fibonacci, N));
        }
        for(int N = 0; N < 100; N++) {
            StdOut.println(N + " " + F(N));
        }
    }
}
