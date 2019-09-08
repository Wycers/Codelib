import java.lang.Math;
import java.util.Scanner;

public class exercise2 {
    
    
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex2(Scanner sc) {
        double[] a = {2.98,2.50,9.98,4.49,6.87};
        double total = 0.0;
        for (int x = sc.nextInt(); x != -1; x = sc.nextInt()) {
            if (x > 5 || x < 1) {
                print("GG");
                return;
            }
            int y = sc.nextInt();
            total += a[x - 1] * y; 
        }
        print(String.format("%.2f\n", total));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex2(sc);
        sc.close();
    }
}

        
            