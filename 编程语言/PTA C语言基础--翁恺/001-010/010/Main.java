import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int a, b;
        a = input.nextInt();
        b = input.nextInt();
        System.out.println(a + " + " + b + " = " + (a + b));
        System.out.println(a + " - " + b + " = " + (a - b));
        System.out.println(a + " * " + b + " = " + (a * b));
        System.out.print(a + " / " + b + " = ");
        if (a % b == 0) {
            System.out.printf("%d", a / b);
        } else {
            System.out.printf("%.2f", (double) a / b);
        }
        input.close();
    }
}