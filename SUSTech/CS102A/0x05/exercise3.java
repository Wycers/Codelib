import java.lang.Math;
import java.util.Scanner;

public class exercise3 {
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex3(Scanner sc) {
        print("Enter numbers:");
        int max = -0x7fffffff, cnt = -1;
        for (int a = sc.nextInt(); a != 0; a = sc.nextInt()) {
            if (a > max) {
                max = a;
                cnt = 0;
            }
            if (a == max) 
                ++cnt;
        }
        if (cnt == -1) {
            print("Input a nonzero integer please");
            return;
        }
        print(String.format("The lagrgest number is %d\n", max));
        print(String.format("The occurrence count of the largest number is %d\n", cnt));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex3(sc);
        sc.close();
    }
}