import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.util.Arrays;

public class Main0011 {
    public static int rank(int key, int[] a) {
        int level = 1;
        StdOut.println("Finding " + key + "...");
        return rank(key, a, 0, a.length - 1, level);
    }

    public static int rank(int key, int[] a, int lo, int hi, int level) {
        StdOut.println("lo = " + lo + "; hi = " + hi + "; level = " + level);
        if (lo > hi) return -1;
        int mid = lo + (hi - lo) / 2;
        if (key < a[mid]) return rank(key, a, lo, mid - 1, level + 1);
        else if (key > a[mid]) return rank(key, a, mid + 1, hi, level + 1);
        else return mid;
    }

    public static void main(String[] args) {
        int[] whitelist = In.readInts(args[0]);
        Arrays.sort(whitelist);
        while (!StdIn.isEmpty()) {
            int key = StdIn.readInt();
            if (rank(key, whitelist) == -1)
                StdOut.println(key + " is not exist");
        }
    }
}
