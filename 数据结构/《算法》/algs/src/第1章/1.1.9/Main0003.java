import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Main0003 {
    public static void main(String[] args) {
        int i = StdIn.readInt();
        String s = "";
        for (int n = i; n > 0; n /= 2) {
            s = (n % 2) + s;
        }
        StdOut.println(i + "[10] = " + s + "[2]");
    }
}
