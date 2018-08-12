import java.util.Scanner;
import java.lang.Math;

public class exercise8 {
    private static void ex8() {
        System.out.println("number  square  cube");
        for (int i = 0; i <= 10; ++i)
            System.out.printf("%-8d%-8d%-8d\n", i, (int) Math.pow(i, 2), (int) Math.pow(i, 3));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex8();
        sc.close();
    }
}