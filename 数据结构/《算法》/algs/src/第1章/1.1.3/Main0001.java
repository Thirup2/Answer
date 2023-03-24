import edu.princeton.cs.algs4.StdOut;

public class Main0001 {
    public static void main(String[] args) {
        int N = 3;
        if (args.length < N) {
            StdOut.println("参数不足！");
            return;
        }
        int[] arr = new int[N];
        for (int i = 0; i < N; ++i) {
            arr[i] = Integer.parseInt(args[i]);
        }
        boolean b = true;
        for (int i = 1; i < N; ++i) {
            if (arr[i] != arr[i - 1]) {
                b = false;
                break;
            }
        }
        if (b) {
            StdOut.println("equal!");
        } else {
            StdOut.println("not equal!");
        }
    }
}
