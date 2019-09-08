import java.lang.Math;
import java.util.Scanner;

public class exercise3 {
    
    
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex3(Scanner sc) {
        int[] a = new int[12];
        int r = c = 0;
        print("Enter a 3*4 matrix:");
        for (int i = 0; i < 12; ++i)
            a[i] = sc.nextInt();
        print("The original matrix is:\n");
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j)
                print(String.format("%d ", a[i]));
            print("\n");
        }

        for (; r * c != 12; ){
            r = sc.nextInt();
            c = sc.nextInt();    
        }
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex3(sc);
        sc.close();
    }
}

        
            