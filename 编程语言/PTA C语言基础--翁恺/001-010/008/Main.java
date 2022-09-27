import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int H = input.nextInt();
        System.out.print((H - 100) * 0.9 * 2);
        input.close();
    }
}