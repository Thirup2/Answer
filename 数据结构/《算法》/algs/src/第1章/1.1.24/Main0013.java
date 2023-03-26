import edu.princeton.cs.algs4.StdOut;

public class Main0013 {
    static int i = 1;

    public static int gcd(int p, int q) {
        StdOut.println("The " + i + " times: " + "p = " + p + "; q = " + q);
        i++;
        if (q == 0) return p;
        int r = p % q;
        return gcd(q, r);
    }

    public static void main(String[] args) {
        if (args.length < 2) {
            StdOut.println("参数不足");
            return;
        }
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        StdOut.println("Now is starting to work out " + a + " " + b);
        StdOut.println("The result is " + gcd(a, b));
    }
}
