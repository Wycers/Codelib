import java.lang.Math;
import java.util.Scanner;

public class exercise5 {
    private static void print(String str) {
        System.out.print(str);
    }

    public static int[] eliminateDuplicates(int[] list) {    
        int[] a = new int[10];
        int cnt = -1;
        for (int i = 0; i < list.length; ++i) {
            Boolean flag = false;
            for (int j = 0; j < cnt + 1; ++j)
                if (a[j] == list[i])
                    flag = true;
            if (flag)
                continue;
            a[++cnt] = list[i];
        }
        return a;
    }    

    private static void ex5(Scanner sc) {
        int[] a = new int[10];
        for (int i = 0; i < 10; ++i)
            a[i] = sc.nextInt();
            
        a = eliminateDuplicates(a);
        print("The distinct numbers are:");
        for (int i = 0; i < a.length; ++i)
            if (a[i] != 0)
                print(String.format("%d ", a[i]));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex5(sc);
        sc.close();
    }
}

        
            