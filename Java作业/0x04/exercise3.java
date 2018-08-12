import java.lang.Math;
import java.util.Scanner;

import sun.security.util.Length;

public class exercise3 {
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex3(Scanner sc) {
        print("Enter a string:");
        String str = sc.nextLine();
        int cnt = 0;
        for (int i = 0; i < str.length(); ++i)
            if ('0' <= str.charAt(i) && str.charAt(i) <= '9')
                ++cnt;
        print(String.format("The number of digits in the string is %d\n", cnt));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex3(sc);
        sc.close();
    }
}