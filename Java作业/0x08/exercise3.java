import java.lang.Math;
import java.util.Scanner;

public class exercise3 {
    
    
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex3(Scanner sc) {
        int[] a = new int[101];
        for (int i = 1; i < 100; ++i)
            a[i] = 0;
        for(int x = sc.nextInt(); x != 0; x = sc.nextInt()) 
            if (1 <= x && x <= 100)
                ++a[x];
            else
                print("Input a valid number please.");
        
        for(int i = 1; i <= 100; ++i)
            if (a[i] != 0)
                print(String.format("%d occurs %d times\n", i, a[i]));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex3(sc);
        sc.close();
    }
}

        
            