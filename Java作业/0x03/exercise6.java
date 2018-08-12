import java.util.Scanner;
import java.lang.Math;

public class exercise6 {
    private static void ex6(Scanner sc) {
        System.out.print("Enter the radius and length of a cylinder:");
        double r = sc.nextDouble();
        double l = sc.nextDouble();
        System.out.printf("The area is %.4f\n", r * r * Math.PI);
        System.out.printf("he volume is %.1f\n", r * r * Math.PI * l);
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex6(sc);
        sc.close();
    }
}