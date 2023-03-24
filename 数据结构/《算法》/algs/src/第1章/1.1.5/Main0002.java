import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Main0002 {
    public static void main(String[] args) {
        double x = StdIn.readDouble(), y = StdIn.readDouble();
        if ((x > 0.0 && x < 1.0) && (y > 0.0 && y < 1.0)) {
            StdOut.println("true");
        } else {
            StdOut.println("false");
        }
    }
}
