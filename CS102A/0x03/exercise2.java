import java.util.Scanner;
import java.lang.Math;

public class exercise2 {
    private static int max(int a, int b) {
        return a > b ? a : b;
    }

    private static int min(int a, int b) {
        return a > b ? b : a;
    }

    private static void ex2(Scanner sc) {
        System.out.print("Input three integers:");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int max = -0x7fffffff;
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

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        //test(sc);
        ex2(sc);
        sc.close();
    }
}