import java.lang.Math;
import java.util.Scanner;

public class exercise6 {
    private static void print(String str) {
        System.out.print(str);
    }
    private static void ex6(Scanner sc, int n) {
        int[] a = new int[20];
        print(String.format("Enter a %d*%d matrix\n", n, n));
        for (int i = 0; i < n * n; ++i)
            a[i] = sc.nextInt();
        print("The original matrix is:\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                print(String.format("%d ", a[i * n + j]));
            print("\n");
        }
        print("The matrix after rotating is:\n");
        for (int i = 0; i < n; ++i) {
            for (int j = (n - 1) * n + i; j >= 0; j -= n)
                print(String.format("%d ", a[j]));
            print("\n");
        }
    }


    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex6(sc, 3);
        ex6(sc, 4);
        sc.close();
    }
}

        
            