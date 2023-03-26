import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class Main0005 {
    public static void main(String[] args) {
        final int M = StdIn.readInt(), N = StdIn.readInt();
        int[][] matrix = new int[M][N];
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                matrix[i][j] = StdRandom.uniformInt(100);
            }
        }
        PrintMatrix(matrix, M, N);
        StdOut.println();
        int[][] reversedmatrix = new int[N][M];
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < M; ++i) {
                reversedmatrix[j][i] = matrix[i][j];
            }
        }
        PrintMatrix(reversedmatrix, N, M);
    }

    public static void PrintMatrix(int[][] matrix, int M, int N) {
        StdOut.print("  ");
        for (int j = 0; j < N; ++j) {
            StdOut.printf("%3d", j + 1);
        }
        StdOut.println();
        for (int i = 0; i < M; ++i) {
            StdOut.printf("%2d", i + 1);
            for (int j = 0; j < N; ++j) {
                StdOut.printf("%3d", matrix[i][j]);
            }
            StdOut.println();
        }
    }
}
