import java.util.Scanner;
import java.lang.Math;

public class exercise5 {
    private static void ex5(Scanner sc) {
        System.out.print("Enter a degree in Celsius:");
        int c = sc.nextInt();
        double f = 1.8 * c + 32;
        System.out.printf("%d Celsius is %.1f Fahrenheit\n", c, f);
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex5(sc);
        sc.close();
    }
}