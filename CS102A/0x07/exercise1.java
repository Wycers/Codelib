import java.lang.Math;
import java.util.Scanner;

public class exercise1 {
    
    
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex1(Scanner sc) {
        int x = sc.nextInt();
        if (x < 1 || x > 40) {
            print("再见");
            return;
        }

        int[] a = {12, 24, 8, 22, 15, 4, 8, 6, x};
        int n = a.length;

        int loop, i;
        for(loop = 1; ; ++loop) {
            int temp = (a[n - 1] >>= 1);
            for (i = n - 2; i >= 0; --i) {
                //a[i + 1] += (a[i] >>= 1);

                a[i] = a[i] / 2;
                a[i + 1] += a[i];
            }
            a[0] += temp;

            for (i = 1; i < n; ++i)
                if (a[i] != a[i - 1])
                    break;
            if (i == n)
                break;
        }
        print(String.format("After looping %d times, each kid gets %d chocolates.", loop, a[0]));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex1(sc);
        sc.close();
    }
}

        
            