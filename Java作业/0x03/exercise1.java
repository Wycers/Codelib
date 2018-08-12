import java.util.Scanner;
import java.lang.Math;

public class exercise1 {
    private static void ex1(Scanner sc) {
        System.out.print("Input a and b:");
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.printf("a + b = %d\n", a + b);
        System.out.printf("a - b = %d\n", a - b);
        System.out.printf("a * b = %d\n", a * b);
        if (b != 0)
            System.out.printf("a / b = %.2f\n", (double) a / b);
        else
            System.out.printf("b is ZERO!\n");
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex1(sc);
        sc.close();
    }
}