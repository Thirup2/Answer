import edu.princeton.cs.algs4.StdOut;

public class Main0009 {
    public static int ln_fact(int N) {
        return ln(fact(N));
    }

    public static double fact(int N) {
        if (N == 1 || N == 0) return 1;
        if (N == 2) return 2;
        return N * fact(N - 1);
    }

    public static int ln(double N) {
        double e = Math.E;
        double i = 1;
        int p = 0;
        while (i <= N) {
            i *= e;
            p++;
        }
        return p - 1;
    }

    public static void main(String[] args) {
        for (int i = 0; i < 100; i++) {
            StdOut.println(i + " " + ln_fact(i));
        }
    }
}
