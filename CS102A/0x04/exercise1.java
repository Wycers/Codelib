import java.lang.Math;
import java.util.Scanner;

public class exercise1 {
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex1(Scanner sc) {
        print("Enter a, b, c:");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextDouble();
        double delta = Math.pow(b, 2) - 4.0 * a * c;
        if (delta < 0) {
            print("The equation has no real roots.\n");
            return;
        }
        double tmp = Math.sqrt(delta);
        double r1 = (-1 * b + tmp) / (2 * a);
        double r2 = (-1 * b - tmp) / (2 * a);
        if (Math.abs(delta) < 1e-10) 
            print(String.format("The root is %.5f\n", r1));
        else
            print(String.format("The roots are %.5f and %.5f\n", r1, r2));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex1(sc);
        sc.close();
    }
}