import java.lang.Math;
import java.util.Scanner;

public class exercise2 {
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex2(Scanner sc) {
        print("Enter five numbers:");
        int sum = 0, sqrSum = 0;
        for (int i = 0; i < 5; ++i) {
            int x = sc.nextInt();
            sum += x;
            sqrSum += x * x;
        }
        print(String.format("The mean is %.1f\n", (double)sum / 5));

        double deviation = Math.pow(((double)sqrSum - (double)sum * sum / 5) / 4, 0.5);
        print(String.format("The standard deviation is %.5f", deviation));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex2(sc);
        sc.close();
    }
}