import java.lang.Math;
import java.util.Scanner;

public class exercise4 {
    private static void print(String str) {
        System.out.print(str);
    }

    public static int getRandom(int... numbers) {
        int[] a = new int[55];
        for (int i = 1; i <= 54; ++i)
            a[i] = 0;
        for (int i = 0; i < numbers.length; ++i) 
            a[numbers[i]] = 1;
        
        int cnt = -1;
        for (int i = 1; i < 54; ++i) 
            if (a[i] == 0)
                a[++cnt] = i;
        return a[(int)Math.floor(Math.random() * (cnt + 1))];
    }    

    private static void ex4(Scanner sc) {
        int[] a = new int[55];
        int cnt = -1;
        for(int i = sc.nextInt(), x; i != 0; --i) {
            a[i] = sc.nextInt();
            if (!(1 <= a[i] && a[i] <= 54)) {
                a[i] = 0;
                print(String.format("Number %d is invalid and ignored.\n", a[i]));        
            }
        } 
        print(String.format("Random number: %d \n", getRandom(a)));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex4(sc);
        sc.close();
    }
}

        
            