import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int F;
        F = input.nextInt();
        System.out.print("Celsius = " + (5 * (F - 32) / 9));
        input.close();
    }
}
