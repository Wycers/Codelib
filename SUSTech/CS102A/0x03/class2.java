import java.util.Scanner;
import java.lang.Math;

public class class2 {
    private static int max(int a, int b) {
        return a > b ? a : b;
    }

    private static int min(int a, int b) {
        return a > b ? b : a;
    }

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

    private static void ex2(Scanner sc) {
        System.out.print("Input three integers:");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int max = -0x7fffffff;
        System.out.print(max);
        max = max(max, a);
        max = max(max, b);
        max = max(max, c);
        int min = 0x7fffffff;
        min = min(min, a);
        min = min(min, b);
        min = min(min, c);
        int sum = a + b + c;
        int avg = sum / 3;
        System.out.printf("The sum is %d\n", sum);
        System.out.printf("The avg is %d\n", avg);
        System.out.printf("The product is %d\n", a * b * c);
        System.out.printf("The smallest is %d and the largest is %d\n", min, max);
    }

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

    private static void ex4(Scanner sc) {
        System.out.print("Input the number of minutes:");
        int mins = sc.nextInt();
        int days = mins / 60 / 24;
        int years = days / 365;
        days %= 365;
        System.out.printf("%d minutes is approximately %d years and %d days.\n", mins, years, days);
    }

    private static void ex5(Scanner sc) {
        System.out.print("Enter a degree in Celsius:");
        int c = sc.nextInt();
        double f = 1.8 * c + 32;
        System.out.printf("%d Celsius is %.1f Fahrenheit\n", c, f);
    }

    private static void ex6(Scanner sc) {
        System.out.print("Enter the radius and length of a cylinder:");
        double r = sc.nextDouble();
        double l = sc.nextDouble();
        System.out.printf("The area is %.4f\n", r * r * Math.PI);
        System.out.printf("he volume is %.1f\n", r * r * Math.PI * l);
    }

    private static void ex7(Scanner sc) {
        System.out.print("Input a number between 0 and 1000:");
        int sum = 0;
        for (int a = sc.nextInt(); a > 0; a /= 10)
            sum += a % 10;
        System.out.printf("The sum of the digits is %d\n", sum);
    }

    private static void ex8() {
        System.out.println("number\tsquare\tcube");
        for (int i = 0; i <= 10; ++i)
            System.out.printf("%d\t%d\t%d\n", i, (int) Math.pow(i, 2), (int) Math.pow(i, 3));
    }

    private static void test(Scanner sc) {
        //ex1(sc);
        //ex2(sc);
        //ex3(sc);
        //ex4(sc);
        //ex7(sc);
        ex6(sc);
    }

    private static void submit(Scanner sc) {
        ex3(sc);
        ex4(sc);
        ex6(sc);
        ex7(sc);
        ex8();
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        test(sc);
        //submit(sc);
        sc.close();
    }
}