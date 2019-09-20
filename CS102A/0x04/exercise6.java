import java.lang.Math;
import java.util.Scanner;

public class exercise6 {
    private static void print(String str) {
        System.out.print(str);
    }

    private static void reverse(int[] a) {
        for (int i = 0; i < (a.length / 2); ++i) {
            a[i] = a[i] ^ a[a.length - 1 - i];
            a[a.length - 1 - i] = a[i] ^ a[a.length - 1 - i];
            a[i] = a[i] ^ a[a.length - 1 - i];
        }
    }

    private static void hex(int[] a) {
        for (int i = 31, tmp = 8, sum = 0; i >= 0; --i) {
            sum += tmp * a[i];
            tmp >>= 1;
            if (tmp == 0) {
                if (sum > 10)
                    print(String.format("%c", (char) (87 + sum)));
                else
                    print(String.format("%c", (char) (48 + sum)));

                tmp = 8;
                sum = 0;
            }
        }
        print("\n");
    }

    private static int tonormal(int[] a) {
        int res = 0;
        for (int i = 0, tmp = 1; i < 32; ++i, tmp <<= 1)
            res += a[i] * tmp;
        return res;
    }

    private static void ex6(Scanner sc) {
        print("The input number:");
        int a = sc.nextInt();
        int[] num = new int[32];
        char[] chr = new char[8];

        for (int i = 0; i < 32; ++i, a >>= 1)
            num[i] = a & 1;

        print("The hexadecimal expression of the input number:");
        hex(num);

        reverse(num);
        print(String.format("The reverse number: %d\n", tonormal(num)));

        print("The hexadecimal expression of the reserve number:");
        hex(num);
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex6(sc);
        sc.close();
    }
}