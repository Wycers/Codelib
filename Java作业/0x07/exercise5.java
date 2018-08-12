import java.lang.Math;
import java.util.Scanner;

public class exercise5 {

    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex5(Scanner sc) {
        for (int i = 1; i <= 110; ++i) {
            String str = "";
            if (i % 3 == 0)
                str += "Coza";
            if (i % 5 == 0)
                str += "Loza";
            if (i % 7 == 0)
                str += "Woza";
            print((str == "" ? String.format("%d", i) : str) + " ");
        }
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex5(sc);
        sc.close();
    }
}
