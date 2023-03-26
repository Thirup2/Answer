import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.util.Arrays;

public class Main0012 {
    public static int rank(int key, int[] a) {
        return rank(key, a, 0, a.length - 1);
    }

    public static int rank(int key, int[] a, int lo, int hi) {
        if (lo > hi) return -1;
        int mid = lo + (hi - lo) / 2;
        if (key < a[mid]) return rank(key, a, lo, mid - 1);
        else if (key > a[mid]) return rank(key, a, mid + 1, hi);
        else return mid;
    }

    public static void main(String[] args) {
        if (args.length < 2) {
            StdOut.println("参数不足");
            return;
        }
        int[] whitelist = In.readInts(args[0]);
        Arrays.sort(whitelist);
        while (!StdIn.isEmpty()) {
            int key = StdIn.readInt();
            if (args[1].equals("+")) {
                if (rank(key, whitelist) == -1)
                    StdOut.println(key + " is not exist");
            }
            if (args[1].equals("-")) {
                if (rank(key, whitelist) != -1)
                    StdOut.println(key + " exist");
            }
        }
    }
}
