import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n1, n2, n3, n4;
        n1 = input.nextInt();
        n2 = input.nextInt();
        n3 = input.nextInt();
        n4 = input.nextInt();
        System.out.print("Sum = " + (n1 + n2 + n3 + n4) + "; Average = ");
        System.out.printf("%.1f", (n1 + n2 + n3 + n4) / 4.0);
        input.close();
    }
}