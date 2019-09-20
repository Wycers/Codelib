import java.lang.Math;
import java.util.Scanner;

public class exercise5 {
    private static void print(String str) {
        System.out.print(str);
    }
    private static int[][] a = new int[100][100];
    private static int[][] f = new int[100][100];
    private static int[][] route = new int[100][100];
    public static int[] temp = new int[100];
    public static int cnt = -1, ans = 0x3f3f3f3f, n;
    private static void work(int x, int y, int res) {
        if (x == n) {
            if (res < ans) {
                cnt = -1;
                ans = res; 
            }
            if (res == ans) {
                ++cnt;
                for (int i = 0; i < n; ++i)
                    route[cnt][i] = temp[i];
            }
            return;
        }
        if (res > f[x][y])
            return;
        f[x][y] = res;
        temp[x] = a[x][y];
        work(x + 1, y + 1, res + a[x + 1][y + 1]);
        if (x + 1 != n)
            work(x + 1, y, res + a[x + 1][y]);
    }  

    private static void ex5(Scanner sc) {
        n = sc.nextInt();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= i; ++j)
                a[i][j] = sc.nextInt();
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                f[i][j] = 0x3f3f3f3f;

        work(0, 0, a[0][0]);
        for (int i = 0; i <= cnt; ++i) {
            print(String.format("Route #%d: [", i + 1));
            for (int j = 0; j < n - 1; ++j) 
                print(String.format("%d, ", route[i][j]));
            print(String.format("%d]", route[i][n - 1]));
            print("\n");
        }
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        a[1][1] = 1;
        ex5(sc);
        sc.close();
    }
}

        
            