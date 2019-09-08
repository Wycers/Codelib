import java.lang.Math;
import java.util.Scanner;

public class exercise2 {
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex2(Scanner sc) {
        print("Enter a point within two coordinates:");
        double x = sc.nextDouble();
        double y = sc.nextDouble();
        double tmp = Math.sqrt(x * x + y * y);
        print(String.format("Point (%.1f, %.1f) is" + (tmp < 10 ? "" : " not") + " in the circle", x, y));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex2(sc);
        sc.close();
    }
}