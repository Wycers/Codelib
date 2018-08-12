import java.lang.Math;
import java.util.Scanner;

public class exercise1 {
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex1(Scanner sc) {
        print("Enter a integer:");
        int a = sc.nextInt();
        if (a <= 1) {
            print("qwq");
            return;
        }
        print("The smallest factors:");
        for (int f = 2; a != 1; ++f) 
            for (; a % f == 0; a /= f)
                print(String.format("%d ", f));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex1(sc);
        sc.close();
    }
}