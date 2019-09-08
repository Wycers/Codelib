import java.util.Scanner;
import java.lang.Math;

public class exercise3 {
    private static void ex3(Scanner sc) {
        System.out.printf("Input x1 and y1:");
        double x1 = sc.nextDouble();
        double y1 = sc.nextDouble();
        System.out.printf("Input x2 and y2:");
        double x2 = sc.nextDouble();
        double y2 = sc.nextDouble();
        System.out.printf("The distance of the two points is %.10f\n",
                Math.pow(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2), 0.5));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex3(sc);
        sc.close();
    }
}