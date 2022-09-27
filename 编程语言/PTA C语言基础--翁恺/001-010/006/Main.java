import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int height;
        height = input.nextInt();
        int foot, inches;
        inches = (int) (height / 30.48 * 12);
        foot = inches / 12;
        inches = inches % 12;
        System.out.print(foot + " " + inches);
        input.close();
    }
}