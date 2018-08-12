import java.lang.Math;
import java.util.Scanner;

public class exercise5 {
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex5(Scanner sc) {
        for (int i = -28; i <= 28; ++i) {
            for (int j = -28; j <= 28; ++j) {
                if (i + j < -28 || i + j > 28 || i - j < -28 || i - j > 28)
                    print("   ");
                else
                    print(String.format("%-3d", Math.abs(j)));
            }
            print("\n");
        }
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex5(sc);
        sc.close();
    }
}