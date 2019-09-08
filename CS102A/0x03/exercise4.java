import java.util.Scanner;
import java.lang.Math;

public class exercise4 {
    private static void ex4(Scanner sc) {
        System.out.print("Input the number of minutes:");
        int mins = sc.nextInt();
        int days = mins / 60 / 24;
        int years = days / 365;
        days %= 365;
        System.out.printf("%d minutes is approximately %d years and %d days.\n", mins, years, days);
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex4(sc);
        sc.close();
    }
}