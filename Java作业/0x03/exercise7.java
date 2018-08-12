import java.util.Scanner;
import java.lang.Math;

public class exercise7 {
    private static void ex7(Scanner sc) {
        System.out.print("Input a number between 0 and 1000:");
        int sum = 0;
        for (int a = sc.nextInt(); a > 0; a /= 10)
            sum += a % 10;
        System.out.printf("The sum of the digits is %d\n", sum);
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex7(sc);
        sc.close();
    }
}