import java.lang.Math;
import java.util.Scanner;

public class exercise7 {
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex7(Scanner sc) {
        int[] a = new int[10];
        for (int i = 0; i < 10; ++i)
            a[i] = sc.nextInt();
        
        for (int i = 0; i < 9; ++i)
            for (int j = i + 1; j < 10; ++j)
                print(String.format("%d combines %d is %d\n", a[i], a[j], a[i] + a[j]));

        print("In fact I don't know what \"combinations\" means");
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex7(sc);
        sc.close();
    }
}

        
            