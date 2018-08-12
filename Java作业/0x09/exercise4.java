import java.lang.Math;
import java.util.Scanner;

public class exercise4 {
    private static void print(String str) {
        System.out.print(str);
    }

    public static int[][] smoothen(int[][] a) {
        int[][] res = new int[3][3];
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) {
                int sum = 0, cnt = 0;
                for (int dx = -1; dx <= 1; ++dx)
                    for (int dy = -1; dy <= 1; ++dy) {
                        int x = i + dx, y = j + dy;
                        if (x < 0 || x >= 3 || y < 0 || y >= 3)
                            continue;
                        ++cnt;
                        sum += a[x][y];
                    }
                res[i][j] = (int)Math.floor((double)sum / cnt);
            }
        return res;
    }    

    private static void ex4(Scanner sc) {
        int[][] a = new int[3][3];
        print("Please enter a 3 by 3 matrix:");
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                a[i][j] = sc.nextInt();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                print(String.format("%d ", a[i][j]));
            print("\n");
        }
        print("The smooth image is:\n");
        int[][] res = smoothen(a);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                print(String.format("%d ", res[i][j]));
            print("\n");
        }
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex4(sc);
        sc.close();
    }
}

        
            